//
// insertion_sort - sorting_algorithms.c
// Created by Edoardo Debenedetti on 19/10/2017.

// INCLUDES
#include <stdlib.h>
#include "sorting_algorithms.h"

// STRUCTS

// INTERNAL FUNCTIONS PROTOS
int exchange(int *a, int *b);

void insertionSort2(int *array, int start, int size, int increment);

void mergeArray(int *A, int first, int mid, int last);


// FUNCTIONS

// INSERTION SORT
void insertionSort(int *array, int size) {
    int key;
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
void bubbleSort(int *array, int size) {
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
void countingSort(int *array, int size) {
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
    // C array construction
    int lentgthC = max - min + 1;
    int *C = (int *) malloc(sizeof(int) * lentgthC);
    for (int i = 0; i < lentgthC; ++i) {
        C[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        C[array[i] - min] = C[array[i] - min] + 1; // increases the number of times we encounter the value
    }
    int k = 0;
    for (int i = 0; i < lentgthC; ++i) {
        while (C[i] > 0) {
            array[k++] = i + min;
            --C[i];
        }
    }
}

// SELECTION SORT
void selectionSort(int *array, int size) {
    for (int j = 0; j < size; ++j) {
        int i = j;
        int min = array[i];
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
void shellSort(int *array, int size) {
    for (int i = ARRAY_SIZE / 2; i > 2; i /= 2) {
        for (int j = 0; j < i - 1; ++j) {
            insertionSort2(array, j, size - j, i);
        }
    }
    insertionSort2(array, 0, size, 1);
}

void insertionSort2(int *array, int start, int size, int increment) {
    for (int k = start + increment; k < size; k += increment) {
        for (int j = k; array[j] < array[j - increment] && j >= increment; j -= increment) {
            exchange(&array[j], &array[j - increment]);
        }
    }
}

// MERGE SORT: initial call = mergeSort(A, 0, size(A) - 1)
void mergeSort(int *A, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(A, first, mid);
        mergeSort(A, mid + 1, last);
        mergeArray(A, first, mid, last);
    }
}

void mergeArray(int *A, int first, int mid, int last) {
    int i = first, j = mid + 1;
    int k = 0;
    int *B = (int) malloc(sizeof(int) * (last - first + 1));
    while (i <= mid && j <= last) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= last) {
        B[k++] = A[j++];
    }
    for (int l = first; l <= last; ++l) {
        A[l] = B[l - first];
    }
    free(B);
}

// QUICKSORT: initial call = quickSort(array, 0, size(A) - 1)
void quickSort(int A[], int start, int end) {
    if (start < end) {
        int wall = start;
        int pivot = A[end];
        for (int i = start; i < end; ++i) {
            int curr_el = A[i];
            if (curr_el < pivot) {
                exchange(&A[wall++], &A[i]);
            }
        }
        exchange(&A[wall], &A[end]);
        quickSort(A, start, wall - 1);
        quickSort(A, wall + 1, end);
    }
}


//  EXCHANGE FUNCTION TO EXCHANGE ELEMENTS, IF THE ALGORITHM NEEDS IT
int exchange(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}