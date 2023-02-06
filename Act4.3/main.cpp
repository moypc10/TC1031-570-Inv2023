/** Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
 *
 * Instituto Tecnológico y de Estudios Superiores de Monterrey
 * Campus Guadalajara
 *
 * Guillermo Esquivel Ortiz - A01625621
 * Moisés Hiram Pineda Campos - A01625510
 * Alma Paulina González Sandoval - A01631256
 *
 * 5 de Febrero del 2023
 *
 *****************************************************************
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main < TestCases/graph01.txt
 *
 * Compilacion y ejecucion:
 *    g++ -std=c++17 -Wall *.cpp && ./a.out < bitacoraGrafos.txt
 **/

#include "Graph.h"
#include "IpData.h"
#include <iostream>
#include <sstream>

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf();
  Graph g1;

  // <--------------> Cargar Gráfica <------------------------>
  // Complejidad Computacional: O(N)
  g1.loadDirWeightedGraph(inputInfo);

  // <-------------> Procesar la Información<------------->
  // Complejidad Computacional: O(N)
  g1.processData();

  // <-------------> Algoritmo Dijkstra <-------------------> 
  // Complejidad Computacional: O((V+E)logV)
  g1.dijkstraAlgorithmBM();

  return 0;
}