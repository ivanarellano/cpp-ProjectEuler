#include "Euler16.h"
#include <algorithm>
#include <math.h>

int Euler16::get_solution() {
	return sum_digits(std::to_string(pow(2, 1000)));
}

int Euler16::sum_digits(std::string digits) {
	int sum = 0;
	for (auto& n : digits) {
		if (n >= '1' && n <= '9') {
			sum += n - '0';
		}
	}
	return sum;
}
