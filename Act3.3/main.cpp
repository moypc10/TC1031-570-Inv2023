/** Act 3.3 - Actividad Integral de BST (Evidencia Competencia)
 *
 * Instituto Tecnológico y de Estudios Superiores de Monterrey
 * Campus Guadalajara
 *
 * Guillermo Esquivel Ortiz - A01625621
 * Moisés Hiram Pineda Campos - A01625510
 *
 * 31/Enero/2023
 *
 *****************************************************************
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall *.cpp
 *
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./a.out < TestCaes/...
 *
 * Ejecucion
 *    ./a.out < TestCases/test0n.txt
 *
 * Compilacion y ejecucion:
 *   g++ -std=c++17 -Wall *.cpp && ./a.out < bitacoraHeap.txt > a.txt  
 **/
#include "MaxHeap.h"
#include <algorithm> // Usado para la funcion removeX
#include <chrono>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

// <--------------------> Functions <------------------------->

// Funcion para realizar un split de la informacion obtenida de los txt
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
// Function from
// https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
std::string removeX(std::string str) {
  str.erase(remove(str.begin(), str.end(), '.'), str.end());
  return str;
}
// <--------------------> Main <------------------------------>

int main() {
  MaxHeap<int> MaxHeap(16807);
  std::vector<std::string> rows, dataRow, ipPort, listIp;
  std::string tmp;

  // <--------------------> Getting data <-------------------->
  //  ----> All data
  while (std::cin) {
    std::getline(std::cin, tmp); // Obtienes cada row
    rows.push_back(tmp);
  }

  for (int i = 0; i < (int)rows.size() - 1; i++) {
    dataRow = splitstr(rows[i], " ");
    ipPort = splitstr(dataRow[3], ":");

    std::string tmp = removeX(ipPort[0]);

    MaxHeap.push(stoi(tmp));
  }

  MaxHeap.print();
  


  return 0;
}