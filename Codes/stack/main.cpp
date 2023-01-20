/**
 * Ejemplo que implementa un stack usando listas ligadas 
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -Wall -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include <iostream>
#include "StackLinkedList.h"


int main() {
  std::cout << "Ejemplo de stack usando listas ligadas\n";
  
  StackLinkedList<int> myStack;
  // isEmpty()
  std::cout << "isEmpty(): " << std::boolalpha << myStack.isEmpty() << std::endl;
  std::cout << "numElements: " << myStack.getNumElements() << std::endl;
  std::cout << std::endl;
  
  // push
  std::cout << "Push de 5 elementos..." << std::endl;
  for (int i = 1; i < 6; i++) {
    std::cout << "push(" << i+10 << ")" << std::endl;
    myStack.push(i+10);
  }
  std::cout << "numElements: " << myStack.getNumElements() << std::endl;
  myStack.print();
  std::cout << std::endl;

  // pop excepcion
  std::cout << "Pop de 3 elementos..." << std::endl;
  for (int i = 1; i < 4; i++) {
    try {
      myStack.pop();
    }
    catch (std::out_of_range &e) {
      std::cout << "Error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
    }    
    catch (...) {
      std::cout << "Error desconocido, no se modifico el stack" << std::endl;
    }
  }
  std::cout << "numElements: " << myStack.getNumElements() << std::endl;
  myStack.print();
  std::cout << std::endl;
  
  // top excepcion
  try {
    std::cout << "getTop: " << myStack.getTop() << std::endl;
  }
  catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl << "No se modifico el stack" << std::endl;
  }    
  catch (...) {
    std::cout << "Error desconocido, no se modifico el stack" << std::endl;
  }
  // isEmpty()
  std::cout << "isEmpty(): " << std::boolalpha << myStack.isEmpty() << std::endl;  
  return 0;
}