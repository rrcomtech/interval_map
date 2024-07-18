#include <gtest/gtest.h>

#include "data-structure.hpp"

TEST(HelloWorldTest, BasicEquals) {
	DataStructure ds = DataStructure();

	const char* out = ds.helloworld();
	EXPECT_EQ(out, "Hello World");
}
