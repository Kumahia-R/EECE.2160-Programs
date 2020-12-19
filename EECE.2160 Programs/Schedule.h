#pragma once
/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Schedule structure definition and function prototypes
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"

typedef struct {
    unsigned nc;			// Actual number of courses in schedule
    Course courses[6];		// List of courses--maximum of 6
} Schedule;

// Prints courses that conflict and returns 1 if conflicts exist
//   Returns 0 otherwise
unsigned checkConflicts(Schedule* s);

// Print all courses in schedule
void printSchedule(Schedule* s);

#endif		// SCHEDULE_H