/* Act 2.3 - Actividad Integral estructura de datos lineales
 *(EvidenciaCompetencia)
 *
 * Instituto Tecnológico y de Estudios Superiores de Monterrey
 * Campus Guadalajara
 *
 * Guillermo Esquivel Ortiz - A01625621
 * Moisés Hiram Pineda Campos - A01625510
 *
 * 27/Enero/2023
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
 *    g++ -std=c++17 -Wall *.cpp && ./a.out < TestCases/test01.txt
 **/
#include "DLinkedList.h"
#include "Record.h"
#include <chrono>
#include <iostream>
#include <sstream>

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

// <--------------------> Main <------------------------------>

int main() {
  DLinkedList<Record> listRecords, listSearch;

  std::vector<std::string> rows, dataRow, date, dataRowS, dateS, ipPort;
  std::string tmp;
  Record x, beg;

  // <--------------------> Getting data <-------------------->
  //  ----> All data
  while (std::cin) {
    std::getline(std::cin, tmp); // Obtienes cada row
    rows.push_back(tmp);
  }

  for (int i = 4; i < (int)rows.size() - 1; i++) {
    dataRow = splitstr(rows[i], " ");
    date = splitstr(dataRow[2], ":");
    ipPort = splitstr(dataRow[3], ":");

    std::stringstream ss;
    for (auto it = dataRow.begin() + 4; it != dataRow.end(); it++) {
      if (it != dataRow.begin()) {
        ss << " ";
      }
      ss << *it;
    }

    Record a(dataRow[0], dataRow[1], date[0], date[1], date[2], ipPort[0],
             ipPort[1], ss.str());

    listRecords.addLast(a);
  }
  // ----> Data from user
  for (int i = 0; i <= 1; i++) {
    dataRowS = splitstr(rows[i], " ");
    dateS = splitstr(dataRowS[4], ":");
    Record got(dataRowS[2], dataRowS[3], dateS[0], dateS[1], dateS[2], "", "",
               "");
    listSearch.addLast(got);
  }

  std::cout << "\n-------> Original data <-------" << std::endl;
  listRecords.printList(0);
  std::cout << "\n-------> Input from user <-------" << std::endl;
  listSearch.printList(1);

  // <--------------------> Sorting data <-------------------->

  // 1 Mas rapido | Algoritmo QuickSort | Complejidad Computacional: O(n^2) 
  // 2 Mas lento  | Algoritmo Merge     | Complejidad Computacional: O(n log n)

  std::cout << "\n-------> Algorithm: Merge Sort <-------" << std::endl;
  auto startTime = std::chrono::system_clock::now();
  DLinkedList<Record> listRecords2 = listRecords.mergeSort();
  auto endTime = std::chrono::high_resolution_clock::now();
  auto time = endTime - startTime;
  std::cout << "Tiempo de ejecución: " << time / std::chrono::microseconds(1)
            << " ms" << std::endl;
  std::cout << std::endl;

  std::cout << "\n-------> Algorithm: Quick Sort <-------" << std::endl;
  startTime = std::chrono::system_clock::now();
  listRecords.quickSort();
  endTime = std::chrono::high_resolution_clock::now();
  time = endTime - startTime;
  std::cout << "Tiempo de ejecución: " << time / std::chrono::microseconds(1)
            << " ms" << std::endl;
  std::cout << std::endl;

  std::cout << "\n-------> Sorted List <-------" << std::endl;
  listRecords.printList(0);

  // <--------------------> Searching data <-------------------->

  // 1  | Algoritmo Busqueda Binaria | Complejidad Computacional: O(log n)
  int in = listRecords.binarySearch(listSearch.getData(1));
  int fi = listRecords.binarySearch(listSearch.getData(0));

  std::cout << "-------> Results test0n.txt<-------" << std::endl;
  if ((in != -1) && (fi != -1)) {
    for (int i = in; i <= fi; i++) {
      std::cout << (listRecords.getData(i)).getAll() << std::endl;
    }
  } else
    std::cout << "Fechas no Encontradas" << std::endl;

  // Aplicar comando en sh y comentar los std::cout en sort algorithms

  // <--------------------> Save resultado_busqueda.txt <-------------------->
  //  g++ -std=c++17 -Wall *.cpp && ./a.out < TestCases/test0n.txt >>
  //  resultado_busqueda.txt

  // <--------------------> Save bitacora_ordenada.txt <-------------------->
  // g++ -std=c++20 *.cpp -Wall -g -o file && ./file < bitacora.txt >
  // bitacora_ordenada.txt

  // for (int i = 0; i < (int)listRecords.size() ; i++) {
  //    std::cout << (listRecords.getData(i)).getAll() << std::endl;
  // }

  return 0;
}