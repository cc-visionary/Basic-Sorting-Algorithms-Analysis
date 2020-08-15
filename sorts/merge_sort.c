/* 
 * C program for Merge Sort by GeeksforGeeks 
 * source: https://www.geeksforgeeks.org/merge-sort/
 *  
 * Modified by: Christopher Lim
 */

#include <stdio.h>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
int merge(int arr[], int l, int m, int r) { 
    int i, j, k, ctr = 0; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    ctr += n1; // count loops from 0 to n1
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j];
    ctr += n2; // count loops from 0 to n2
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 

    ctr += i + j; // adds the length of the left and right array
    return ctr;
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r, int ctr) { 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        // while counting the number of time mergeSort has been called
        ctr = mergeSort(arr, l, m, ctr + 1) + mergeSort(arr, m + 1, r, ctr + 1); 
  
        merge(arr, l, m, r);
        ctr++; // + 1 for the merge
    }
    return ctr;
} 