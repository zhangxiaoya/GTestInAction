#include <gtest/gtest.h>
#include "../SampleDynamicLibrary/Headers/DynamicSample.h"

TEST(DynamicTes, test)
{
	EXPECT_EQ(2,GlobalAdd(1, 1));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}