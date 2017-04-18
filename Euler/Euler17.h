#pragma once
#include <map>

/*
Phrase:
	Thousand
	Hundred "and" Teen
	Hundred "and" Ten "-" One
	Hundred "and" Ten
	Hundred "and" One
	Hundred
	Teen
	Ten "-" One
	Ten
	One
Thousand:
	1000
Hundred:
	100-999
Ten:
	10-99
Teen:
	11-19
One:
	1-9
*/

class Euler17 {
public:
	int getSolution();
private:
	std::string toPhrase(int number);
	std::string toThousand(int number);
	std::string toHundred(int number);
	std::string toTen(int number);
	std::string toTeen(int number);
	std::string toOne(int number);
	int sumOfPhrase(std::string words);

	const std::string HUNDRED = " hundred ";
	const std::string THOUSAND = " thousand ";
	const std::string AND = "and ";
	const std::string HYPHEN = "-";

	const std::map<int, std::string> ones {
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"},
	};

	const std::map<int, std::string> teens {
		{11, "eleven"},
		{12, "twelve"},
		{13, "thirteen"},
		{14, "fourteen"},
		{15, "fifteen"},
		{16, "sixteen"},
		{17, "seventeen"},
		{18, "eighteen"},
		{19, "nineteen"}
	};

	const std::map<int, std::string> tens {
		{1, "ten"},
		{2, "twenty"},
		{3, "thirty"},
		{4, "forty"},
		{5, "fifty"},
		{6, "sixty"},
		{7, "seventy"},
		{8, "eighty"},
		{9, "ninety"}
	};
};

