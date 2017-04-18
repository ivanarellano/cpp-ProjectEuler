#pragma once

#include <chrono>

#include "Euler11.h"
#include "Euler16.h"
#include "Euler17.h"
#include "Euler19.h"
#include "Euler20.h"
#include "../../code_snippets/std_lib_facilities.h"

typedef int Solution();

int euler11() {
	Euler11 euler11;
	return euler11.get_solution();
}

int euler16() {
	Euler16 euler16;
	return euler16.get_solution();
}

int euler17() {
	Euler17 euler17;
	return euler17.getSolution();
}

int euler19() {
	Euler19 euler19;
	return euler19.getSolution();
}

int euler20() {
	Euler20 euler20;
	return euler20.solution();
}

void printSolutionDelta(Solution solution) {
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	int output = solution();

	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	cout << "Solution: " << output
		<< endl
		<< "Time difference in ms = "
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< endl;
}
