#include "Euler17.h"
#include <map>
#include <cmath>

int Euler17::getSolution() {
	int sum = 0;

	for (int i = 1; i <= 1000; ++i) {
		std::string words = toPhrase(i);
		sum += sumOfPhrase(words);
	}

	return sum;
}

std::string Euler17::toPhrase(int number) {
	std::string thousand = toThousand(number);

	if (!thousand.empty()) {
		return thousand;
	}

	std::string hundredth = toHundred(number);
	if (!hundredth.empty()) {
		std::string teen = toTeen(number % 100);
		if (!teen.empty()) {
			return hundredth + AND + teen;
		}

		std::string ten = toTen(number % 100);
		if (!ten.empty()) {
			std::string one = toOne(number % 10);
			std::string tenth = !one.empty() ? ten + HYPHEN + one : ten;
			return hundredth + AND + tenth;
		}
		
		std::string one = toOne(number % 10);
		if (!one.empty()) {
			return hundredth + AND + one;
		}
		
		return hundredth;
	}

	std::string teen = toTeen(number);
	if (!teen.empty()) {
		return teen;
	}

	std::string ten = toTen(number);
	if (!ten.empty()) {
		std::string one = toOne(number % 10);
		return !one.empty() ? ten + HYPHEN + one : ten;
	}

	return toOne(number);
}

std::string Euler17::toThousand(int number) {
	if (number < 1000 || number > 9999) {
		return "";
	}

	std::map<int, std::string>::const_iterator i = ones.find(number / 1000);

	return i != ones.end() ? i->second + THOUSAND : "";
}

std::string Euler17::toHundred(int number) {
	if (number < 100 || number > 999) {
		return "";
	}

	std::map<int, std::string>::const_iterator i = ones.find(number / 100);

	return i != ones.end() ? i->second + HUNDRED : "";
}

std::string Euler17::toTen(int number) {
	if (number < 10 || number > 99) {
		return "";
	}

	std::map<int, std::string>::const_iterator i = tens.find(number / 10);

	return i != tens.end() ? i->second : "";
}

std::string Euler17::toTeen(int number) {
	if (number < 11 || number > 19) {
		return "";
	}

	std::map<int, std::string>::const_iterator i = teens.find(number);
	
	return i != teens.end() ? i->second : "";
}

std::string Euler17::toOne(int number) {
	if (number < 1 || number > 9) {
		return "";
	}

	std::map<int, std::string>::const_iterator i = ones.find(number);

	return i != ones.end() ? i->second : "";
}

int Euler17::sumOfPhrase(std::string words) {
	int sum = 0;

	for (auto n : words) {
		if (n == ' ' || n == '-') {
			continue;
		}

		sum += 1;
	}

	return sum;
}
