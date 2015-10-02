#ifndef _SORTS_H_
#define _SORTS_H_

template <class T>
void bubbleSort(T a[], int n);

template <class T>
void insertionSort(T a[], int n);

template <class T>
void selectionSort(T a[], int n);

template <class T>
void quickSort(T a[], int n);

template <class T>
void quickSort3(T a[], int n);

template <class T>
void imergeSort(T a[], int n);

template <class T>
void mergeSort(T a[], int n);

#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "selectionSort.cpp"
#include "quickSort.cpp"
#include "mergeSort.cpp"

#endif
