#include "Euler20.h"
#include <string>
#include <iostream>
#include <stdexcept>

/*
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

int Euler20::solution()
{
	factorial(100);

	display();

	return sum_digits();
}

int Euler20::sum_digits()
{
	int sum = 0;
	for (auto& i : big_num)
		sum += i;

	return sum;
}

void Euler20::factorial(int n)
{
	if (1 > n)
		std::runtime_error("input must be greater than 1");
	
	big_num.clear();
	big_num.push_back(1);

	for (int i = 1; i <= n; ++i)
		multiply(i);
}

void Euler20::multiply(int x)
{
	int carry = 0;
	for (auto& i : big_num)
	{
		int result = i * x + carry;
		i = result % 10;
		carry = result / 10;
	}

	while (carry > 0)
	{
		big_num.push_back(carry % 10);
		carry /= 10;
	}
}

void Euler20::display()
{
	for (std::vector<int>::reverse_iterator p = big_num.rbegin(); p != big_num.rend(); ++p)
		std::cout << *p;

	std::cout << std::endl;
}