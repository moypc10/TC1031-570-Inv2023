/* Act 1.2 - Algoritmos de Búsqueda y Ordenamiento

Instituto Tecnológico y de Estudios Superiores de Monterrey | Campus Guadalajara

Guillermo Esquivel Ortiz - A01625621
Moisés Hiram Pineda Campos - A01625510

15/Enero/2023

Para compilar el archivo (sh):
    g++ -std=c++17 -Wall -O3 *.cpp -o main
    ./main < TestCases/test01.txt
*/

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

// ------------------------ Sorting Algorithms ------------------------

template <class T>
class AlgorithmSort {
  private:
    void merge(std::vector<T> &vec, int low, int m, int high, int &compare);
    int partition(std::vector<T> &values, int low, int high, int &compare, int &swap);
//
  public:
    AlgorithmSort();
    void bubbleSort(std::vector<T> &vec, int n, int &compare, int &swap);
    void mergeSort(std::vector<T> &vec, int low, int high, int &compare);
    void quickSort(std::vector<T> &values, int low, int high, int &compare, int &swap);
};

template <class T>
AlgorithmSort<T>::AlgorithmSort() {}

// Method bubbleSort
template <class T>
void AlgorithmSort<T>::bubbleSort(std::vector<T> &vec, int n, int &compare, int &swap) {
  for(int i = 0; i < n-1; i++){
    for (int j = 0; j < n-i-1; j++){
      compare++;
      if(vec[j] > vec[j+1]){
      std::swap(vec[j], vec[j+1]);
      swap++;
      }
    }
  }
}

// Method MergeSort
template <class T>
void AlgorithmSort<T>::mergeSort(std::vector<T> &vec, int low, int high, int &compare) {
  if (low < high) {
    int m = low + (high - low) / 2;
    mergeSort(vec, low, m, compare);
    mergeSort(vec, m+1, high, compare);
    merge(vec, low, m, high, compare);
  }
}

// Method Merge
template <class T>
void AlgorithmSort<T>::merge(std::vector<T> &vec, int low, int m, int high, int &compare) {
  int i, j, k;
  int n1 = m - low + 1;
  int n2 = high - m;
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for (i = 0; i < n1; i++) L[i] = vec[low + i];
  for (j = 0; j < n2; j++) R[j] = vec[m + 1 + j];
  // Fusionar los vectores auxiliares Ly R ordenados
  i = j = 0;
  k = low;
  while (i<n1 && j<n2) {
    compare++;
    if (L[i] <= R[j]){
      vec[k]=L[i];
      i++;
    }
    else{
      vec[k] = R[j];
      j++;
    }
    k++;
  }
}

// Method Quick sort
template <class T>
void AlgorithmSort<T>::quickSort(std::vector<T> &vec, int low, int high, int &compare, int &swap) {
  if (low < high) {
    int pivot = partition(vec, low, high, compare, swap);
    quickSort(vec, low, pivot - 1, compare, swap);
    quickSort(vec, pivot + 1, high, compare, swap);
  }
}
// Method Partition
template <class T>
int AlgorithmSort<T>::partition(std::vector<T> &vec, int low, int high, int &compare, int &swap) {
  int pivot = vec[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    compare++;
    if (vec[j] < pivot) {
      i++;
      std::swap(vec[i], vec[j]);
      swap++;
    }
  }
  std::swap(vec[i + 1], vec[high]);
  return i + 1;
}


//// ------------------------ Search Algorithms ------------------------

template <class T>
class AlgorithmSearch {
  public:
    AlgorithmSearch();
    int orderedSequence(std::vector<T> &vec, int key, int &compare);
    int binarySearch(std::vector<T> &vec, int key, int &compare);
};

template <class T>
AlgorithmSearch<T>::AlgorithmSearch() {}

// Method orderedSequence
template <class T>
int AlgorithmSearch<T>::orderedSequence(std::vector<T> &vec, int key, int &compare){
    for(int i = 0; i < (int)vec.size(); ++i) {
      ++compare;
      if(key <= vec[i]) { 
        return key==vec[i] ? i : -1;
      }
    }
    return -1;
}

// Method binarySearch
template <class T>
int AlgorithmSearch<T>::binarySearch(std::vector<T> &vec, int key, int &compare) {
  int low = 0;
  int high = (int)vec.size()-1;
  int mid = 0;
  while(low <= high) {
    mid = (low + high)/2;
    ++compare;
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


// ------------------------ Functions ------------------------

// Vector output
void printVector(std::vector<int> vec) {
    std::cout << "\nVector ordenado: ";
    for(int i = 0; i < (int)vec.size(); i++) {
      std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// Vector input
void cinVector(std::vector<int> &vec, int size){
  int tmp = 0;
  for(int i = 0; i < size; i++) {
      std::cin >> tmp;
      vec.push_back(tmp);
  }  
}

// ---------------------------- Main ----------------------------

int main() {
    int size, sortAlg, searchAlg, key, swaps = 0, compSort = 0, compSear = 0; 
    std::vector<int> vec;

    // Data input
    std::cin >> size;
    std::cin >> sortAlg;
    std::cin >> searchAlg;
    std::cin >> key;

    cinVector(vec, size);

    AlgorithmSort<int> sortObj;
    AlgorithmSearch<int> searchObj;

    // 1  | Algoritmo Burbuja   | Complejidad Computacional: O(n^2)
    // 2  | Algoritmo Merge     | Complejidad Computacional: O(n log n)
    // 3  | Algoritmo QuickSort | Complejidad Computacional: O(n^2)

    if (sortAlg == 1) { 
      sortObj.bubbleSort(vec, size, compSort, swaps);
      printVector(vec);
      std::cout << "Comparaciones Sort Algorithm: " << compSort << std::endl;
      std::cout << "Swaps: " << swaps << std::endl; 
    } else if (sortAlg == 2){
      sortObj.mergeSort(vec, 0, size - 1, compSort);
      printVector(vec);
      std::cout << "Comparaciones Sort Algorithm: " << compSort << std::endl;
    } else if (sortAlg == 3){ 
      sortObj.quickSort(vec, 0, size - 1, compSort, swaps);
      printVector(vec);
      std::cout << "Comparaciones Sort Algorithm: " << compSort << std::endl;
      std::cout << "Swaps: " << swaps << std::endl;
    }

    // 1  |   Busqueda Secuencial Ordenada  |   Complejidad Computacional: O(n/2)
    // 2  |   Busqueda Binaria              |   Complejidad Computacional: O(log n)

    if (searchAlg == 1){
      std::cout << "Posicion del key: " << searchObj.orderedSequence(vec, key, compSear) << std::endl;
      std::cout << "Comparaciones Search Algorithm: " << compSear << std::endl;
    } else if (searchAlg == 2){
      std::cout << "Posicion del key: " << searchObj.binarySearch(vec, key, compSear) << std::endl;
      std::cout << "Comparaciones Search Algorithm: " << compSear << std::endl;
    }
}