#pragma once
#include <vector>

class SimpleString
{
public:
	SimpleString();

	void Append(const char val);

	size_t Length() const;

	void Dispose();

private:
	std::vector<char> data;
};
