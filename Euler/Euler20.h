#include <vector>

#pragma once
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