#pragma once
/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Course structure definition and function prototypes
 */

#ifndef COURSE_H
#define COURSE_H

typedef struct {
	char prefix[5];		// Course prefix (for example, "EECE")
	unsigned num;		   // Course number
	unsigned sec;	      // Course section
	char name[50];		   // Course name
	char days[4];		   // Days on which course meets
	unsigned time;		   // Start time--given using military time
							  //   So, for example, 9 AM = 900,
							  //   12 PM = 1200, 3 PM = 1500, and so on
							  // You'll have to extract hours from this 
							  //   number to print it appropriately
} Course;

void printCourse(Course* c);	// Print contents of Course structure

#endif	// COURSE_H