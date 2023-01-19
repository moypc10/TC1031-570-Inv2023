/**
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion y ejecucion:
 *     g++ -std=c++20 *.cpp -Wall -g -o file && ./file < TestCases/bitacora.txt

 **/
#include "Record.h"

int main() {
  std::vector<Record> listRecords;
  std::vector<std::string> rows, dataRow, date, ipPort;
  std::string tmp;

  // <--------------------> Getting data <-------------------->
  while (std::cin) {
    std::getline(std::cin, tmp);
    rows.push_back(tmp);
  }

  // Put data into the class record
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

    listRecords.push_back(a);
  }

  // <--------------------> Sorting data <-------------------->
  AlgorithmSort<Record> sortObj;

  // 1  | Algoritmo Burbuja   | Complejidad Computacional: O(n^2)
  // 2  | Algoritmo Merge     | Complejidad Computacional: O(n log n)

  // Algoritmo más lento
  int swaps = 0, compSort = 0;
  std::cout << "Sort Algorithm: BubbleSort " << std::endl;
  auto startTime = std::chrono::system_clock::now();
  sortObj.bubbleSort(listRecords, listRecords.size(), compSort, swaps);
  auto endTime = std::chrono::high_resolution_clock::now();
  totalTime(startTime, endTime);
  std::cout << "Comparaciones Sort Algorithm: " << compSort << std::endl;
  std::cout << "Swaps: " << swaps << std::endl;
  std::cout << std::endl;

  // Algoritmo más rápido
  compSort = 0;
  std::cout << "Sort Algorithm: Merge Sort " << std::endl;
  startTime = std::chrono::system_clock::now();
  sortObj.mergeSort(listRecords, 0, listRecords.size() - 1, compSort);
  endTime = std::chrono::high_resolution_clock::now();
  totalTime(startTime, endTime);
  std::cout << "Comparaciones Sort Algorithm: " << compSort << std::endl;
  std::cout << std::endl;

  // <--------------------> Data from user <-------------------->

  // Fecha Inicio y Fin Usuario
  std::string I = "Jun 01 01:18:39"; // Fecha Inicio
  std::string F = "Jun 01 01:34:06"; // Fecha FIn

  Record Inicio(I.substr(0, 3), I.substr(4, 2), I.substr(7, 2), I.substr(10, 2),
                I.substr(13, 2), "", "", "");
  Record Fin(F.substr(0, 3), F.substr(4, 2), F.substr(7, 2), F.substr(10, 2),
             F.substr(13, 2), "", "", "");

  // <--------------------> Searching algorithms <-------------------->

  AlgorithmSearch<Record> searchObj;

  // Busqueda Binaria ~ Complejidad Computacional: O(log n)

  int in = searchObj.binarySearch(listRecords, Inicio);
  int fi = searchObj.binarySearch(listRecords, Fin);

  if ((in != -1) && (fi != -1)) {
    for (int i = in; i <= fi; i++) {
      std::cout << listRecords[i].getAll() << std::endl;
    }
  } else
    std::cout << "Fechas no Encontradas" << std::endl;

  // <--------------------> Save bitacora_ordenada.txt <-------------------->

  // Aplicar comando en sh y comentar los std::cout en sort algorithms
  // g++ -std=c++20 *.cpp -Wall -g -o file && ./file < bitacora.txt >
  // bitacora_ordenada.txt

  // for (int i = 0; i < (int)listRecords.size() ; i++) {
  //    std::cout << listRecords[i].getAll() << std::endl;
  // }

  return 0;
}
