#pragma once
#include <vector>

/*
Highly divisible triangular number

The sequence of triangle numbers is generated by adding the natural numbers. 
So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

1: 1
3: 1,3
6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

Formula for Triangle Numbers: n(n-1)/2
*/
class Euler11
{
public:
	int get_solution();
private:
	const int DIVISORS_GOAL = 500;
	std::vector<int> get_factors(int n) const;
	int get_factors_size(int n) const;
	int get_triangle_number(int n);
	bool is_answer(int n) const { return n < DIVISORS_GOAL; }
};

