/**** REPLACE THIS COMMENT WITH APPROPRIATE HEADER COMMENT ****/

#include "prog6_functions.h"
#include <ctype.h>
#include <stdio.h>
/*** ADD OTHER NECSSARY #INCLUDE DIRECTIVES ***/

/* Reads single line of text and updates histogram
 as well as frequency of most frequent letter */
void ReadText(int histo[], int* max) {
    char junk;
    do {
        scanf("%c", &junk);
    } while (junk != '\n');
    int endRead = 0;
    char newLetter;
    printf("ENTER A LINE OF TEXT:\n\n");
    do {
        scanf("%c", &newLetter);
        if (isalpha(newLetter) != 0) {
            histo[toupper(newLetter) - 65]++;
        }
        for (int i = 0; i < 26; i++) {
            if (histo[i] > *max) {
                *max = histo[i];
            }
        }
        if (newLetter == '\n') {
            endRead = 1;
        }
    } while (newLetter != '\n');
    /*** COMPLETE FUNCTION WITH APPROPRIATE CODE ***/
}

/* Prints histogram, using array holding values
 as well as frequency of most frequent letter,
 which determines height of histogram */
void DrawHist(int histo[], int max) {
    printf("LETTER FREQUENCIES IN TEXT:\n\n");
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (histo[j] >= i) {
                printf("| ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        printf("+-");
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
        int letterASCII = 65;
        printf("%c ", letterASCII + i);
    }
    printf("\n");
    /*** COMPLETE FUNCTION WITH APPROPRIATE CODE ***/
}