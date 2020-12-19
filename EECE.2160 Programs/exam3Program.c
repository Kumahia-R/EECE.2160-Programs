/*
 * EECE.2160: ECE Application Programming
 * Exam 3 Problems
 *
 * Program to test your solutions to the
 *   required functions
 */

#include <stdio.h>
#include "exam3_fns.h"

int main() {
	unsigned function;			// Input integer used to select function to test
									  //  1 = getStats(), 2 = countDays(), 3 = makeChange()
	double val;					   // General double-precision value
	unsigned nQ, nD, nN, nP;	// Number of quarters, dimes, nickels, and pennies,
									  //   set by calls to makeChange() function

	printf("Which function? ");
	scanf("%d", &function);

	// Select function to be tested
	switch (function) {

	case 1:			// Testing getStats()
		printf("Average of 2160, 4.6, 2020 = %.2lf\n", getStats('A', 2160, 4.6, 2020));
		printf("Average of 12, 11.59, 0.10 = %.2lf\n\n", getStats('a', 12, 11.59, 0.1));

		printf("Median of 1, -1, 0 = %.0lf\n", getStats('M', 1, -1, 0));
		printf("Median of 4, 4, 20 = %.0lf\n\n", getStats('m', 4, 4, 20));

		printf("Highest value of 32.2, 48.1, 10.7 = %.1lf\n", getStats('H', 32.2, 48.1, 10.7));
		printf("Highest value of -14.5, -113, -2020 = %.1lf\n\n", getStats('h', -14.5, -113, -2020));

		printf("Lowest value of 32.2, 48.1, 10.7 = %.1lf\n", getStats('L', 32.2, 48.1, 10.7));
		printf("Lowest value of -14.5, -113, -2020 = %.1lf\n\n", getStats('l', -14.5, -113, -2020));

		printf("If command invalid, function prints: ");
		val = getStats('i', 45, 0.127, 3.14);
		printf(" and returns %.0lf\n", val);

		break;

	case 2:			// Testing countDays()
		printf("If countDays(13, 1) called, prints:\n");
		countDays(13, 1);

		printf("\nIf countDays(4, 31) called, prints:\n");
		countDays(4, 31);

		printf("\nIf countDays(2, 6) called, prints:\n");
		countDays(2, 6);

		printf("\nIf countDays(3, 5) called, prints:\n");
		countDays(3, 5);

		printf("\nIf countDays(3, 10) called, prints:\n");
		countDays(3, 10);

		printf("\nIf countDays(3, 31) called, prints:\n");
		countDays(3, 31);

		printf("\nIf countDays(4, 6) called, prints:\n");
		countDays(4, 6);

		printf("\nIf countDays(12, 25) called, prints:\n");
		countDays(12, 25);

		break;

	case 3:			// Testing makeChange()

		makeChange(0.41, &nQ, &nD, &nN, &nP);
		printf("$0.41 = %u quarter, %u dime, %u nickel, %u penny\n", nQ, nD, nN, nP);

		makeChange(0.74, &nQ, &nD, &nN, &nP);
		printf("$0.74 = %u quarters, %u dimes, %u nickels, %u pennies\n", nQ, nD, nN, nP);

		makeChange(1.85, &nQ, &nD, &nN, &nP);
		printf("$1.85 = %u quarters, %u dime, %u nickels, %u pennies\n", nQ, nD, nN, nP);

		makeChange(2.16, &nQ, &nD, &nN, &nP);
		printf("$2.16 = %u quarters, %u dime, %u nickel, %u penny\n", nQ, nD, nN, nP);

		break;

	default:
		printf("Getting to this point shouldn't be possible ... \n");
	}

	return 0;
}