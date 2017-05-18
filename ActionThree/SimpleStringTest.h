#pragma once
#include <gtest/gtest.h>
#include "SimpleString.h"

class SimpleStringTest: public ::testing::Test
{
protected:
	void SetUp() override;

	void TearDown() override;

protected:
	SimpleString simpleString;
};
