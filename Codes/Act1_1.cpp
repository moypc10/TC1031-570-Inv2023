/* Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad

Instituto Tecnológico y de Estudios Superiores de Monterrey | Campus Guadalajara

Guillermo Esquivel Ortiz - A01625621
Moisés Hiram Pineda Campos -

09/Enero/2023

Para compilar el archivo (sh):
    g++ mainFunctions.cpp -o file
    ./file
*/

#include <iostream>
#include <vector>

// ----------------------------- Functions Sum -----------------------------

// Iterativa
void sumaIterativa(std::vector<int> vec) {
  int s = 0;

  // Ciclo para sumar cada elemento del vector
  for (int i = 0; i < vec.size(); i++) {
    // Precondicion que sea positivo
    if (vec[i] > 0) {
      for (int j = 0; j <= vec[i]; j++) {
        s += j;
      }
      std::cout << "Suma iterada hasta el número " << vec[i] << ": " << s << std::endl;
      s = 0;
    } else {
      std::cout << "Es un número negativo" << std::endl;
    }
  }
}

// Recursiva
unsigned long int summation(int n) {
  if (n > 0) {
    if (n < 2)
      return 1;
    return (summation(n - 1) + n);
  } else {
    std::cout << "Es un número negativo" << std::endl;
    return 0;
  }
}

// Main Recursiva
void sumaRecursiva(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "Suma recursiva hasta el numero " << vec[i] << ": " << summation(vec[i]) << std::endl;
  }
}

// ----------------------------- Functions Fibonacci -----------------------------

// Iterativo
void fibonacciIterativo(std::vector<int> vec) {
  int x = 0, y = 1, z = 0;

  for (int i = 1; i <= 30; i++) {
    if (i == 5 || i == 10 || i == 15 || i == 30) {
      std::cout << "Número " << i << " de la serie: " << z << std::endl;
    }

    z = x + y;
    x = y;
    y = z;
  }
}

// Recursiva
int F(int fib) {
  if (fib == 1 || fib == 2)
    return 1;
  return F(fib - 1) + F(fib - 2);
}

// Main Recursiva
void fibonacciRecursivo(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "Número " << vec[i] << " de la serie: " << F(vec[i]) << std::endl;
  }
}

// ----------------------------- Functions Average -----------------------------

// Iterativo
void promedioIterativo(std::vector<int> ave) {
  float total = 0;
  for (int i = 0; i < ave.size(); i++) {
    total += ave[i];
  }
  std::cout << "Promedio: " << total / ave.size() << std::endl;
}

// Recursivo
float promedioRecursivo(std::vector<int> vec, int n = 0) {
  if (n != vec.size())
    return (vec[n] + promedioRecursivo(vec, n + 1));
  else
    return 0;
}

// ---------------------------------------- Main ----------------------------------------

int main() {

  // ----------------------------- Suma -----------------------------
  std::vector<int> vec = {20, 50, 100, 1000};

  // Iterativa
  std::cout << "\nSuma Iterativa: " << std::endl;
  sumaIterativa(vec);

  // Recursiva
  std::cout << "\nSuma Recursiva: " << std::endl;
  sumaRecursiva(vec);

  // ----------------------------- Fibonacci -----------------------------
  std::vector<int> fib = {5, 10, 15, 30};

  // Iterativo
  std::cout << "\nFibonacci Iterativo: " << std::endl;
  fibonacciIterativo(fib);

  // Recursivo
  std::cout << "\nFibonacci Recursivo: " << std::endl;
  fibonacciRecursivo(fib);

  // ----------------------------- Promedio -----------------------------
  std::vector<int> ave = {1, 5, 10, 23, 56, 100};
  std::vector<int> ave_2 = {51, 35, 140, 323, 566, 1600, 231, 99, 1, 662};

  // Iterativo
  std::cout << "\nPromedio Iterativo: " << std::endl;
  promedioIterativo(ave);
  promedioIterativo(ave_2);

  // Recursivo
  std::cout << "\nPromedio Recursivo: " << std::endl;
  std::cout << "Promedio: " << promedioRecursivo(ave) / ave.size() << std::endl;
  std::cout << "Promedio: " << promedioRecursivo(ave_2) / ave_2.size() << std::endl;
}