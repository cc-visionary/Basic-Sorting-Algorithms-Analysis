#define CPU_TIME  (1)
#define MAX_N 10         // N
#define ITER_PER_SIZE 25 // M
#define N_METHODS 6
#define BASE 1024

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/types.h> // for folder creation for output
#include <sys/stat.h>  // for folder creation for output
#include <unistd.h>    // for folder creation for output

#include "utilities.c"
#include "generate_data.c"
#include "sorts/bubble_sort.c"
#include "sorts/insertion_sort.c"
#include "sorts/selection_sort.c"
#include "sorts/merge_sort.c"
#include "sorts/radix_sort.c"
#include "sorts/quick_sort.c"

int main () {
    /* Use current time as seed for random generator  */
    srand((long) time(NULL));
    
    struct stat st = {0};

    if (stat("./results", &st) == -1) {
        mkdir("results", 0700);
    }
    
    int n, m, arr_size = BASE;
    char labels[N_METHODS][20] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort", "Radix Sort"};
    double total_time[N_METHODS], average_times[N_METHODS][MAX_N];
    long double total_counter[N_METHODS], average_counters[N_METHODS][MAX_N];

    for(n = 1; n <= MAX_N; n++) {
        for(m = 0; m < N_METHODS; m++) {
            total_time[m] = 0;
            total_counter[m] = 0;
        }

        for(m = 0; m < ITER_PER_SIZE; m++) {
            double elapsed[N_METHODS];
            int seconds, nanoseconds;
            unsigned long long ctr[N_METHODS] = {0, 0, 0, 0, 0, 0};
            int index;
            // A is the main array where random values will be assigned
            // the others array is to keep the values they'll sort to be consistent
            int A[arr_size], temp_arr[arr_size];
            // for variables measuring time
            struct timespec begin, end; 

            // calls GenerateData to generate random data from 1-50000 
            GenerateData(A, arr_size);

            // gets the size of the array A again (just a recheck)
            arr_size = sizeof(A)/sizeof(A[0]);

            if(m == 0) printf("\nSize: %d\n", arr_size);
            printf("Iteration %d:\n", m + 1);

            // <----------------- Measure Bubble Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);

            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[0] = bubbleSort(temp_arr, arr_size);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[0] = seconds + nanoseconds*1e-9;

            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);
            
            // <----------------- Measure Insertion Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);

            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[1] = insertionSort(temp_arr, arr_size);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[1] = seconds + nanoseconds*1e-9;

            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);
            
            // <----------------- Measure Selection Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);

            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[2] = selectionSort(temp_arr, arr_size);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[2] = seconds + nanoseconds*1e-9;

            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);

            // <----------------- Measure Merge Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);
        
            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[3] = mergeSort(temp_arr, 0, arr_size-1, 1);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[3] = seconds + nanoseconds*1e-9;

            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);

            // <----------------- Measure Quick Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);

            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[4] = quickSort(temp_arr, 0, arr_size - 1, 1);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[4] = seconds + nanoseconds*1e-9;
            
            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);

            // <----------------- Measure Radix Sort ----------------->
            // copy values from A to each array for each sorting method
            copyValues(temp_arr, A, arr_size);

            // printf("Unsorted: ");
            // printArray(temp_arr, arr_size);

            // Start measuring time
            clock_gettime(CLOCK_REALTIME, &begin);
            ctr[5] = radixSort(temp_arr, arr_size);
            // Stop measuring time and calculate the elapsed time
            clock_gettime(CLOCK_REALTIME, &end);
            
            seconds = end.tv_sec - begin.tv_sec;
            nanoseconds = end.tv_nsec - begin.tv_nsec;
            elapsed[5] = seconds + nanoseconds*1e-9;

            // printf("Sorted: ");
            // printArray(temp_arr, arr_size);
            
            for(index = 0; index < N_METHODS; index++) {
                total_time[index] += elapsed[index] * 1000;
                total_counter[index] += ctr[index];
                printf("%s | Time Measured (ms): %lf | Counter: %llu\n", labels[index], elapsed[index] * 1000, ctr[index]);
            }
            printf("\n");
        }
        
        for(m = 0; m < N_METHODS; m++) {
            FILE *fp; // outputs the results to a file in "results" folder
            char title[30] = "./results/";
            strcat(title, labels[m]);
            strcat(title, ".txt");
            fp = fopen(title, "a");
            average_times[m][n - 1] = total_time[m] / ITER_PER_SIZE;
            average_counters[m][n - 1] = total_counter[m] / ITER_PER_SIZE;
            fprintf(fp, "%d | Average Time Measured (ms): %lf | Average Counter: %.2LF\n", arr_size, average_times[m][n - 1], average_counters[m][n - 1]);
            printf("%s | Average Time Measured (ms): %lf | Average Counter: %.2LF\n", labels[m], average_times[m][n - 1], average_counters[m][n - 1]);
            fclose(fp);
        }
        arr_size *= 2;
    }

    printf("\nSummary:\n");
    for(n = 0; n < N_METHODS; n++) {
        arr_size = BASE;
        printf("<---- %s ---->\n", labels[n]);
        for(m = 1; m <= MAX_N; m++) {
            printf("Size: %d | Average Time (ms): %lf | Average Counter: %LF\n", arr_size, average_times[n][m - 1], average_counters[n][m - 1]);
            arr_size *= 2;
        }

        printf("<---- %s ---->\n", labels[n]);
    }
      

    return 0;
}