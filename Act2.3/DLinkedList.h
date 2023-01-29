#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_

#include "DLLNode.h"
#include "Record.h"
#include <iostream>
#include <stdexcept>
#include <unistd.h> // delete this to the end buddyyy
#include <vector>

template <class T> class DLinkedList {
private:
  int numElements;
  DLLNode<T> *head;
  DLLNode<T> *tail;
  DLLNode<T> *partition(DLLNode<T> *start, DLLNode<T> *end); // Working
  void _quickSort(DLLNode<T> *start, DLLNode<T> *end);       // Working
  void _mergeAux(DLinkedList<T> &list, int low, int m, int high);
  void mergeAux(DLinkedList<T> &list, int low, int high);
  int middle(DLLNode<T> start, DLLNode<T> last);
  int _binarySearch(DLinkedList<T> &list, T key); // Not checked

public:
  DLinkedList();                                     // Working
  ~DLinkedList();                                    // Working
  DLinkedList(const DLinkedList<T> &list);           // Working
  DLinkedList<T> getReversedSublist(int p1, int p2); // Working
  DLinkedList<T> mergeSort();                        // Working
  int getNumElements();                              // Working
  int binarySearch(T key);
  void printList(int i);              // Working
  void printListReversed();           // Working
  void addFirst(T value);             // Working
  void addLast(T value);              // Working
  void invert();                      // Working
  void quickSort();                   // Working
  void updateAt(int pos, T newValue); // Working
  bool deleteData(T value);           // Working
  bool deleteAt(int position);        // Working
  T getData(int position);            // Working
};

template <class T> DLinkedList<T>::DLinkedList() {
  // std::cout << "---> Creando una lista ligada vacia: " << this << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T> DLinkedList<T>::~DLinkedList() {
  // std::cout << "---> Liberando memoria de la lista ligada: " << this
  //           << std::endl;
  DLLNode<T> *p, *q;
  p = head;
  while (p != nullptr) {
    q = p->next;
    delete p;
    p = q;
  }
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T> int DLinkedList<T>::getNumElements() { return numElements; }

template <class T> void DLinkedList<T>::printList(int Date) {
  DLLNode<T> *ptr = head;
  while (ptr != nullptr) {
    (Date == 0) ? std::cout << (ptr->data).getAll() << std::endl
                : std::cout << (ptr->data).getAllD() << std::endl;

    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T> void DLinkedList<T>::printListReversed() {
  DLLNode<T> *ptr = tail;
  while (ptr != nullptr) {
    std::cout << (ptr->data).getAll() << std::endl;
    ptr = ptr->prev;
  }
  std::cout << std::endl;
}

template <class T> void DLinkedList<T>::addFirst(T value) {
  DLLNode<T> *newNode = new DLLNode<T>(value); // Create a new node
  // Si la lista esta vacia
  if (head == nullptr && tail == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  numElements++;
}

template <class T> void DLinkedList<T>::addLast(T value) {
  // La lista esta vacia
  if (head == nullptr && tail == nullptr) {
    addFirst(value);
  } else {
    // 1. crea un nuevoNodo
    DLLNode<T> *newNode = new DLLNode<T>(value);
    // 2. apunto tail->next a el nuevoNodo
    tail->next = newNode;
    newNode->prev = tail;
    // 3. Actualizo tail para que apunte al nuevoNodo
    tail = newNode;
    numElements++;
  }
}

template <class T> bool DLinkedList<T>::deleteData(T value) {
  // La lista esta vacia
  if (head == nullptr && tail == nullptr) {
    return false;
  } else {
    DLLNode<T> *p = head;
    DLLNode<T> *previous = nullptr;
    while (p != nullptr && p->data != value) {
      previous = p;
      p = p->next;
    }
    // si no existe value en la lista
    if (p == nullptr)
      return false;
    // si debe borrarse el primer elemento de la lista
    if (p != nullptr && p == head) {
      head = p->next;
      if (head != nullptr)
        head->prev = nullptr;
      if (head == nullptr) // si habia un solo nodo en la lista
        tail = nullptr;
    } else if (p->next ==
               nullptr) { // si debe borrarse el ultimo nodo de la lista
      previous->next = nullptr;
      tail = previous;
    } else { // si debe borrarse cualquier otro elemento
      previous->next = p->next;
      p->next->prev = previous;
    }
    delete p;
    numElements--;
    return true;
  }
}

template <class T> bool DLinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  } else if (position == 0) { // borrar primer nodo de la lista
    DLLNode<T> *p = head;
    // si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr)
      head = tail = nullptr;
    else {
      head = p->next;
      head->prev = nullptr;
    }
    delete p;
    numElements--;
    return true;
  } else { // borrar cualquier otro nodo de la lista
    DLLNode<T> *p = head;
    DLLNode<T> *previous = nullptr;
    int index = 0;
    // buscar el indice del elemento a borrar
    while (index != position) {
      previous = p;
      p = p->next;
      index++;
    }
    // si debe borrarse el ultimo elemento
    if (p->next == nullptr) {
      previous->next = nullptr;
      tail = previous;
    } else { // borrar cualquier otro nodo
      previous->next = p->next;
      p->next->prev = previous;
    }
    delete p;
    numElements--;
    return true;
  }
}

template <class T> T DLinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
  } else {
    if (position == 0) { // si es el primero de la lista
      return head->data;
    }
    // debemos buscar el elemento
    DLLNode<T> *p = head;
    int index = 0;
    // buscar el indice del elemento a borrar
    while (p != nullptr) {
      if (index == position)
        return p->data;
      p = p->next;
      index++;
    }
  }
  return {};
}

// <----------------------------> Invert <---------------------------->
// <------------> Complexity O() <------------>
template <class T> void DLinkedList<T>::invert() {
  DLLNode<T> *tmp = nullptr;
  DLLNode<T> *current = head;

  while (current != nullptr) {
    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    current = current->prev;
  }
  if (tmp != nullptr) {
    head = tmp->prev;
  }
}

// <---------------------> getReversedSublist <--------------------->
// <------------> Complexity O(1) <------------>
template <class T>
DLinkedList<T> DLinkedList<T>::getReversedSublist(int p1, int p2) {
  if ((p1 < 0 || p1 >= numElements) || (p2 < 0 || p2 >= numElements)) {
    std::cout << "Indice fuera de rango" << std::endl;
    return {};
  } else {
    DLLNode<T> *current = head;
    DLinkedList<T> list;
    int index = 0;

    while (current != nullptr) {
      if ((index >= p1) && (index <= p2)) {
        std::cout << (current->data).getAll() << std::endl;
        list.addFirst(current->data);
      }
      current = current->next;
      index++;
    }
    return list;
  }
}

// <------------------------> Copia de LinkedList <------------------------->
// <------------> Complexity O(1) <------------>
template <class T> DLinkedList<T>::DLinkedList(const DLinkedList<T> &list) {
  std::cout << "---> Copia de LinkedList: " << this << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
  DLLNode<T> *p = list.head;
  while (p != nullptr) {
    addLast(p->data);
    p = p->next;
  }
}

template <class T> void DLinkedList<T>::updateAt(int pos, T newValue) {
  if (pos < 0 || pos >= numElements) {
    throw std::out_of_range("Index out of range");
  } else {
    DLLNode<T> *p = head;
    int index = 0;

    while (index != pos) {
      p = p->next;
      index++;
    }
    p->data = newValue;
  }
}

// <----------------------------> Algorithms <---------------------------->

// <------------> Auxiliar QuickSort <------------>
// <------------> Complexity O(nlog(n))
template <class T>
void DLinkedList<T>::_quickSort(DLLNode<T> *start, DLLNode<T> *end) {
  if (end != NULL && start != end && start != end->next) {
    DLLNode<T> *pivot = partition(start, end);
    _quickSort(start, pivot->prev);
    _quickSort(pivot->next, end);
  }
}

//------------------------------Sort---------------------------------
// <------------> Complexity O(nlog(n)) <------------>
template <class T> void DLinkedList<T>::quickSort() {
  // std::cout << "---> Aplicando algoritmo de ordenamiento " << std::endl;
  _quickSort(head, tail);
}

//------------------------------ Partition ---------------------------------
// <------------> Complexity O(nlog(n)) <------------>
template <class T>
DLLNode<T> *DLinkedList<T>::partition(DLLNode<T> *start, DLLNode<T> *end) {
  DLLNode<T> *pivot = end;
  DLLNode<T> *i = start->prev;
  for (DLLNode<T> *ptr = start; ptr != end; ptr = ptr->next) {
    if (ptr->data <= pivot->data) {
      i = (i == NULL ? start : i->next);
      Record temp = i->data;
      i->data = ptr->data;
      ptr->data = temp;
    }
  }
  i = (i == NULL ? start : i->next);
  Record temp = i->data;
  i->data = pivot->data;
  pivot->data = temp;
  return i;
}

// <--------------------> Method MergeSort <-------------------->
template <class T> DLinkedList<T> DLinkedList<T>::mergeSort() {
  std::cout << "---> Aplicando algoritmo de ordenamiento " << std::endl;
  DLLNode<T> *current = head;
  DLinkedList<T> list;
  while (current != nullptr) {
    list.addFirst(current->data);
    current = current->next;
  }
  mergeAux(list, 0, list.getNumElements() - 1);

  return list;
}

template <class T>
void DLinkedList<T>::mergeAux(DLinkedList<T> &list, int low, int high) {
  if (low < high) {
    int m = low + (high - low) / 2;
    mergeAux(list, low, m);
    mergeAux(list, m + 1, high);
    _mergeAux(list, low, m, high);
  }
}

// <--------------------> Method Merge <-------------------->
template <class T>
void DLinkedList<T>::_mergeAux(DLinkedList<T> &list, int low, int m, int high) {
  int i, j, k;
  int n1 = m - low + 1;
  int n2 = high - m;
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for (i = 0; i < n1; i++) {
    L[i] = list.getData(low + i);
  }
  for (j = 0; j < n2; j++) {
    R[j] = list.getData(m + 1 + j);
  }
  // Fusionar los vectores auxiliares Ly R ordenados
  i = j = 0;
  k = low;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      // std::cout << (list.getData(low + i)).getAll() << std::endl;
      // std::cout << "Merging " << std::endl;
      list.updateAt(k, L[i]);
      i++;
    } else {
      // std::cout << i << " " << j << " " << n1 << " " << n2 << " " <<
      // std::endl; std::cout << "Merging 1" << std::endl;
      list.updateAt(k, R[j]);
      j++;
    }
    k++;
  }
}

// <--------------------> Method BinarySearch <-------------------->

template <class T>
int DLinkedList<T>::_binarySearch(DLinkedList<T> &list, T key) {
  int low = 0;
  int high = list.getNumElements();
  int mid = 0;
   
  while (low <= high) {
    mid = (low + high) / 2;
    if ((key == list.getData(mid))) {
        return mid;
    } else if (key > list.getData(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

template <class T> int DLinkedList<T>::binarySearch(T key) {
  DLLNode<T> *current = head;
  DLinkedList<T> list;
  while (current != nullptr) {
    list.addFirst(current->data);
    current = current->next;
  }
  return _binarySearch(list, key);
}

#endif // _DLINKEDLIST_H_
