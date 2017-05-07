#include "Euler22.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>

int Euler22::get_total_of_scores() const
{
	std::vector<std::string> names = parse_names(get_names_path());

	sort(names.begin(), names.end());

	int total_score = 0;
	int i = 0;

	for (auto& n: names)
	{
		total_score += score_name(n, i);
		++i;
	}

	return total_score;
}

int Euler22::score_name(std::string name, int alpha_pos) const
{
	int score = 0;

	for (auto& ch : name)
	{
		if (ch >= 'A' && ch <= 'Z')
			score += ch - '@';
	}

	return score * (alpha_pos + 1);
}

/*
 Read names from file
 format: "MARY","JOE",...
 */
std::vector<std::string> Euler22::parse_names(const std::string& file_name) const
{
	std::vector<std::string> names;

	std::ifstream ist(file_name);

	if (!ist)
		std::runtime_error { "Can't open file." };

	std::string name;

	while (!ist.eof())
	{
		getline(ist, name, ',');

		name.erase(remove(name.begin(), name.end(), '"'), name.end());

		names.push_back(name);
	}

	return names;
}
