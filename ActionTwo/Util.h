#pragma once
#include <gtest/gtest-death-test.h>

class Util
{
public:
	static int AddInteger(int a, int b);
	static bool IsOdd(int value);
	static std::string MergeStr(const std::string& first_str, const std::string& second_str);
};
