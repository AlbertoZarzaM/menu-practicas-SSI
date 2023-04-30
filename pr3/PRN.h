
//guardas
#ifndef PRN_H
#define PRN_H

#include <iostream>
#include <vector>

std::vector<std::vector<int>> PRN = {
   {2,6},
   {3,7},
   {4,8},
   {5,9},
   {1,9},
   {2,10},
   {1,8},
   {2,9},
   {3,10},
   {2,3},
   {3,4},
   {5,6},
   {6,7},
   {7,8},
   {8,9},
   {9,10},
   {1,4},
   {2,5},
   {3,6},
   {4,7},
   {5,8},
   {6,9},
   {1,3},
   {4,6},
   {5,7},
   {6,8},
   {7,9},
   {8,10},
   {1,6},
   {2,7},
   {3,8},
   {4,9}
};


void imprimir_resultados(std::vector<int> G1, std::vector<int> G2, int semilla1, int semilla2, bool cabecera) {
  
  if(cabecera == true){ 
     std::cout << "LSFR1:                           |       LSFR2:" << std::endl;
     std::cout << std::endl;
  }


  for (size_t i = 0; i < G1.size(); i++) {
    std::cout << G1.at(i) << " ";
  }

  std::cout << "     " << semilla1 << "       |       ";

  

  for (size_t i = 0; i < G2.size(); i++) {
    std::cout << G2.at(i) << " ";
  }
  std::cout << "     " << semilla2 << std::endl;
  std::cout << std::endl;
};

std::vector<int> C_A(  std::vector<int> G1,  std::vector<int> G2,  std::vector<int> Secuencia_C_A,  int PRNID,  int longitud){
  

  //Relleno con 1111111111
  for (int i = 0; i < 10; i++) {
    G1.push_back(1);
  }
  for (int i = 0; i < 10; i++) {
    G2.push_back(1);
  }

  for (size_t i = 0; i < longitud; i++) {
  bool cabecera = false;  
  if (i == 0) {
    cabecera = true;
  } 

  int xorC_A = 0;
  int xorG1 = 0;

  int salida = G1.at(9);
  xorG1 = G1.at(2) ^ G1.at(9);

  int xorG2_1 = 0;
  int xorG2_2 = 0;
  xorG2_1 = G2.at(1) ^ G2.at(2) ^ G2.at(5) ^ G2.at(7) ^ G2.at(8) ^ G2.at(9);
 
  imprimir_resultados(G1, G2, xorG1, xorG2_1, cabecera );

  //acceder a los elementos 3 y 10 de la cola
  G1.insert(G1.begin(), xorG1);
  G1.pop_back();


  xorG2_2 = G2.at(PRN.at(PRNID).at(0)-1) ^ G2.at(PRN.at(PRNID).at(1)-1);
  
  G2.insert(G2.begin(), xorG2_1);
  G2.pop_back();



  xorC_A = salida ^ xorG2_2;

  Secuencia_C_A.push_back(xorC_A);

  

  }
  return Secuencia_C_A;
}



#endif //PRN_H