#include "SimpleStringTest.h"

void SimpleStringTest::SetUp()
{
	this->simpleString.Append('a');
	this->simpleString.Append('b');
}

void SimpleStringTest::TearDown()
{
	this->simpleString.Dispose();
}
