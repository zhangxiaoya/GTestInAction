#include <gtest/gtest.h>
#include "../SampleDynamicLibrary/Headers/DynamicSample.h"
#include "../SampleStaticLibrary/Headers/StaticSample.h"

TEST(DynamicTes, test)
{
	EXPECT_EQ(2,GlobalAdd(1, 1));
}

TEST(StaticLibaray, test)
{
	EXPECT_EQ(1, GlobalMinus(2, 1));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}