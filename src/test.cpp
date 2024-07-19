#include <gtest/gtest.h>
#include <iostream>

#include "data-structure.hpp"

TEST(IntervalMapTest, ValueBegin) {
	const auto c = 'a';
	const auto imap = interval_map<int, char>(c);

	EXPECT_EQ(imap[0], c);
	EXPECT_EQ(imap[-1], c);
	EXPECT_EQ(imap[10000], c);
}

TEST(IntervalMapTest, ValueSet) {
	const auto c = 'a';
	auto imap = interval_map<int, char>(c);
	
	imap.assign(1, 5, 'b');
	EXPECT_EQ(imap[1], 'b');
	EXPECT_EQ(imap[5], c);
	EXPECT_EQ(imap[-1], c);

	imap.assign(5, 15, 'c');
	EXPECT_EQ(imap[1], 'b');
	EXPECT_EQ(imap[5], 'c');
	EXPECT_EQ(imap[15], c);
	EXPECT_EQ(imap[-1], c);
	EXPECT_EQ(imap[1000], c);

	imap.assign(15, 15, 'd');
	EXPECT_EQ(imap[1], 'b');
	EXPECT_EQ(imap[5], 'c');
	EXPECT_EQ(imap[15], c);
	EXPECT_EQ(imap[-1], c);
}

TEST(IntervalMapTest, OverwriteInterval) {
	const auto c = 'a';
	auto imap = interval_map<int, char>(c);

	imap.assign(1, 5, 'b');
	imap.assign(5, 10, 'c');
	imap.assign(10, 20, 'd');
	imap.assign(3, 17, 'e');

	EXPECT_EQ(imap[0], c);
	EXPECT_EQ(imap[1], 'b');
	EXPECT_EQ(imap[2], 'b');

	for (int i = 3; i < 17; ++i) {
		EXPECT_EQ(imap[i], 'e');
	}
	
	EXPECT_EQ(imap[17], 'd');
	EXPECT_EQ(imap[18], 'd');
	EXPECT_EQ(imap[19], 'd');
	EXPECT_EQ(imap[20], c);
}

TEST(IntervalMapTest, BigNumbers) {
	const auto c = -1;
	auto imap = interval_map<int, int>(c);
	for (auto i = 1; i < 1000000; ++i) {
		imap.assign(i, 2*i, i);
	}

	for (auto i = 1; i < 1000000; ++i) {
		EXPECT_EQ(imap[i], i);
	}

  for (auto i = 1000000; i < (2000000-2); ++i) {
    EXPECT_EQ(imap[i], 999999);
  }

  EXPECT_EQ(imap[2000000], c);
}

TEST(IntervalMapTest, OverlappingIntervals) {
  const auto c = -1;
  auto imap = interval_map<int, int>(c);

  const auto upper = 1000000;
  for (auto i = 0; i < upper / 2; ++i) {
    imap.assign(i, upper-i, i);
  }

  for (auto i = 0; i < upper / 2; ++i) {
    EXPECT_EQ(imap[i], i);
  }

  for (auto i = upper / 2; i < upper; ++i) {
    EXPECT_EQ(imap[i], (upper - i) - 1);
  }
}