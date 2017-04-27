#include "Euler23.h"
#include <algorithm>

int Euler23::get_solution()
{
	constexpr int smallest_abundant_n {12};
	constexpr int last_non_abundant_n {28123};

	int running_sum = 0;

	for (int i = smallest_abundant_n; i <= last_non_abundant_n; ++i)
	{
		if (is_number_abundant(i))
			m_abundants.push_back(i);
	}

	int abundants_sz = m_abundants.size();

	for (int i = 0; i < abundants_sz - 1; ++i)
	{
		for (int j = i; j < abundants_sz; ++j)
			m_abundants_sums.push_back(m_abundants.at(i) + m_abundants.at(j));
	}

	sort(m_abundants_sums.begin(), m_abundants_sums.end());
	//m_abundants_sums.erase(unique(m_abundants_sums.begin(), m_abundants_sums.end()), m_abundants_sums.end());

	for (int i = 1; i < last_non_abundant_n; ++i)
	{
		if (!binary_search(m_abundants_sums.begin(), m_abundants_sums.end(), i))
			running_sum += i;
	}

	return running_sum;
}

bool Euler23::is_number_abundant(int number) const
{
	return get_sum_of_divisors(number) > number;
}

int Euler23::get_sum_of_divisors(int number) const
{
	int sum {0};
	int max {number / 2};

	for (int i = 1; i <= max; ++i)
	{
		if (number % i == 0)
			sum += i;
	}
	return sum;
}
