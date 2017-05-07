#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible 
permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically 
or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

class Euler24
{
public:

	void print_solution()
	{
		for (auto i : m_numbers)
			std::cout << i;
		std::cout << std::endl;
	}

	int get_solution()
	{
		for (int i = 1; i < 1000000; ++i)
			std::next_permutation(m_numbers.begin(), m_numbers.end());

		print_solution();

		return 0;
	}
private:
	std::vector<int> m_numbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
};