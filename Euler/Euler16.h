#pragma once
#include <string>

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

class Euler16
{
public:
	int get_solution();
private:
	int sum_digits(std::string digits);
};

