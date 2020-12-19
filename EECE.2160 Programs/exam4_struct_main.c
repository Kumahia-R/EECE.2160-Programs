/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Program to test your solutions to the
 *   required struct functions
 */

#include <stdio.h>

#include "Schedule.h"		// Implicitly includes Course.h

int main() {
	unsigned part;		// Used to determine which function(s) are being tested

	// Remember, Schedule struct contains # of courses and then
	//   an array of Course structures
	// Each Course contains, in order:
	//   prefix, number, section, name, days, time
	Schedule s1 =
	{
		5,
		{ { "EECE", 2010, 202, "Circuit Theory I", "MWF", 1200 },
		  { "EECE", 2070, 804, "Basic EE Laboratory I", "T", 1700 },
		  { "EECE", 2160, 203, "ECE Application Programming", "MWF", 1200 },
		  {	"MATH", 2310, 205, "Calculus III", "MWF", 1400 },
		  { "EECE", 2460, 201, "Intro to Data Communication Networks", "MWF", 900 } }
	};

	Schedule s2 =
	{
		6,
		{ { "EECE", 2160, 202, "ECE Application Programming", "MWF", 1300 },
		  { "EECE", 3110, 805, "Electronics I Lab", "R", 800 },
		  { "EECE", 3620, 202, "Signals & Systems I", "MWF", 1000 },
		  { "EECE", 3640, 201, "Engineering Math", "MWF", 800 },
		  {	"EECE", 3650, 201, "Electronics I", "MWF", 1100 },
		  { "PHIL", 3340, 201, "Engineering Ethics", "MWF", 900 } }
	};

	Schedule s3 =
	{
		6,
		{ { "EECE", 3170, 202, "Microprocessors I", "MWF", 1100 },
		  { "EECE", 3220, 201, "Data Structures", "MWF", 1000 },
		  { "EECE", 3620, 202, "Signals & Systems I", "MWF", 1000 },
		  { "EECE", 3630, 201, "Intro to Probability", "MWF", 1200 },
		  {	"EECE", 3650, 201, "Electronics I", "MWF", 1100 },
		  { "MATH", 2340, 203, "Differential Equations", "MWF", 1200 } }
	};

	printf("Which part? (1 = test printCourse(), 2 = test checkConflicts()) ");
	scanf("%u", &part);

	switch (part) {
	case 1:
		printf("\nTesting printCourse()\n");
		printf("Schedule s1:\n");
		printSchedule(&s1);

		printf("Schedule s2:\n");
		printSchedule(&s2);
		break;

	case 2:
		printf("\nTesting checkConflicts:\n");
		printf("Conflicts in s1:\n");
		if (checkConflicts(&s1) == 0)			// If there are conflicts, function
			printf("No conflicts\n\n");			//  will print them and return 1

		printf("\nConflicts in s2:\n");
		if (checkConflicts(&s2) == 0)
			printf("No conflicts\n");

		printf("\nConflicts in s3:\n");
		if (checkConflicts(&s3) == 0)
			printf("No conflicts\n");
		break;
	default:
		printf("%u is invalid input\n", part);
	}
	

	return 0;
}