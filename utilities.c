/* UTILITY FUNCTIONS */
#include <stdio.h>

/* Function to swap a and b */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to copy the values of array(arr2) to another(arr1) */
void copyValues(int arr1[], int arr2[], int n) {
    int i;
    for(i = 0; i < n; i++) arr1[i] = arr2[i];
}

/* Function to print an array */
void printArray(int A[], int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) 
            mx = arr[i]; 
    }
    return mx; 
} 
