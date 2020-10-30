/**
* Game File
* This file contains the functions implementation that are used in the main.
*
* Author: Maria Cireno
* Version: 1.0
*/

/* Functions used */
// Recursive QuickSort function to ordenate array (divide and conquer)
void quickSort (int* arr, int start, int end) {

    int pivot = end; // choosing last number of array as pivot
    int temp; // temp var used to swap numbers
    int j = start; // reading pointer
    int i = start; // reference pointer

    // Loop that puts the pivot in place with smaller numbers on the left and bigger on the right
    while (i < pivot) {
        j = i;
        if (arr[j] > arr[pivot]) {
            temp = arr[j];
            while(j < pivot) {
                arr[j] = arr[j+1];
                j = j + 1;
            }
            arr[j] = temp;
            pivot = pivot - 1;
        } else {
            i = i + 1;
        }
    }

    // calling recursive function to the sub array on the left of pivot
    if(pivot > start){
        quickSort(arr, start, pivot - 1);
    }
    // calling recursive function to the sub array on the right of pivot
    if(pivot < end){
        quickSort(arr, pivot + 1, end);
    }

}

// Function that search for repeated value on array
int isRepNumber (int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if(arr[i] == value) return 1;
    }
    return 0;
}


