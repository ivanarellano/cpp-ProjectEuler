#pragma once

#include "Euler11.h"
#include "Euler16.h"
#include "Euler17.h"
#include "Euler19.h"
#include "Euler20.h"

#include <iostream>
#include <chrono>
#include "Euler22.hpp"
#include "Euler23.h"

typedef int Solution();

inline void keep_window_open()
{
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
}

int euler11()
{
	Euler11 euler11;
	return euler11.get_solution();
}

int euler16()
{
	Euler16 euler16;
	return euler16.get_solution();
}

int euler17()
{
	Euler17 euler17;
	return euler17.getSolution();
}

int euler19()
{
	Euler19 euler19;
	return euler19.getSolution();
}

int euler20()
{
	Euler20 euler20;
	return euler20.solution();
}

int euler22()
{
	Euler22 euler22;
	return euler22.get_total_of_scores();
}

int euler23()
{
	Euler23 euler23;
	return euler23.get_solution();
}

void printSolutionDelta(Solution solution)
{
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	int output = solution();

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Solution: " << output
		<< std::endl
		<< "Time difference in ms = "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
		<< std::endl;
}
