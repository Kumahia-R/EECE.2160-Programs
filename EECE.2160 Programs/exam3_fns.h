/*
 * EECE.2160: ECE Application Programming
 * Exam 3 Problems
 *
 * Header file with prototypes of functions you must write
 */

 /*
	 Given a single character "command" and three values of type
	 double, calculate and return a given statistic based on
	 the three numeric inputs:
	   - 'A' or 'a':				 average v1, v2, and v3
	   - 'M' or 'm':				 median (middle value) of v1, v2, and v3
	   - 'H' or 'h':				 highest (most positive) of v1, v2, and v3
	   - 'L' or 'l' (lowercase L): lowest (least positive) of v1, v2, and v3
	   - Any other command:		 print "Invalid command " followed by that character, return 0
 */
double getStats(char cmd, double v1, double v2, double v3);

/* Given day/month, print # days between given date and day of last
   in-person class (March 6) as well as start of remote learning (March 18) */
void countDays(unsigned month, unsigned day);

/* Given a double as an amount of change to return, figure out the
	minimum number of coins possible to make change for that amount
	and assign the appropriate number to the locations represented by
	quarters, dimes, nickels, and pennies */
void makeChange(double amount, unsigned* quarters, unsigned* dimes,
	unsigned* nickels, unsigned* pennies);