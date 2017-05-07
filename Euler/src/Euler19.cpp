#include "Euler19.h"
#include <stdexcept>

int Euler19::getSolution() {
	Day currentDay = Day::MON;		// Day 0 = 1900 Monday
	int firstSundays = 0;			// the sum of first sundays

	for (int year = START_YEAR; year <= END_YEAR; ++year) {

		for (int month = 0; month < 12; ++month) {

			Month currentMonth = getMonth(month);
			int daysInMonth = Euler19::daysInMonth(currentMonth);

			if (isLeapYear(year) && currentMonth == Month::FEB) {
				++daysInMonth;
			}
			
			for (int day = 0; day < daysInMonth; ++day) {

				// first sunday
				if (day == 0 && currentDay == Day::SUN && year > START_YEAR) {
					++firstSundays;
				}

				currentDay = tomorrow(currentDay);
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
	if (month < int(Month::JAN) || int(Month::DEC) < month) throw std::runtime_error("Bad month");
	return Month(month);
}

Day Euler19::tomorrow(const Day& day) {
	return day == Day::SAT ? Day::SUN : Day(int(day) + 1);
}

