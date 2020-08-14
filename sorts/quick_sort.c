#include <stdio.h>

int partition(int A[], int low, int high) {
    int pivot = A[low], i = low, j = high;
    
    while (i < j) {
        while (A[i] <= pivot)
            i++;
        
        while (A[j] > pivot)
            j--;
        
        if (i < j)
            swap(&A[i], &A[j]);
    }
    swap(&A[low], &A[j]);
    return j;
}

int quickSort(int A[], int low, int high, int ctr) {
    if (low < high) {
        int pivotIndex = partition(A, low, high);
        ctr = quickSort(A, low, pivotIndex-1, ctr + 1) + quickSort(A, pivotIndex+1, high, ctr + 1);
    }
    return ctr;
}