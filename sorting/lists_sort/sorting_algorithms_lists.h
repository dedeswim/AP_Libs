//
// sorting_algorithms - sorting_algorithms.h
// Created by Edoardo Debenedetti on 19/10/2017.
//
#ifndef INSERTION_SORT_SORTING_ALGORITHMS_H
#define INSERTION_SORT_SORTING_ALGORITHMS_H

#include "linked_lists_sorting.h"

// PROTOS
void insertionSort(LIST **array, int size);

void bubbleSort(LIST **array, int size);

void countingSort(LIST **array, int size);

void selectionSort(LIST **array, int size);

void shellSort(LIST **array, int size);

void mergeSort(LIST **A, int first, int last);

void quickSort(LIST **A, int size);


#endif //INSERTION_SORT_SORTING_ALGORITHMS_H