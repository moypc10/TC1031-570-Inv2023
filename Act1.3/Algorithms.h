#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <iostream>
#include <vector>

template <typename T> struct Algorithms {
private:
  void merge(std::vector<T> &vec, int low, int m, int high, int &compare);

public:
  Algorithms();
  void bubbleSort(std::vector<T> &vec, int n, int &compare, int &swap);
  void mergeSort(std::vector<T> &vec, int low, int high, int &compare);
  int binarySearch(std::vector<T> &vec, T key);
};

template <typename T> Algorithms<T>::Algorithms() {}

// <--------------------> Method bubbleSort <-------------------->
template <typename T>
void Algorithms<T>::bubbleSort(std::vector<T> &vec, int n, int &compare,
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

// <--------------------> Method MergeSort <-------------------->
template <class T>
void Algorithms<T>::mergeSort(std::vector<T> &vec, int low, int high,
                              int &compare) {
  if (low < high) {
    int m = low + (high - low) / 2;
    mergeSort(vec, low, m, compare);
    mergeSort(vec, m + 1, high, compare);
    merge(vec, low, m, high, compare);
  }
}

// <--------------------> Method Merge <-------------------->
template <class T>
void Algorithms<T>::merge(std::vector<T> &vec, int low, int m, int high,
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

// <--------------------> Method BinarySearch <-------------------->
template <class T> int Algorithms<T>::binarySearch(std::vector<T> &vec, T key) {
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

#endif // _ALGORITHMS_H_