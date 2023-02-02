/** Act 3.3 - Actividad Integral de BST (Evidencia Competencia)
 *
 * Instituto Tecnológico y de Estudios Superiores de Monterrey
 * Campus Guadalajara
 *
 * Guillermo Esquivel Ortiz -
 * Moisés Hiram Pineda Campos - A01625510
 * Alma Paulina González Sandoval - A01631256
 *
 * 1 de Febrero del 2023
 *
 *****************************************************************
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall *.cpp && ./a.out
 *
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./a.out < TestCaes/...
 *
 * Ejecucion
 *    ./a.out < TestCases/test0n.txt
 *
 * Compilacion y ejecucion:
 *   g++ -std=c++17 -Wall *.cpp && ./a.out < bitacoraHeap.txt
 **/
#include "DLinkedList.h"
#include "Ip.h"
#include "MaxHeap.h"
#include "Record.h"
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
// <--------------------> Main <------------------------------>

int main() {
  MaxHeap<Ip> MaxHeap(16807); // Obtained from "wc -l bitacoraHeap.txt"
  DLinkedList<Record> listRecords;
  std::vector<std::string> rows, dataRow, ipPort, listIp, date;
  std::string tmp;

  // <--------------------> Getting data <-------------------->
  while (std::cin) {
    std::getline(std::cin, tmp); // Obtienes cada row
    rows.push_back(tmp);
  }

  for (int i = 0; i < (int)rows.size() - 1; i++) {
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
  // <--------------------> HeapSort <-------------------->

  // Complejidad Computacional O(n log n)
  std::vector<Record> sortRecords = listRecords.heapSort();

  // ---> Remover el comentario y ejecutar el comando sh para guardar en
  // bitacora_ordenada.txt <----

  // g++ -std=c++17 -Wall *.cpp && ./a.out < bitacoraHeap.txt >
  // bitacora_ordenada.txt

  // for (int i = sortRecords.size() - 1; i >= 0; i--) {
  //   std::cout << sortRecords[i].getAll() << " ress" << std::endl;
  // }

  // <--------------------> Cuenta de casos <-------------------->
  int c = 1;
  for (int i = 1; i < (int)sortRecords.size() + 1; i++) {
    if (sortRecords[i - 1] == sortRecords[i])
      c++;
    else {
      Ip ip(sortRecords[i - 1].getIp(), c);
      MaxHeap.push(ip);
      c = 1;
    }
  }

  // <-------------> Registro de Ip's con mayor accesos <------------>

  // ---> Remover comentarios y ejecutar el comando sh para guardar en
  // ips_con_mayor_acceso.txt <----

  // g++ -std=c++17 -Wall *.cpp && ./a.out < bitacoraHeap.txt >
  //  ips_con_mayor_acceso.txt

  // while (MaxHeap.top().getN() != 0) {
  //   std::cout << MaxHeap.top() << std::endl;
  //   MaxHeap.pop();
  // }

  // <-------------> Print de 5 mayores ocurrencias <------------>

  int index = 0;
  while (MaxHeap.top().getN() != 0) {
    if (index < 5) {
      std::cout << MaxHeap.top() << std::endl;
      index++;
    } else
      break;
    MaxHeap.pop();
  }

  return 0;
}