/* Act 2.2 - Implementación de un ADT de Double Linked List

Instituto Tecnológico y de Estudios Superiores de Monterrey | Campus Guadalajara

Guillermo Esquivel Ortiz - A01625621
Moisés Hiram Pineda Campos - A01625510

24/Enero/2023

Compilacion para debug:
    g++ -std=c++17 -Wall -g -o main *.cpp
Ejecucion con valgrind:
    nix-env -iA nixpkgs.valgrind
    valgrind --leak-check=full ./main

 Compilacion para ejecucion:
    g++ -std=c++17 -Wall *.cpp && ./a.out
*/

#include "DLinkedList.h"
#include <iostream>

int main() {

  DLinkedList<int> miLista;

  std::cout << "numElements: " << miLista.getNumElements() << std::endl;

  //------------------addFirst------------------------------
  // Complejidad Computacional: O(n)
  std::cout << "---> Agregando 5 elementos al frente..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "printList: ";
  miLista.printList();
  std::cout << "printListReversed: ";
  miLista.printListReversed();
  std::cout << std::endl;

  //---------------------addLast-------------------------------
  // Complejidad Computacional: O(n)
  std::cout << "---> Agregando 5 elementos al final..." << std::endl;
  for (int i = 10; i < 15; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "printList: ";
  miLista.printList();
  std::cout << "printListReversed: ";
  miLista.printListReversed();
  std::cout << std::endl;

  /*
  //--------------------deleteData---------------------------
  // Complejidad Computacional: O(n)

  std::cout << "Delete 12: " << std::endl;
  miLista.deleteData(12);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << "Delete 5: " << std::endl;
  miLista.deleteData(5);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << "Delete 14: " << std::endl;
  miLista.deleteData(14);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "printList: " << std::endl;
  miLista.printList();
  std::cout << "Delete 114: " << std::endl;
  miLista.deleteData(114);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "printList: " << std::endl;
  miLista.printList();
  miLista.printListReversed();
  std::cout << std::endl;


  // DeleteAt puede lanzar una excepcion
  std::cout << "DeleteAt 2: " << std::endl;
  try {
    miLista.deleteAt(2);
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico la lista"
  << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << "DeleteAt 19: " << std::endl;
  try {
    miLista.deleteAt(19);
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico la lista"
  << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  //------------------------getData-------------------------
  // Complejidad Computacional: O(n)
  try {
    std::cout << "getData(3): " << miLista.getData(3) << std::endl;
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico la lista"
  << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
    try {
    std::cout << "getData(13): " << miLista.getData(13) << std::endl;
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico la lista"
  << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
 */

  // <------------------> FindData Method <------------------------->
  std::cout << "---> Implementacion del metodo FindData" << std::endl;
  std::cout << miLista.findData(10) << std::endl;
  // Valor no existente en la lista
  std::cout << miLista.findData(15) << std::endl;
  std::cout << std::endl;

  //-------------------------Sort-------------------------------

  // Algoritmo: QuickSort
  // Complejidad Computacional: O(N log N))

  std::cout << "---> Sort: Quicksort" << std::endl;
  std::cout << "Lista sin sort: ";
  miLista.printList();
  std::cout << "Lista con QuickSort: ";
  miLista.quickSort();
  miLista.printList();

  //--------------------------Invert----------------------------
  // Complejidad Computacional: O(n)
  std::cout << "---> Metodo invert" << std::endl;
  miLista.printList();
  miLista.invert();
  miLista.printList();

  //---------------------getReversedSublist---------------------
  // Complejidad Computacional: O(1)
  std::cout << "---> Metodo getReversedSublist" << std::endl;
  std::cout << "Lista 1: ";
  miLista.printList();
  DLinkedList<int> miLista2 = miLista.getReversedSublist(1, 4);
  std::cout << "Lista 2: ";
  miLista2.printList();
  std::cout << "Lista 1: ";
  miLista.printList();

  return 0;
}