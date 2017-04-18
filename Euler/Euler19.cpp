#include "Euler19.h"
#include "../../code_snippets/std_lib_facilities.h"

/*
Counting Sundays
Problem 19

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

int Euler19::getSolution() {
	Day currentDay = Day::MON;		// Day 0 = 1900 Monday
	int firstSundays = 0;			// the sum of first sundays

	for (int year = START_YEAR; year <= END_YEAR; ++year) {

		for (int month = 0; month < 12; ++month) {

			Month currentMonth = getMonth(month);
			int daysInMonth = Euler19::daysInMonth(currentMonth);

			if (Euler19::isLeapYear(year) && currentMonth == Month::FEB) {
				++daysInMonth;
			}
			
			for (int day = 0; day < daysInMonth; ++day) {

				// first sunday
				if (day == 0 && currentDay == Day::SUN && year > START_YEAR) {
					++firstSundays;
				}

				currentDay = Euler19::tomorrow(currentDay);
			}
		}
	}

	return firstSundays;
}

int Euler19::daysInMonth(const Month& month) {
	switch (month) {
	case Month::FEB:
		return 28;
	case Month::SEPT:
	case Month::APR:
	case Month::JUNE:
	case Month::NOV:
		return 30;
	default:
		return 31;
	}
}

bool Euler19::isLeapYear(int year) {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

Month Euler19::getMonth(int month) {
	if (month < int(Month::JAN) || int(Month::DEC) < month) error("Bad month");
	return Month(month);
}

Day Euler19::tomorrow(const Day& day) {
	return day == Day::SAT ? Day::SUN : Day(int(day) + 1);
}

