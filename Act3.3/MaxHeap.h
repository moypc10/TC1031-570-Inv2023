#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <iostream>
#include <stdexcept>
#include <vector>
#include <unistd.h>

template <class T> class MaxHeap {
private:
  // contiene los elementos del heap
  std::vector<T> data;
  // capacidad maxima del heap
  int maxSize;
  // tamano actual del heap
  int currentSize;
  int parent(int k);
  int left(int k);
  int right(int k);

public:
  MaxHeap(int capacity);
  ~MaxHeap();
  T low();
  int getCapacity();
  int getCurrentSize();
  int top();
  int size();
  int extractMin();
  bool isEmpty();
  void print();
  void push(T key);
  void pop(int i, int);
  void decreaseKey(int i, int n);
  void heapify(int i);
  std::vector<T> getMaxElements();
};

template <class T> MaxHeap<T>::MaxHeap(int capacity) {
  maxSize = capacity;
  currentSize = 0;
  data.resize(maxSize);
}

template <class T> MaxHeap<T>::~MaxHeap() {
  maxSize = 0;
  currentSize = 0;
  data.clear();
}

template <class T> bool MaxHeap<T>::isEmpty() { return (currentSize <= 0); }

template <class T> int MaxHeap<T>::getCapacity() { return maxSize; }

template <class T> int MaxHeap<T>::getCurrentSize() { return currentSize; }

template <class T> void MaxHeap<T>::print() {
  //std::cout << "Contenido del MaxHeap:" << std::endl;
  for (int i = 0; i < currentSize; i++) {
    std::cout << data[i] << std::endl;
  }
  std::cout << std::endl;
}

template <class T> int MaxHeap<T>::parent(int k) { return (k - 1) / 2; }

template <class T> int MaxHeap<T>::left(int k) { return (2 * k + 1); }

template <class T> int MaxHeap<T>::right(int k) { return (2 * k + 2); }

template <class T> void MaxHeap<T>::push(T key) {
  if (currentSize == maxSize) {
    throw std::out_of_range("Overflow: no se puede insertar la llave");
  }
  // Insertamos la nueva llave al final del vecor
  int k = currentSize;
  data[k] = key;
  currentSize++;
  // Reparar las propiedades del maxheap si son violadas
  while (k != 0 && data[parent(k)] < data[k]) {
    std::swap(data[k], data[parent(k)]);
    k = parent(k);
  }
}

template <class T> int MaxHeap<T>::top() {
  if (isEmpty()) {
    throw std::out_of_range("El heap esta vacio");
    return {};
  }
  return data[0];
}

template <class T> T MaxHeap<T>::low() {
  if (isEmpty()) {
    throw std::out_of_range("El heap esta vacio");
    return {};
  }
  return data[6];
}

template <class T> void MaxHeap<T>::pop(int i, int n) {
  decreaseKey(i, n);
  extractMin();
}

template <class T> void MaxHeap<T>::decreaseKey(int i, int n) {
  data[i] = n;
  while (i != 0 && data[parent(i)] < data[i]) {
    std::swap(data[i], data[parent(i)]);
    // swap(&data[i], &data[parent(i)]);
    i = parent(i);
  }
}

template <class T> int MaxHeap<T>::extractMin() {
  if (currentSize <= 0)
    return 145;
  if (currentSize == 1) {
    currentSize--;
    return data[0];
  }

  // Store the minimum value, and remove it from heap
  int root = data[0];
  data[0] = data[currentSize - 1];
  currentSize--;
  heapify(0);

  return root;
}

template <class T> void MaxHeap<T>::heapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < currentSize && data[l] > data[i])
    smallest = l;
  if (r < currentSize && data[r] > data[smallest])
    smallest = r;
  if (smallest != i) {
    std::swap(data[i], data[smallest]);
    heapify(smallest);
  }
}

#endif // _MAXHEAP_H_