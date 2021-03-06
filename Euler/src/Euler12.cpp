#include "Euler12.h"
#include <algorithm>

int Euler12::get_solution()
{
	int triangle { 28 };
	int divisors { 6 };
	int n { 9 };

	while (is_answer(divisors)) {
		triangle = get_triangle_number(n);
		int factors = get_factors_size(triangle);

		divisors = std::max(divisors, factors);
		++n;
	}

	return triangle;
}

int Euler12::get_triangle_number(int n)
{
	return n * (n - 1) / 2;
}


std::vector<int> Euler12::get_factors(int n) const
{
	std::vector<int> list;

	if (n < 0)
	{
		return list;
	}

	list.push_back(1);
	int sqrt_n { static_cast<int>(sqrt(n)) };

	for (int i = 1; i <= sqrt_n; i++) 
	{
		if (n % i == 0) 
		{
			list.push_back(i);
		}
	}

	return list;
}

int Euler12::get_factors_size(int n) const
{
	int factors { 0 };
	long sqrt_n { static_cast<int>(sqrt(n)) };

	for (int i = 1; i <= sqrt_n; i++) 
	{
		if (n % i == 0) 
		{
			factors += 2;
		}
	}

	return factors;
}
