#include <iostream>
#include <gtest/gtest.h>
#include "Util.h"

using namespace std;

TEST(UtilAddIntegerTest, zeroTest)
{
	EXPECT_EQ(0, Util::AddInteger(0, 0));
}

TEST(UtilAddIntegerTest, normalTest)
{
	EXPECT_EQ(2, Util::AddInteger(1, 1));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}