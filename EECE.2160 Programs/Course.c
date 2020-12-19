/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Course function definitions
 */

#include <stdio.h>
#include "Course.h"

void printCourse(Course* c) {
    /**** COMPLETE THIS FUNCTION ****/
    int notMilitary = 0;
    printf("%s.%u-%u\n%s\n%s ", c->prefix, c->num, c->sec, c->name, c->days);
    if (c->time > 1200) {
        printf("%d:00 PM", (c->time%1200) / 100);
    }
    else if (c->time == 1200) {
        printf("12:00 PM");
    }
    else {
        printf("%d:00 AM", (c->time) / 100);

    }
}
