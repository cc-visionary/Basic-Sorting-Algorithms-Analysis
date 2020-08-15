/* 
 * C program for Radix Sort by GeeksforGeeks 
 * source: https://www.geeksforgeeks.org/radix-sort/
 *  
 * Modified by: Christopher Lim
 */

#include <stdio.h>

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
int countSort(int arr[], int n, int exp) { 
    int output[n]; // output array 
    int i, count[10] = {0}, ctr = 0;
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) {
        count[ (arr[i]/exp)%10 ]++;
        ctr++; // counts each of n
    }

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
        ctr++; // counts checking how many count
    }
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
        ctr++; // counts how many loop there were to build output array
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) {
        arr[i] = output[i]; 
        ctr++; // counts each of n
    }

    return ctr;
} 

// The main function to that sorts arr[] of size n using  
// Radix Sort 
int radixSort(int arr[], int n) { 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
    int ctr = 0;
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) {
        ctr += countSort(arr, n, exp); 
        ctr++;
    } 

    return ctr;
} 