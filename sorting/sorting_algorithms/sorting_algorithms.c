//
// insertion_sort - sorting_algorithms.c
// Created by Edoardo Debenedetti on 19/10/2017.
//

// INCLUDES
#include <stdlib.h>
#include "sorting_algorithms.h"

// STRUCTS

// INTERNAL FUNCTIONS PROTOS
int exchange(array_type *a, array_type *b);

void insertionSort2(array_type *array, int start, int size, int increment);

void mergeArray(array_type *array, int first, int mid, int last);


// FUNCTIONS

// INSERTION SORT
void insertionSort(array_type *array, int size) {
    array_type key;
    for (int t = 1; t < size; ++t) {
        key = array[t];
        int s = t - 1;
        while (s >= 0 && array[s] > key) {
            array[s + 1] = array[s];
            --s;
        }
        array[s + 1] = key;
    }
}

// BUBBLE SORT
void bubbleSort(array_type *array, int size) {
    int bubbleFlag = 1;
    while (bubbleFlag) {
        bubbleFlag = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                exchange(&array[i], &array[i + 1]);
                bubbleFlag = 1;
            }
        }
    }
}

// COUNTING SORT
void countingSort(int *array, int size) { // works only with integers
    // computing min and max
    int min = array[0];
    int max = array[0];

    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        } else if (array[i] < min) {
            min = array[i];
        }
    }
    // Counting  array construction
    int length = max - min + 1;
    int *C = (int *) malloc(sizeof(int) * length);
    if (!C) exit(EXIT_FAILURE);
    for (int i = 0; i < length; ++i) {
        C[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        C[array[i] - min] = C[array[i] - min] + 1; // increases the number of times we encounter the value
    }
    int k = 0;
    for (int i = 0; i < length; ++i) {
        while (C[i] > 0) {
            array[k++] = i + min;
            --C[i];
        }
    }
}

// SELECTION SORT
void selectionSort(array_type *array, int size) {
    for (int j = 0; j < size; ++j) {
        int i = j;
        array_type min = array[i];
        int minIndex = i;
        for (; i < size; ++i) {
            if (min > array[i]) {
                min = array[i];
                minIndex = i;
            }
        }
        array[minIndex] = array[j];
        array[j] = min;
    }
}

// SHELL SORT
void shellSort(array_type *array, int size) {
    for (int i = ARRAY_SIZE / 2; i > 2; i /= 2) {
        for (int j = 0; j < i - 1; ++j) {
            insertionSort2(array, j, size - j, i);
        }
    }
    insertionSort2(array, 0, size, 1);
}

void insertionSort2(array_type *array, int start, int size, int increment) {
    for (int k = start + increment; k < size; k += increment) {
        for (int j = k; array[j] < array[j - increment] && j >= increment; j -= increment) {
            exchange(&array[j], &array[j - increment]);
        }
    }
}

// MERGE SORT: initial call = mergeSort(A, 0, size(A) - 1)
void mergeSort(array_type *array, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(array, first, mid);
        mergeSort(array, mid + 1, last);
        mergeArray(array, first, mid, last);
    }
}

void mergeArray(array_type *array, int first, int mid, int last) {
    int i = first, j = mid + 1;
    int k = 0;
    array_type *B = (array_type *) malloc(sizeof(array_type) * (last - first + 1));
    if (!B) exit(EXIT_FAILURE);
    while (i <= mid && j <= last) {
        if (array[i] < array[j]) {
            B[k++] = array[i++];
        } else {
            B[k++] = array[j++];
        }
    }
    while (i <= mid) {
        B[k++] = array[i++];
    }
    while (j <= last) {
        B[k++] = array[j++];
    }
    for (int l = first; l <= last; ++l) {
        array[l] = B[l - first];
    }
    free(B);
}

// QUICKSORT: initial call = quickSort(array, size(A))
void quickSort(array_type *array, int size) {
    int end = size - 1;
    if (end > 0) {
        int wall = 0;
        array_type pivot = array[end];
        for (int i = 0; i < end; ++i) {
            array_type curr_el = array[i];
            if (curr_el < pivot) {
                exchange(&array[wall++], &array[i]);
            }
        }
        exchange(&array[wall], &array[end]);
        quickSort(array, wall - 1);
        quickSort(&array[wall + 1], end - wall);
    }
}


//  EXCHANGE FUNCTION TO EXCHANGE ELEMENTS, IF THE ALGORITHM NEEDS IT
int exchange(array_type *a, array_type *b) {
    array_type t = *a;
    *a = *b;
    *b = t;
}