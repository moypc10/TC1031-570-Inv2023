/**
 * Ejemplo que implementa uso de memoria dinamica
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

int main() {
    /* 
  int a = 5, *p;
  p = new int;
  *p = a;
  a = *p + 2;
  std::cout << a << std::endl;
  std::cout << *p << std::endl;
  std::cout << p << std::endl;
  std::cout << &p << std::endl;
  delete p;
  p = nullptr;
  std::cout << p << std::endl;
  p = NULL;
  std::cout << p << std::endl;
  */


/*
  
    int *p, *q, *r;
    p = new int;
    *p = 5;
    q = r = p;
    delete r;   
    std::cout << *p << std::endl;
    std::cout << *q << std::endl;
  */

  int *p = new int;
  *p = 5;
  if (p != nullptr)
    std::cout << *p << std::endl;
  p = new int;

  if (p != nullptr)
    std::cout << *p << std::endl;
  
/*
  int *p, *q, *r;
  p = new int;
  *p = 5;
  q = r = p;
  if (p != nullptr)
    std::cout << *p << std::endl;
  if (q != nullptr)
    std::cout << *q << std::endl;
  if (r != nullptr)
    std::cout << *r << std::endl;
  if (p == q) {
    std::cout << "p apunta a la misma direccion que q" << std::endl;
    std::cout << "Direccion donde el apuntador esta almacenado " << &p << "\t\t" << &q << std::endl;
    std::cout << "Direccion a donde el apuntador esta apuntando " << &(*p) << "\t\t" << &(*q) << std::endl;
    }
  if (p == r)
    std::cout << "p apunta a la misma direccion que r" << std::endl;
  */
  return 0;
}