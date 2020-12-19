/*
 * EECE.2160: ECE Application Programming
 * Exam 3 Problems
 *
 * Space to complete required functions
 */

#include <stdio.h>

 /*
    Given a single character "command" and three values of type
    double, calculate and return a given statistic based on
    the three numeric inputs:
      - 'A' or 'a':				   average v1, v2, and v3
      - 'M' or 'm':				      median (middle value) of v1, v2, and v3
      - 'H' or 'h':                highest (most positive) of v1, v2, and v3
      - 'L' or 'l' (lowercase L):  lowest (least positive) of v1, v2, and v3
      - Any other command:		   print "Invalid command " followed by that character, return 0
 */
double getStats(char cmd, double v1, double v2, double v3) {
    // DECLARE ANY VARIABLES YOU WANT HERE
    int medFound = 0;
    double vArray[3] = { v1, v2, v3 };
    double median = v1;
    double high = v1;
    double low = v1;

    // Use cmd input to determine what value to calculate and return
    switch (cmd) {
    // Average
    case 'A':
    case 'a':
        return (v1 + v2 + v3) / 3;
        break;
    // Median
    case 'M':
    case 'm':
        if ((v1 < v2) && (v1 > v3)) {
            median = v1;
        }
        else if ((v2 < v1) && (v2 > v3)) {
            median = v2;
        }
        else if ((v3 < v1) && (v3 > v2)) {
            median = v3;
        }
        return median;
        break;
    // Highest (most positive)
    case 'H':
    case 'h':
        for (int i = 0; i < 3; i++) {
            if (high < vArray[i]) {
                high = vArray[i];
            }
        }
        return high;
        break;
    // Lowest (least positive)
    case 'L':
    case 'l':
        for (int i = 0; i < 3; i++) {
            if (low > vArray[i]) {
                low = vArray[i];
            }
        }
        return low;
        break;
    default:
        printf("Invalid command %c", cmd);
        return 0;
    }
}

/* Given day/month, print # days between given date and day of last
   in-person class (March 6) as well as start of remote learning (March 18) */
void countDays(unsigned month, unsigned day) {
    unsigned nDays[12] =                // # of days in each month
    { 31, 29, 31, 30,               // Remember, arrays are zero-indexed,
      31, 30, 31, 31,               //   so nDays[0] = # days in January,
      30, 31, 30, 31 };             //   nDays[1] = # days in February, etc.

    unsigned totDays = 0;                   // Number of days since March 6
    int i;                              // Loop index

    // DECLARE ANY ADDITIONAL VARIABLES YOU WANT HERE
    int remoteStart = 0;
    int j;
    // Start with error cases--invalid month, or invalid day within month
    if (month > 12 || month < 0) {
        printf("Invalid month %d", month);
    }
    // Then, check if user provided valid month/day before spring break
    else if (day > nDays[month - 1] || day < 0) {
        printf("Invalid day %d in month %d", day, month);
    }
    // If not, check if date was during spring break--March 7 through 17
    else {
        if (month <= 3 && day < 7) {
            printf("University open");
        }
        else if (month == 3 && (day > 6 && day < 18)) {
            printf("Spring break");
        }
        // Otherwise, calculate days since last class & # days remote learning
        
        // If month is March (3), count days since March 6
        else {
            for (i = 2; i < month; i++) {
                if (i == 2) {
                    for (j = 6; j < nDays[i]; j++) {
                        totDays++;
                    }
                    for (j = 17; j < nDays[i]; j++) {
                        remoteStart++;
                    }
                }
                else if (i == month - 1) {
                    for (j = 0; j < day; j++) {
                        totDays++;
                        remoteStart++;
                    }
                }
                else {
                   for (j = 0; j < nDays[i]; j++) {
                        totDays++;
                        remoteStart++;
                   }
                }
            }
            printf("Days since last class: %u\n", totDays);
            printf("Days of remote learning: %d", remoteStart);
        }
        // Otherwise, use nDays[] array to help you count days in months
        //   that have already finished (but only count 25 days in March, not 31)

        // Once days are calculated, print required two lines of output
    }
}

/* Given a double as an amount of change to return, figure out the
    minimum number of coins possible to make change for that amount
    and assign the appropriate number to the locations represented by
    quarters, dimes, nickels, and pennies */
void makeChange(double amount, unsigned* quarters, unsigned* dimes,
    unsigned* nickels, unsigned* pennies)
{
    int i;
    int numQuarts = 0, numDimes = 0, numNicks = 0, numPenns = 0;
    int amountCents = (int)(amount * 100);
    for (i = 0; i + 25 <= amountCents; i+= 25) {
        numQuarts += 1;
    }
    amountCents -= i;
    for (i = 0; i + 10 <= amountCents; i += 10) {
        numDimes += 1;
    }
    amountCents -= i;
    for (i = 0; i + 5 <= amountCents; i += 5) {
        numNicks += 1;
    }
    amountCents -= i;
    for (i = 0; i + 1 <= amountCents; i += 1) {
        numPenns += 1;
    }
    amountCents -= i;
    *quarters = numQuarts;
    *dimes = numDimes;
    *nickels = numNicks;
    *pennies = numPenns;
    // See spec for description of this problem
}