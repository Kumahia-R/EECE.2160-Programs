/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Schedule function definitions
 */

#include "Schedule.h"
#include <string.h>
#include <stdio.h>

 // Prints courses that conflict and returns 1 if conflicts exist
 //   Returns 0 otherwise
unsigned checkConflicts(Schedule* s) {
    /***** COMPLETE THIS FUNCTION *****/
    int conflicts[6] = { 0 };
    int conflict = 0;
    for (int i = 0; i < s->nc; i++) {
        for (int j = 0; j < s->nc; j++) {
            if (!strcmp(s->courses[j].days, s->courses[i].days) && (s->courses[j].time == s->courses[i].time) && i != j && conflicts[i] == 0) {
                conflict = 1;
                conflicts[i]++;
                conflicts[j]++;
                printf("%s.%u-%u and %s.%u-%u\n", s->courses[i].prefix, s->courses[i].num, s->courses[i].sec, s->courses[j].prefix, s->courses[j].num, s->courses[j].sec);
                if (s->courses[i].time > 1200) {
                    printf("%s %d:00 PM\n", s->courses[i].days, (s->courses[i].time % 1200) / 100);
                }
                else if (s->courses[i].time == 1200) {
                    printf("%s 12:00 PM\n", s->courses[i].days);
                }
                else {
                    printf("%s %d:00 AM\n", s->courses[i].days, (s->courses[i].time) / 100);

                }
            }
        }
    }
    if (conflict == 0) {
        printf("No conflicts\n");
    }
    //return 0;      // Replace this line--it's only here to ensure your code compiles
}

/****** DO NOT MODIFY ANY CODE BELOW THIS LINE--THE PRINTSCHEDULE() FUNCTION IS WRITTEN FOR YOU! *******/
// Print all courses in schedule
void printSchedule(Schedule* s) {
    unsigned i;

    // Prints each individual course, leaving blank line in between
    for (i = 0; i < s->nc; i++) {
        printCourse(&(s->courses[i]));
        printf("\n");
    }
}
