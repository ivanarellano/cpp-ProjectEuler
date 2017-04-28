#include "Euler23.h"

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

	m_abundants_sums.assign(last_non_abundant_n, false);

	int abundants_sz = m_abundants.size();
	for (int i = 0; i < abundants_sz; ++i)
	{
		for (int j = i; j < abundants_sz; ++j)
		{
			int sum_of_abundants = m_abundants.at(i) + m_abundants.at(j);
			if (sum_of_abundants < last_non_abundant_n)
				m_abundants_sums[sum_of_abundants] = true;
			else
				break;
		}
	}

	for (int i = 1; i < last_non_abundant_n; ++i)
	{
		if (!m_abundants_sums[i])
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
