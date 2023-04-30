#ifndef cifradoAES_H
#define cifradoAES_H
#include "funcionesAES.h"


void pr6 () {

  std::cout << "Bienvenido al programa de cifrado AES" << std::endl;

  std::vector<std::vector<std::string>> key = {
    {"04", "04", "04", "04"},
    {"03", "03", "03", "03"},
    {"02", "02", "02", "02"},
    {"00", "00", "00", "00"}
  };


  int bloque = 1;
  std::cout << "Introduzca la clave de cifrado poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> bloque;
  if (bloque == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> key[j][i];
      }
    }
  }

  

  std::cout << "La clave de cifrado es: " << std::endl;

  printMatrix(key);

  int clave = 1;

  std::cout << "Introduzca el bloque de texto 1 poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> clave;
  
  std::vector<std::vector<std::string>> state = {
    {"00", "11", "22", "33"},
    {"44", "55", "66", "77"},
    {"88", "99", "aa", "bb"},
    {"cc", "dd", "ee", "ff"}
  };
  if (clave == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto 1 es: " << std::endl;

  printMatrix(state);

  std::vector<std::vector<std::string>> IV = {
    {"00", "11", "22", "33"},
    {"43", "52", "61", "70"},
    {"8e", "9f", "ac", "bd"},
    {"c8", "d9", "ea", "fb"}
  };

  int clave2 = 1;
  std::cout << "Introduzca el bloque de texto 2 poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> clave2;
  
  std::vector<std::vector<std::string>> state2 = {
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"}
  };
   std::vector<std::vector<std::string>> state2Plus = {
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "--"}
  };
  if (clave2 == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto 2 es: " << std::endl;

  printMatrix(state2);


  

  std::vector<std::vector<std::vector<std::string>>> keySchedule = KeySchedules(key);

  std::cout << "Los bloques de texto cifrado son: " << std::endl;

  modeCBC(state, state2, keySchedule, IV);

  // std::cout << "Parte OPCIONAL: Cipher stealing." << std::endl;
  // std::cout << "Los bloques de texto cifrado son: " << std::endl;
  // modeCBCstealing(state, state2Plus, keySchedule, IV);



}

#endif