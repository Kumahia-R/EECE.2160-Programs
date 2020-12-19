/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * String function definitions to be completed
 */

#include <string.h>

void insertSubString(char* dest, char* sub, unsigned pos) {

    /** YOU DON'T NEED TO USE THESE VARIABLES--REPLACE THEM IF YOU WANT-- **
     **   BUT I FOUND THEM TO BE USEFUL IN MY SOLUTION                    **/
    char tmp[100];			// Temporary array to hold longer string
    unsigned i, j;			// Loop/array indexes
    int copied = 0;
    for (i = 0; i < 100; i++) {
        if (i == pos && copied == 0) {
            copied = 1;
            for (j = 0; j < strlen(sub); j++) {
                tmp[i + j] = sub[j];
            }
        }
        else if (copied == 0) {
            tmp[i] = dest[i];
        }
        else if (i + strlen(sub) < 100) {
            tmp[i + strlen(sub)-1] = dest[i-1];
        }
    }
    strcpy(dest, tmp);
    /**** COMPLETE REMAINDER OF FUNCTION ****/

}