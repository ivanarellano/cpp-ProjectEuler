#pragma once
#include <vector>

enum class Month {
	JAN, FEB, MAR, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC
};

enum class Day {
	SUN, MON, TUES, WED, THURS, FRI, SAT
};

class Euler19 {
public:
	int getSolution();
private:
	const int END_YEAR = 2000;
	const int START_YEAR = 1900;

	int daysInMonth(const Month& month);
	bool isLeapYear(int year);
	Month getMonth(int month);
	Day tomorrow(const Day& day);
};