


#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <vector>

std::vector<int> polinomioSnow3G = {1,0,1,0,1,0,0,1};
std::vector<int> polinomioAES =    {0,0,0,1,1,0,1,1};

std::vector<int> polinomioMenosPeso(std::vector<int> vector1, std::vector<int> vector2){

  //El vector de menor peso es el que tiene menos 1 en su vector
  int pesoVector1 = 0;
  int pesoVector2 = 0;

  for (size_t i = 0; i < vector1.size(); i++) {
    if(vector1.at(i) == 1){
      pesoVector1++;
    }
  }

  for (size_t i = 0; i < vector2.size(); i++) {
    if(vector2.at(i) == 1){
      pesoVector2++;
    }
  }

  if(pesoVector1 < pesoVector2){
    return vector1;
  }else{
    return vector2;
  }
}
std::vector<int> polinomioMasPeso(std::vector<int> vector1, std::vector<int> vector2){

  //El vector de menor peso es el que tiene menos 1 en su vector
  int pesoVector1 = 0;
  int pesoVector2 = 0;

  for (size_t i = 0; i < vector1.size(); i++) {
    if(vector1.at(i) == 1){
      pesoVector1++;
    }
  }

  for (size_t i = 0; i < vector2.size(); i++) {
    if(vector2.at(i) == 1){
      pesoVector2++;
    }
  }

  if(pesoVector1 > pesoVector2){
    return vector1;
  }else{
    return vector2;
  }
}

std::vector<std::vector<int>> dividirPolinomioSegun1(std::vector<int> polinomio){

  std::vector<std::vector<int> > polinomios;

  std::vector<int> polinomioAux;

  for (int i = 0; i < polinomio.size(); i++) {
    polinomioAux.push_back(0);
  }

  for (int i = polinomio.size()-1; i >= 0; i--) {
    if(polinomio.at(i) == 1){
      polinomioAux.at(i) = 1;
      polinomios.push_back(polinomioAux);
      polinomioAux.at(i) = 0;
    }
  }
  return polinomios;
}

int dondeEstaEl1(std::vector<int> polinomio){

  for (int i = polinomio.size()-1; i >= 0; i--) {
    if(polinomio.at(i) == 1){
      return polinomio.size()-i-1;
    }
  }
  return -1;
}

void imprimirVector(std::vector<int> vector){
  for (size_t i = 0; i < vector.size(); i++) {
    std::cout << vector.at(i);
  }
  std::cout << std::endl;
}

std::vector<int> XOR(std::vector<int> vector1, std::vector<int> vector2){

  std::vector<int> vectorAux;

  for (size_t i = 0; i < vector1.size(); i++) {
    if(vector1.at(i) == vector2.at(i)){
      vectorAux.push_back(0);
    }else{
      vectorAux.push_back(1);
    }
  }

  return vectorAux;
}


std::vector<int> deHexadecimalToBinario(std::string hexadecimal){

  std::vector<int> binario;

  for (size_t i = 0; i < hexadecimal.size(); i++) {
    switch (hexadecimal.at(i))
    {
    case '0':
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(0);
      break;
    case '1':
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(1);
      break;
    case '2':
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(0);
      break;
    case '3':
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(1);
      break;
    case '4':
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(0);
      break;
    case '5':
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(1);
      break;
    case '6':
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(0);
      break;
    case '7':
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(1);
      break;
    case '8':
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(0);
      break;
    case '9':
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(0);
      binario.push_back(1);
      break;
    case 'A':
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(0);
      break;
    case 'B':
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(1);
      binario.push_back(1);
      break;
    case 'C':
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(0);
      break;

    case 'D':
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(0);
      binario.push_back(1);
      break;

    case 'E':
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(0);
      break;
    
    case 'F':
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(1);
      binario.push_back(1);
      break;

    default:

      break;
    }
  }

  return binario;
}










#endif //FUNCIONES_H