/* 
 * C program for bubble Sort by GeeksforGeeks 
 * source: https://www.geeksforgeeks.org/bubble-sort/
 */
#include <stdio.h> 
// A function to implement bubble sort 
unsigned long long bubbleSort(int arr[], int n) { 
   int i, j;
   unsigned long long ctr=0; 
   for (i = 0; i < n-1; i++){       
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              ctr++; // number of swaps
              swap(&arr[j], &arr[j+1]); 
           }
       }
   }
   return ctr;
} 
