#include "Util.h"

int Util::AddInteger(int a, int b)
{
	return a + b;
}

bool Util::IsOdd(int value)
{
	if (value <= 0)
		return false;
	return value % 2 == 1;
}

std::string Util::MergeStr(const std::string& first_str, const std::string& second_str)
{
	return  first_str + second_str;
}
