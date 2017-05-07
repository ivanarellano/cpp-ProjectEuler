#pragma once
#include <vector>

/*
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

class Euler20 {
public:
	int solution();
private:
	std::vector<int> big_num = { 400 };

	int sum_digits();
	void factorial(int n);
	void multiply(int n);
	void display();
};