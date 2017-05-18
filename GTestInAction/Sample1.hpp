#pragma once

// Returns the factorial of n
inline int Factorial(int n)
{
	auto result = 1;
	for (auto i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
