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

TEST(UtilOddTest, zeroTest)
{
	EXPECT_FALSE(Util::IsOdd(0));
}

TEST(UtilOddTest, normalTest)
{
	EXPECT_TRUE(Util::IsOdd(1));
	EXPECT_FALSE(Util::IsOdd(2));
}

TEST(UtilStringTest, firstTest)
{
	string firstStr = "Hello";
	string secondStr = "Google";
	EXPECT_STREQ("HelloGoogle", Util::MergeStr(firstStr,secondStr).c_str());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}