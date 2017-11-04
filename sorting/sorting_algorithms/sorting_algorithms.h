//
// insertion_sort - sorting_algorithms.h
// Created by Edoardo Debenedetti on 19/10/2017.
//
#ifndef INSERTION_SORT_SORTING_ALGORITHMS_H
#define INSERTION_SORT_SORTING_ALGORITHMS_H

#define ARRAY_SIZE 5

typedef int array_type;
// PROTOS
void insertionSort(array_type *array, int size);

void bubbleSort(array_type *array, int size);

void countingSort(int *array, int n); // works only with integers

void selectionSort(array_type *array, int size);

void shellSort(array_type *array, int size);

void mergeSort(array_type *array, int first, int last);

void quickSort(array_type *array, int start, int end);


#endif //INSERTION_SORT_SORTING_ALGORITHMS_H