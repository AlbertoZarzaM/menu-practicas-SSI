
#include <iostream>
#include <vector>
#include "Multiplicacion.h"
#include "funciones.h"


int main (){

  std::cout << "Bienvenido al programa de multiplicacion en Snow 3G y AES" << std::endl;

  std::cout << "Introduzca el primer byte " << std::endl;
  std::string byte1;
  std::cin >> byte1;
  std::cout << "Introduzca el entero " << std::endl;
  int byte2;
  std::cin >> byte2;
  std::cout << "Introduzca el algoritmo a utilizar Snow 3G(1) AES(2) " << std::endl;
  int algoritmo;
  std::cin >> algoritmo;

  std::vector<int> polinomio1 = deHexadecimalToBinario(byte1);


  std::cout << "El primer byte es: " << std::endl;
  imprimirVector(polinomio1);
  std::cout << "El entero es: " << std::endl;
  std::cout << byte2 << std::endl;

  if (algoritmo == 1) {
    std::cout << "Byte Algoritmo: " << std::endl;
    imprimirVector(polinomioSnow3G);
    std::cout << "Multiplicacion: " << std::endl;
    std::vector<int> resultado = modmultiplicarPolinomios(polinomio1, byte2, polinomioSnow3G);
    imprimirVector(resultado);
  }
  else if (algoritmo == 2) {
    std::cout << "Byte Algoritmo: " << std::endl;
    imprimirVector(polinomioAES);
    std::cout << "Multiplicacion: " << std::endl;
    std::vector<int> resultado = modmultiplicarPolinomios(polinomio1, byte2, polinomioAES);
    imprimirVector(resultado);
  }
  else {
    std::cout << "Algoritmo no valido" << std::endl;
  }

  return 0;
}