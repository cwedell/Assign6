#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

// use number generator from assignment 1 to create a test input file
// make note of memory usage and cpu usage for each algorithm (put in report) (use task manager)

int main(int c, char** argv) {
  Sorting sorter;
  ifstream filein;
  try {
    filein.open(argv[1]);
  } catch(exception& e) {
    cout << "File not found." << endl;
    return 1;
  }
  int linecount = 0;
  int numItems;
  string line;
  double* arr;
  while(getline(filein, line)) {
    try {
      if(linecount == 0) {
        numItems = stoi(line);
        arr = new double[numItems];
      } else {
        if(linecount - 1 < numItems) {
          arr[linecount - 1] = stod(line);
        } else {
          cout << "Error. Wrong number of lines indicated. (Expected fewer lines.)" << endl; // array too small
          return 1;
        }
      }
    } catch(exception& e) {
      cout << "Error. Non-numeric data on line " << (linecount + 1) << endl;
      return 1;
    }
    ++linecount;
  }
  if(linecount <= numItems) {
    cout << "Error. Wrong number of lines indicated. (Expected more lines.)" << endl; // array too large
    return 1;
  }
  double arr2[numItems];
  double arr3[numItems];
  double arr4[numItems];
  double arr5[numItems];
  for(int i = 0; i < numItems; ++i) {
    arr2[i] = arr[i];
    arr3[i] = arr[i];
    arr4[i] = arr[i];
    arr5[i] = arr[i];
  }
  // bubble sort
  auto startTime = chrono::high_resolution_clock::now();
  sorter.bubbleSort(arr, numItems);
  auto endTime = chrono::high_resolution_clock::now();
  auto elapsedTime = endTime - startTime;
  time_t c_startTime = chrono::system_clock::to_time_t(startTime);
  time_t c_endTime = chrono::system_clock::to_time_t(endTime);
  cout << "Bubble sort:" << endl;
  cout << "\tStarted: " << ctime(&c_startTime) << endl;
  cout << "\tEnded: " << ctime(&c_endTime) << endl;
  cout << "\tElapsed: " << chrono::duration_cast<chrono::seconds>(elapsedTime).count() << " seconds" << endl;
  // selection sort
  auto startTime2 = chrono::high_resolution_clock::now();
  sorter.selectionSort(arr2, numItems);
  auto endTime2 = chrono::high_resolution_clock::now();
  auto elapsedTime2 = endTime2 - startTime2;
  time_t c_startTime2 = chrono::system_clock::to_time_t(startTime2);
  time_t c_endTime2 = chrono::system_clock::to_time_t(endTime2);
  cout << "Selection sort:" << endl;
  cout << "\tStarted: " << ctime(&c_startTime2) << endl;
  cout << "\tEnded: " << ctime(&c_endTime2) << endl;
  cout << "\tElapsed: " << chrono::duration_cast<chrono::seconds>(elapsedTime2).count() << " seconds" << endl;
  // insert sort
  auto startTime3 = chrono::high_resolution_clock::now();
  sorter.insertSort(arr3, numItems);
  auto endTime3 = chrono::high_resolution_clock::now();
  auto elapsedTime3 = endTime3 - startTime3;
  time_t c_startTime3 = chrono::system_clock::to_time_t(startTime3);
  time_t c_endTime3 = chrono::system_clock::to_time_t(endTime3);
  cout << "Insert sort:" << endl;
  cout << "\tStarted: " << ctime(&c_startTime3) << endl;
  cout << "\tEnded: " << ctime(&c_endTime3) << endl;
  cout << "\tElapsed: " << chrono::duration_cast<chrono::seconds>(elapsedTime3).count() << " seconds" << endl;
  // quick sort
  auto startTime4 = chrono::high_resolution_clock::now();
  sorter.quickSort(arr4, 0, numItems - 1);
  auto endTime4 = chrono::high_resolution_clock::now();
  auto elapsedTime4 = endTime4 - startTime4;
  time_t c_startTime4 = chrono::system_clock::to_time_t(startTime4);
  time_t c_endTime4 = chrono::system_clock::to_time_t(endTime4);
  cout << "Quick sort:" << endl;
  cout << "\tStarted: " << ctime(&c_startTime4) << endl;
  cout << "\tEnded: " << ctime(&c_endTime4) << endl;
  cout << "\tElapsed: " << chrono::duration_cast<chrono::milliseconds>(elapsedTime4).count() << " milliseconds" << endl;
  // merge sort
  auto startTime5 = chrono::high_resolution_clock::now();
  sorter.mergeSort(arr5, 0, numItems - 1);
  auto endTime5 = chrono::high_resolution_clock::now();
  auto elapsedTime5 = endTime5 - startTime5;
  time_t c_startTime5 = chrono::system_clock::to_time_t(startTime5);
  time_t c_endTime5 = chrono::system_clock::to_time_t(endTime5);
  cout << "Merge sort:" << endl;
  cout << "\tStarted: " << ctime(&c_startTime5) << endl;
  cout << "\tEnded: " << ctime(&c_endTime5) << endl;
  cout << "\tElapsed: " << chrono::duration_cast<chrono::milliseconds>(elapsedTime5).count() << " milliseconds" << endl;
  delete[] arr;
  return 0;
}
