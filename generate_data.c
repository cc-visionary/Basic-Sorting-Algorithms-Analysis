/* Reference: https://www.geeksforgeeks.org/generating-random-number-range-c/ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateData(int A[], int n) {
    int i;

    /* Assign n random numbers to A[i] from 1 to 50000 */
    for(i = 0 ; i < n; i++)
      A[i] = rand() % 50000 + 1;
}