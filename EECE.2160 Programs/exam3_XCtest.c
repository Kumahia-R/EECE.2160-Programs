/*
 * EECE.2160: ECE Application Programming
 * Exam 3 Problems
 *
 * Test program for extra credit function
 */

#include <stdio.h>
#include "exam3_XC.h"

int main() {
	unsigned arr1[9][9] =				// First test array--valid solution
	{ {1, 2, 3, 4, 5, 6, 7, 8, 9},
		{4, 5, 6, 7, 8, 9, 1, 2, 3},
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 1, 2, 3, 4, 5, 6, 7},
		{3, 4, 5, 6, 7, 8, 9, 1, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 1, 2, 3, 4, 5, 6, 7, 8} };

	unsigned arr2[9][9] =				// Second test array--repeats value in row
	{ {1, 2, 3, 4, 5, 6, 7, 8, 9},
		{4, 5, 6, 7, 4, 9, 1, 2, 3},	// Two 4s in second row
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 1, 2, 3, 8, 5, 6, 7},
		{3, 4, 5, 6, 7, 4, 9, 1, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 1, 2, 3, 8, 5, 6, 7, 8} };

	unsigned arr3[9][9] =				// Third test array--repeats values in column
	{ {1, 2, 3, 4, 5, 6, 7, 8, 9},
		{4, 5, 6, 7, 8, 3, 1, 2, 9},	// Two 3s in 6th column; two 9s in last column
		{7, 8, 9, 1, 2, 3, 4, 5, 6},	//  Also repeats values in same 3 x 3 box
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 1, 2, 3, 4, 5, 6, 7},
		{3, 4, 5, 6, 7, 8, 9, 1, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 1, 2, 3, 4, 5, 6, 7, 8} };

	unsigned arr4[9][9] =				// Fourth test array--repeats values in box
	{ {1, 2, 3, 4, 5, 6, 7, 8, 9},	// Two 1s in first 3 x 3 box (other errors, too)
		{4, 1, 6, 7, 8, 9, 5, 2, 3},
		{7, 8, 9, 1, 2, 3, 4, 5, 6},
		{2, 3, 4, 5, 6, 7, 8, 9, 1},
		{5, 6, 7, 8, 9, 1, 2, 3, 4},
		{8, 9, 5, 2, 3, 4, 1, 6, 7},
		{3, 4, 1, 6, 7, 8, 9, 5, 2},
		{6, 7, 8, 9, 1, 2, 3, 4, 5},
		{9, 5, 2, 3, 4, 1, 6, 7, 8} };

	if (isSudokuSoln(arr1))
		printf("arr1 is valid solution\n");
	else
		printf("arr1 is NOT valid solution\n");

	if (isSudokuSoln(arr2))
		printf("arr2 is valid solution\n");
	else
		printf("arr2 is NOT valid solution\n");

	if (isSudokuSoln(arr3))
		printf("arr3 is valid solution\n");
	else
		printf("arr3 is NOT valid solution\n");

	if (isSudokuSoln(arr4))
		printf("arr4 is valid solution\n");
	else
		printf("arr4 is NOT valid solution\n");

	return 0;
}