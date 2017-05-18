#include <iostream>

#include <gtest/gtest.h>
#include "SimpleStringTest.h"

using namespace std;

TEST_F(SimpleStringTest, firstTest)
{
	EXPECT_EQ(2, simpleString.Length());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}