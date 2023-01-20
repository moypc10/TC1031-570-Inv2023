/** 
* Ejemplo que implementa un queue usando una lista ligada 
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "QueueLinkedList.h"


int main() {
  std::cout << "Ejemplo de queue usando listas ligadas\n";

  QueueLinkedList<int> miQueue;
  // isEmpty()
  std::cout << "isEmpty(): " << std::boolalpha << miQueue.isEmpty() << std::endl;
  std::cout << "numElements: " << miQueue.getNumElements() << std::endl;
  std::cout << std::endl;
  // enqueue()
  std::cout << "Enqueue de 5 elementos ..." << std::endl;
  for (int i = 1; i < 6; i++) {
    std::cout << "enqueue(" << i+10 << ")" << std::endl;
    miQueue.enqueue(i+10);
  }
  std::cout << "numElements: " << miQueue.getNumElements() << std::endl;
  miQueue.print();
  std::cout << std::endl;

  // dequeue()
  try {
    std::cout << "dequeue() " << std::endl;
    miQueue.dequeue();
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico el queue" << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico el queue" << std::endl;
  } 
  std::cout << "numElements: " << miQueue.getNumElements() << std::endl;
  miQueue.print();
  std::cout << std::endl;

  // getFront()
  try {
    std::cout << "getFront(): " << miQueue.getFront() << std::endl;
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico el queue" << std::endl;
  }
  catch (...) {
    std::cout << "Error desconocido, no se modifico el queue" << std::endl;
  } 
  miQueue.print();
  std::cout << std::endl;
  
    
  
  return 0;
}