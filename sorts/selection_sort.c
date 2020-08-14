#include <stdio.h>

unsigned long long selectionSort(int A[], int size) {
  // counts how many swaps were done 
    int i, j;
    unsigned long long ctr = 0;
    
    for (i = 0; i < size - 1; i++) {
        int min = A[i];
        for (j = i + 1; j < size; j++) {
            if (A[j] < min) {
                min = A[j];
                swap(&A[i], &A[j]);
                ctr++;
            }
        }
    }
    return ctr;
}