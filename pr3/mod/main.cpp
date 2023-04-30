#include <iostream>
#include <string>
#include <vector>

//libreria para una cola
#include <queue>

#include "PRN.h"

int main () {

  std::vector<int> G1;
  std::vector<int> G2;
  std::vector<int> Secuencia_C_A;
  int PRNID = 0;
  int longitud;

  std::cout << "Introduzca el PRNID: ";
  std::cin >> PRNID;
  PRNID = PRNID - 1;
  std::cout << "Introduzca la longitud de la secuencia: ";
  std::cin >> longitud;




  Secuencia_C_A = C_A(G1, G2, Secuencia_C_A, PRNID, longitud);
  
  std::cout << "Secuencia C/A: " << Secuencia_C_A.size()<< std::endl;
  for (size_t i = 0; i < Secuencia_C_A.size(); i++) {
    std::cout << Secuencia_C_A.at(i);
  }

  std::cout << std::endl; 

 
  return 0;
 
}