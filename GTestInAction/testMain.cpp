#include "Sample1.hpp"
#include <gtest/gtest.h>

using namespace std;

TEST(FactorialTest, outlierTest)
{
	EXPECT_EQ(1, Factorial(-1));
	EXPECT_EQ(1, Factorial(0));
}

TEST(FactorialTest, normalTest)
{
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}