#include "SimpleString.h"

SimpleString::SimpleString() : data()
{
	this->data.resize(0);
}

void SimpleString::Append(const char val)
{
	this->data.push_back(val);
}

size_t SimpleString::Length() const
{
	return this->data.size();
}

void SimpleString::Dispose()
{
	this->data.clear();
}
