#include <map>

template<typename K, typename V>
class interval_map {
public:
	V m_valBegin;
	std::map<K,V> m_map;
	
	// constructor associates whole range of K with val
	interval_map(V const& val) : m_valBegin(val) { }

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if (!(keyBegin < keyEnd )) return;
		// An empty map is a simple case. No need for more complex operations.
		if (m_map.empty()) {
			m_map.insert_or_assign(keyBegin, val);
			m_map.insert_or_assign(keyEnd, m_valBegin);
			return;
		}

		// Get the first element that is either above or at keyEnd.
		// That can be on the keyEnd itself. Then nothing to do.
		// If it is above keyEnd, the next lower element is below
		// keyEnd (otherwise it would have been returned). That means
		// we need to set an entry for the next lower element's value
		// on keyEnd.
		auto it = m_map.lower_bound(keyEnd);

		// If keyEnd is the largest key in the map, insert it add the end
		// and overwrite possible other keys.
		if (it == m_map.end()) {
			it--;
			m_map.insert_or_assign(keyEnd, m_valBegin);
		} else if (keyEnd < it->first) {
			m_map.insert_or_assign(keyEnd, (--it)->second);
		}

		// Now iterate down and overwrite all elements that are between
		// keyBegin and keyStart.
		// Here we have two options:
		//	1. Erase all elements between keyBegin and keyEnd.
		//	   This is O(log n) for each erase.
		//	2. Point all elements to the new val. However, access
		//	   via the [] operator is also in O(log n), therefore
		//	   we do not gain an advantage in time complexity.
		//	   The disadvantage is that the size of the container
		//	   grows and future operations will become slower.
		//     From testing: This alternative is way slower.
		//     From task description: Not allowed (would make DS
		//     canonical).
		while (keyBegin < it->first && it != m_map.begin())  {
			it = m_map.erase(it);
			--it;
		}

		// Set the new value in place.
		m_map.insert_or_assign(keyBegin, val);
		return;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
