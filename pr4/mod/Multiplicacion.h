//guardas
#ifndef SNOW_H
#define SNOW_H

#include <iostream>
#include <vector>
#include "funciones.h"



std::vector<int> multiplicarPolinomios(std::vector<int> polinomio1, std::vector<int> polinomio2, std::vector<int> polinomioAlgoritmo){
  std::vector<int> polinomioaux;
  std::vector<int> polinomio1aux;

  polinomioaux = polinomioMenosPeso(polinomio1, polinomio2);
  
  std::vector<std::vector<int>> polinomios = dividirPolinomioSegun1(polinomioaux);
  std::vector<std::vector<int>> polinomios1;

  for (int i = 0; i < polinomios.size(); i++) {
    polinomio1aux = polinomioMasPeso(polinomio1, polinomio2);
    bool suma = false;
    for (int j = 0; j <= dondeEstaEl1(polinomios.at(i)); j++) {
      //desplazamiento a la izquierda del polinomio1 
      if(j != 0) {
          if (polinomio1aux[0] == 1){
              suma = true;  
          } 
          polinomio1aux.push_back(0);
          for (int v = 0; v < polinomio1aux.size(); v++) {
            polinomio1aux[v] = polinomio1aux[v+1];
          }
          polinomio1aux.pop_back();
            
          if (suma == true ) {
            polinomio1aux = XOR(polinomio1aux, polinomioAlgoritmo);
            suma = false;
          }
      }

    }
    polinomios1.push_back(polinomio1aux); 
  }
  std::vector<int> polinomioaux2;
  polinomioaux2 = polinomios1.at(0);

  for (int i = 1; i < polinomios1.size(); i++) {
    polinomioaux2 = XOR(polinomioaux2, polinomios1.at(i));
  }
  return polinomioaux2;
}




std::vector<int> modmultiplicarPolinomios(std::vector<int> polinomio1, int iteraciones, std::vector<int> polinomioAlgoritmo){
  std::vector<int> polinomioaux;
  std::vector<int> polinomio1aux;
  polinomio1aux = polinomio1;

 // polinomioaux = polinomioMenosPeso(polinomio1, polinomio2);
  
  //std::vector<std::vector<int>> polinomios = dividirPolinomioSegun1(polinomioaux);
 // std::vector<std::vector<int>> polinomios1;

 // for (int i = 0; i < 1; i++) {
    
    bool suma = false;
    for (int j = 0; j <= iteraciones; j++) {
      //desplazamiento a la izquierda del polinomio1 
      if(j != 0) {
          if (polinomio1aux[0] == 1){
              suma = true;  
          } 
          polinomio1aux.push_back(0);
          for (int v = 0; v < polinomio1aux.size(); v++) {
            polinomio1aux[v] = polinomio1aux[v+1];
          }
          polinomio1aux.pop_back();
            
          if (suma == true ) {
            polinomio1aux = XOR(polinomio1aux, polinomioAlgoritmo);
            suma = false;
          }
      }

      std::cout << "iteracion " << j << " ";
       imprimirVector(polinomio1aux);

    }
    //polinomios1.push_back(polinomio1aux); 
 // }
  // std::vector<int> polinomioaux2;
  // polinomioaux2 = polinomios1.at(0);

  // for (int i = 1; i < polinomios1.size(); i++) {
  //   polinomioaux2 = XOR(polinomioaux2, polinomios1.at(i));
  // }
  return polinomio1aux;
}





#endif //SNOW_H