#ifndef _RECORD_H_
#define _RECORD_H_

#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Record {
private:
  std::string month, day, hour, minute, second, ip, port, failure;
  std::vector<std::string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  struct tm dateStruct;

  time_t dateTime;

public:
  Record();
  Record(std::string _month, std::string _day, std::string _hour,
         std::string _minute, std::string _second, std::string _ip,
         std::string _port, std::string _failure);

  std::string getAll();

  bool operator==(const Record &);
  bool operator!=(const Record &);
  bool operator>(const Record &);
  bool operator<(const Record &);
  bool operator>=(const Record &);
  bool operator<=(const Record &);
};

// <---------------------------------------------------------->
// <--------------------> Sort Algoritms <-------------------->
// <---------------------------------------------------------->

template <class T> class AlgorithmSort {
private:
  void merge(std::vector<T> &vec, int low, int m, int high, int &compare);

public:
  AlgorithmSort();
  void bubbleSort(std::vector<T> &vec, int n, int &compare, int &swap);
  void mergeSort(std::vector<T> &vec, int low, int high, int &compare);
};

template <class T> AlgorithmSort<T>::AlgorithmSort() {}

// Method bubbleSort
template <class T>
void AlgorithmSort<T>::bubbleSort(std::vector<T> &vec, int n, int &compare,
                                  int &swap) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      compare++;
      if (vec[j] > vec[j + 1]) {
        std::swap(vec[j], vec[j + 1]);
        swap++;
      }
    }
  }
}

// Method MergeSort
template <class T>
void AlgorithmSort<T>::mergeSort(std::vector<T> &vec, int low, int high,
                                 int &compare) {
  if (low < high) {
    int m = low + (high - low) / 2;
    mergeSort(vec, low, m, compare);
    mergeSort(vec, m + 1, high, compare);
    merge(vec, low, m, high, compare);
  }
}

// Method Merge
template <class T>
void AlgorithmSort<T>::merge(std::vector<T> &vec, int low, int m, int high,
                             int &compare) {
  int i, j, k;
  int n1 = m - low + 1;
  int n2 = high - m;
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for (i = 0; i < n1; i++)
    L[i] = vec[low + i];
  for (j = 0; j < n2; j++)
    R[j] = vec[m + 1 + j];
  // Fusionar los vectores auxiliares Ly R ordenados
  i = j = 0;
  k = low;
  while (i < n1 && j < n2) {
    compare++;
    if (L[i] <= R[j]) {
      vec[k] = L[i];
      i++;
    } else {
      vec[k] = R[j];
      j++;
    }
    k++;
  }
}

// <---------------------------------------------------------->
// <--------------------> Search Algoritms <-------------------->
// <---------------------------------------------------------->

template <class T> class AlgorithmSearch {
public:
  AlgorithmSearch();
  int binarySearch(std::vector<T> &vec, T key);
};

template <class T> AlgorithmSearch<T>::AlgorithmSearch() {}

// Method binarySearch
template <class T>
int AlgorithmSearch<T>::binarySearch(std::vector<T> &vec, T key) {
  int low = 0;
  int high = (int)vec.size() - 1;
  int mid = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == vec[mid]) {
      return mid;
    } else if (key < vec[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
// <---------------------------------------------------------->
// <--------------------> Functions <-------------------->
// <---------------------------------------------------------->

template <typename T> void totalTime(T startTime, T endTime) {
  auto time = endTime - startTime;
  std::cout << "Tiempo de ejecución: " << time / std::chrono::nanoseconds(1)
            << " ns" << std::endl;
}

inline std::vector<std::string> splitstr(std::string str, std::string deli) {
  std::vector<std::string> vec;
  int start = 0;
  int end = str.find(deli);
  while (end != -1) {
    vec.push_back(str.substr(start, end - start));
    start = end + deli.size();
    end = str.find(deli, start);
  }
  vec.push_back(str.substr(start, end - start));
  return vec;
}

#endif //