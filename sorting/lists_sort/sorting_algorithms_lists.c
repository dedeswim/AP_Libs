//
// sorting_algorithms - sorting_algorithms.c
// Created by Edoardo Debenedetti on 19/10/2017.
//

// INCLUDES
#include <stdlib.h>
#include "sorting_algorithms_lists.h"

// STRUCTS

// PROTOS FOR INTERNAL USE FUNCTIONS
int exchange(LIST **a, LIST **b);

void insertionSort2(LIST **array, int start, int size, int increment);

void mergeArray(LIST **A, int first, int mid, int last);


// FUNCTIONS
// INSERTION SORT
void insertionSort(LIST **array, int size) {
    LIST *key;
    for (int t = 1; t < size; ++t) {
        key = array[t];
        int s = t - 1;
        while (s >= 0 && array[s]->val > key->val) {
            array[s + 1] = array[s];
            --s;
        }
        array[s + 1] = key;
    }
}

// BUBBLE SORT
void bubbleSort(LIST **array, int size) {
    int bubbleFlag = 1;
    while (bubbleFlag) {
        bubbleFlag = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i]->val > array[i + 1]->val) {
                exchange(&array[i], &array[i + 1]);
                bubbleFlag = 1;
            }
        }
    }
}

// COUNTING SORT
void countingSort(LIST **array, int size) {
    // computing min and max
    int min = array[0]->val;
    int max = array[0]->val;

    for (int i = 0; i < size; ++i) {
        if (array[i]->val > max) {
            max = array[i]->val;
        } else if (array[i]->val < min) {
            min = array[i]->val;
        }
    }
    // C array construction
    int lengthC = max - min + 1;
    int *C = (int *) malloc(sizeof(int) * lengthC);
    if (!C) exit(EXIT_FAILURE);
    for (int i = 0; i < lengthC; ++i) {
        C[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        C[array[i]->val - min] = C[array[i]->val - min] + 1; // increases the number of times we encounter the value
    }
    int k = 0;
    for (int i = 0; i < lengthC; ++i) {
        while (C[i] > 0) {
            array[k++]->val = i + min;
            --C[i];
        }
    }
}

// SELECTION SORT
void selectionSort(LIST **array, int size) {
    for (int j = 0; j < size; ++j) {
        int i = j;
        LIST *min = array[i];
        int minIndex = i;
        for (; i < size; ++i) {
            if (min->val > array[i]->val) {
                min = array[i];
                minIndex = i;
            }
        }
        array[minIndex] = array[j];
        array[j] = min;
    }
}

// SHELL SORT
void shellSort(LIST **array, int size) {
    for (int i = size / 2; i > 2; i /= 2) {
        for (int j = 0; j < i - 1; ++j) {
            insertionSort2(array, j, size - j, i);
        }
    }
    insertionSort2(array, 0, size, 1);
}

void insertionSort2(LIST **array, int start, int size, int increment) {
    for (int k = start + increment; k < size; k += increment) {
        for (int j = k; j >= increment && array[j]->val < array[j - increment]->val; j -= increment) {
            exchange(&array[j], &array[j - increment]);
        }
    }
}

// MERGE SORT: initial call = mergeSort(A, 0, size(A) - 1)
void mergeSort(LIST **A, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(A, first, mid);
        mergeSort(A, mid + 1, last);
        mergeArray(A, first, mid, last);
    }
}

void mergeArray(LIST **A, int first, int mid, int last) {
    int i = first, j = mid + 1;
    int k = 0;
    LIST **B = (LIST **) malloc(sizeof(LIST *) * (last - first + 1));
    if (!B) exit(EXIT_FAILURE);
    while (i <= mid && j <= last) {
        if (A[i]->val < A[j]->val) {
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

// QUICKSORT
void quickSort(LIST **A, int start, int end) { // initial call quickSort(array, 0, size - 1)
    if (start < end) {
        int wall = start;
        LIST *pivot = A[end];
        for (int i = start; i < end; ++i) {
            LIST *curr_el = A[i];
            if (curr_el->val < pivot->val) {
                exchange(&A[wall++], &A[i]);
            }
        }
        exchange(&A[wall], &A[end]);
        quickSort(A, start, wall - 1);
        quickSort(A, wall + 1, end);
    }
}

// EXCHANGE FUNCTION FOR FUNCTIONS WHICH NEED IT
int exchange(LIST **a, LIST **b) {
    LIST *t = *a;
    *a = *b;
    *b = t;
}