#include <iostream>

using namespace std;

class Sorting {
public:
  Sorting();
  ~Sorting();

  void bubbleSort(double arr[], int n);
  void selectionSort(double arr[], int n);
  void insertSort(double arr[], int n);
  void quickSort(double arr[], int l, int r);
  int quickSplit(double arr[], int l, int r);
  void mergeSort(double arr[], int l, int r);
  void mergeSplit(double arr[], int l, int r, int s);
};
