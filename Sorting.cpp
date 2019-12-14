#include "Sorting.h"
#include <iostream>

using namespace std;

Sorting::Sorting() {
}

Sorting::~Sorting() {
}

void Sorting::bubbleSort(double arr[], int n) {
  for(int i = 0; i < n; ++i) {
    double temp = 0;
    for(int j = 0; j < n - 1; ++j) {
      if(arr[j] > arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void Sorting::selectionSort(double arr[], int n) {
  int i, j, minIndex;
  double temp;
  for(i = 0; i < n - 1; ++i) {
    minIndex = i;
    for(j = i + 1; j < n; ++j) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void Sorting::insertSort(double arr[], int n) {
  for(int j = 1; j < n; ++j) {
    double temp = arr[j];
    int k = j;
    while(k > 0 && arr[k - 1] >= temp) {
      arr[k] = arr[k - 1];
      --k;
    }
    arr[k] = temp;
  }
}

void Sorting::quickSort(double arr[], int l, int r) {
  if(l < r) {
    int split = quickSplit(arr, l, r);
    quickSort(arr, l, split - 1);
    quickSort(arr, split + 1, r);
  }
}

int Sorting::quickSplit(double arr[], int l, int r) {
  double pivot = arr[r];
  double temp;
  int i = l;
  for(int j = l; j < r; ++j) {
    if(arr[j] <= pivot) { // if value less than pivot, swap them
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      ++i;
    }
  } // iterated through whole array, now swap pivot and ending index value
  temp = pivot;
  arr[r] = arr[i];
  arr[i] = temp;
  return i;
}

void Sorting::mergeSort(double arr[], int l, int r) {
  if(l < r) {
    int split = l + (r - l) / 2;
    mergeSort(arr, l, split);
    mergeSort(arr, split + 1, r);
    mergeSplit(arr, l, r, split);
  }
}

void Sorting::mergeSplit(double arr[], int l, int r, int s) {
  int lidx = l; // index of left side
  int ridx = s + 1; // index of right side
  int i = 0; // index for iterating
  double sortedArr[r - l + 1];
  while(lidx <= s && ridx <= r) { // merge the arrays
    if(arr[lidx] <= arr[ridx]) { // value on left is bigger
      sortedArr[i] = arr[lidx];
      ++lidx;
    } else {
      sortedArr[i] = arr[ridx]; // value on right is bigger
      ++ridx;
    }
    ++i;
  }
  while(lidx <= s) {
    sortedArr[i] = arr[lidx]; // get leftover values from left
    ++i;
    ++lidx;
  }
  while(ridx <= r) {
    sortedArr[i] = arr[ridx]; // get leftover values from right
    ++i;
    ++ridx;
  }
  for(int k = l; k <= r; ++k) { // put the sorted values into the array
    arr[k] = sortedArr[k];
  }
}
