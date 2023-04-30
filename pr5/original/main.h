
#ifndef a_H
#define a_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> Rc1 = {{"01", "00", "00", "00"}};
std::vector<std::string> Rc2 = {{"02", "00", "00", "00"}};
std::vector<std::string> Rc3 = {{"04", "00", "00", "00"}};
std::vector<std::string> Rc4 = {{"08", "00", "00", "00"}};
std::vector<std::string> Rc5 = {{"10", "00", "00", "00"}};
std::vector<std::string> Rc6 = {{"20", "00", "00", "00"}};
std::vector<std::string> Rc7 = {{"40", "00", "00", "00"}};
std::vector<std::string> Rc8 = {{"80", "00", "00", "00"}};
std::vector<std::string> Rc9 = {{"1B", "00", "00", "00"}};
std::vector<std::string> Rc10 = {{"36", "00", "00", "00"}};

std::vector<std::vector<std::string>> Rcon = {Rc1, Rc2, Rc3, Rc4, Rc5, Rc6, Rc7, Rc8, Rc9, Rc10};

void printMatrix(std::vector<std::vector<std::string>> state);

std::vector<std::vector<std::string>> S_Caja = {
  {"63", "7c", "77", "7b", "f2", "6b", "6f", "c5", "30", "01", "67", "2b", "fe", "d7", "ab", "76"},
  {"ca", "82", "c9", "7d", "fa", "59", "47", "f0", "ad", "d4", "a2", "af", "9c", "a4", "72", "c0"},
  {"b7", "fd", "93", "26", "36", "3f", "f7", "cc", "34", "a5", "e5", "f1", "71", "d8", "31", "15"},
  {"04", "c7", "23", "c3", "18", "96", "05", "9a", "07", "12", "80", "e2", "eb", "27", "b2", "75"},
  {"09", "83", "2c", "1a", "1b", "6e", "5a", "a0", "52", "3b", "d6", "b3", "29", "e3", "2f", "84"},
  {"53", "d1", "00", "ed", "20", "fc", "b1", "5b", "6a", "cb", "be", "39", "4a", "4c", "58", "cf"},
  {"d0", "ef", "aa", "fb", "43", "4d", "33", "85", "45", "f9", "02", "7f", "50", "3c", "9f", "a8"},
  {"51", "a3", "40", "8f", "92", "9d", "38", "f5", "bc", "b6", "da", "21", "10", "ff", "f3", "d2"},
  {"cd", "0c", "13", "ec", "5f", "97", "44", "17", "c4", "a7", "7e", "3d", "64", "5d", "19", "73"},
  {"60", "81", "4f", "dc", "22", "2a", "90", "88", "46", "ee", "b8", "14", "de", "5e", "0b", "db"},
  {"e0", "32", "3a", "0a", "49", "06", "24", "5c", "c2", "d3", "ac", "62", "91", "95", "e4", "79"},
  {"e7", "c8", "37", "6d", "8d", "d5", "4e", "a9", "6c", "56", "f4", "ea", "65", "7a", "ae", "08"},
  {"ba", "78", "25", "2e", "1c", "a6", "b4", "c6", "e8", "dd", "74", "1f", "4b", "bd", "8b", "8a"},
  {"70", "3e", "b5", "66", "48", "03", "f6", "0e", "61", "35", "57", "b9", "86", "c1", "1d", "9e"},
  {"e1", "f8", "98", "11", "69", "d9", "8e", "94", "9b", "1e", "87", "e9", "ce", "55", "28", "df"},
  {"8c", "a1", "89", "0d", "bf", "e6", "42", "68", "41", "99", "2d", "0f", "b0", "54", "bb", "16"}
};

std::vector<std::vector<std::string>> mixColumnMatrix = {
  {"02", "03", "01", "01"},
  {"01", "02", "03", "01"},
  {"01", "01", "02", "03"},
  {"03", "01", "01", "02"}
};


std::vector<std::vector<std::string>> subBytes (std::vector<std::vector<std::string>> state){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      std::string hex = state[i][j];

      if (hex.length() == 1){
        hex = "0" + hex;
      }
      std::string row = hex.substr(0,1);
      std::string col = hex.substr(1,1);
      int rowInt = std::stoi(row, nullptr, 16);
      int colInt = std::stoi(col, nullptr, 16);
      state[i][j] = S_Caja[rowInt][colInt];
    }
  }
  return state;
}

std::vector<std::vector<std::string>> shiftRow (std::vector<std::vector<std::string>> state){
   for (int i = 0; i < 4; i++){
    for (int j = 0; j < i; j++){
      
      state[i].push_back(state[i][0]);
      state[i].erase(state[i].begin());
    }
  }
  return state;
}


std::string hexadecimalMultiplication(std::string num1, std::string num2) {
    // Convertir los números hexadecimales a enteros
    int n1, n2;
    std::stringstream ss;
    ss << std::hex << num1;
    ss >> n1;
    ss.clear();
    ss << std::hex << num2;
    ss >> n2;

    // Realizar la multiplicación a nivel de bits
    int resultado = n1 * n2;

    // Convertir el resultado a formato hexadecimal
    std::stringstream ss2;
    ss2 << std::hex << resultado;
    std::string resultado_hex = ss2.str();

    return resultado_hex;
}

std::string hexadecimalXOR (std::string num1, std::string num2) {
    // Convertir los números hexadecimales a enteros
    int n1, n2;
    std::stringstream ss;
    ss << std::hex << num1;
    ss >> n1;
    ss.clear();
    ss << std::hex << num2;
    ss >> n2;

    // Realizar la multiplicación a nivel de bits
    int resultado = n1 ^ n2;

    // Convertir el resultado a formato hexadecimal
    std::stringstream ss2;
    ss2 << std::hex << resultado;
    std::string resultado_hex = ss2.str();

    return resultado_hex;
}

std::string hexadecimalMultOutOverflow( std::string a, std::string b ) {

    std::string result1;
    std::string result2;

    if (a == "01"){
        return b;
    } 
    else if(a == "02"){
        result1 = hexadecimalMultiplication(a, b);
        if (result1.length() == 3){
            result1 = hexadecimalXOR(result1, "1b");
            result1.erase(0,1);
            return result1;
        }
        else {
            return result1;
        }
    }

    else if ( a == "03") {
       result1 = hexadecimalMultiplication("02", b);
        if (result1.length() == 3){
            result1 = hexadecimalXOR(result1, "1b");
            result1.erase(0,1);
            result1 = hexadecimalXOR(result1, b);
            return result1;
        }
        else{
            result1 = hexadecimalXOR(result1, b);
            return result1;
        }
    }
    else {
        return "00";
    }
}


std::vector<std::vector<std::string>> mixColumns (std::vector<std::vector<std::string>> state, std::vector<std::vector<std::string>> mixColumnMatrix){
std::vector<std::vector<std::string>> result (4, std::vector<std::string>(4)) ;

int x = 0;
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::string aux = "";
        for (int k = 0; k < 4; k++) {
            std::string a = state[k][j];
            std::string b = mixColumnMatrix[i][k];
            std::string c = hexadecimalMultOutOverflow(b, a);
            if (aux == ""){
                aux = c;
            }
            else{
                aux = hexadecimalXOR(aux, c);
            }
        }
        result[i][j] = aux;
    }
  }
 return result;
}


std::vector<std::vector<std::string>> addRoundKey (std::vector<std::vector<std::string>> state, std::vector<std::vector<std::string>> key){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      state[j][i] = hexadecimalXOR(state[j][i], key[j][i]);
    }
  }
  return state;
}


std::vector<std::vector<std::string>> StepKey ( std::vector<std::vector<std::string>> keyold, std::vector<std::string> rcon){

  std::vector<std::vector<std::string>> keyoldaux (4, std::vector<std::string>(4));
  std::vector<std::vector<std::string>> keyaux (4, std::vector<std::string>(4));
  std::vector<std::vector<std::string>> keynew (4, std::vector<std::string>(4));

  for (int i = 0; i < 4; i++){ 
    if (i == 0){
      //rotword
      keyoldaux = subBytes(keyold);
      std::vector<std::string> aux;  
      aux.push_back(keyoldaux[1][3]);
      aux.push_back(keyoldaux[2][3]);
      aux.push_back(keyoldaux[3][3]);
      aux.push_back(keyoldaux[0][3]);

      for (int j = 0; j < 4; j++) {
        keyaux[j][0] = hexadecimalXOR(keyold[j][0], hexadecimalXOR(aux[j], rcon[j]));    
      }      
      keynew = keyaux;
    }

    for (int j = 1; j < 4; j++) {
       for (int k = 0; k < 4; k++) {
          keynew[k][j] = hexadecimalXOR(keyold[k][j], keynew[k][j-1]);
       }
    }
  }
  return keynew;
}


std::vector<std::vector<std::vector<std::string>>> KeySchedules (std::vector<std::vector<std::string>> key){

  std::vector<std::vector<std::vector<std::string>>> keySchedule;

  keySchedule.push_back(key);

  for (int i = 1; i < 11; i++)
  {
    keySchedule.push_back(StepKey(keySchedule[i-1], Rcon[i-1]));
  }
  return keySchedule;
}

std::vector<std::vector<std::string>> AES (std::vector<std::vector<std::string>> state,std::vector<std::vector<std::vector<std::string>>> key){
  
  std::cout << "Ronda 0" << std::endl;
  state = addRoundKey(state, key[0]);

  printMatrix(state);

  int j = 1;
  for (int i = 1; i < 10; i++){
    std::cout << "Ronda " << j << std::endl;
    state = subBytes(state);
    state = shiftRow(state);
    state = mixColumns(state, mixColumnMatrix);
    state = addRoundKey(state, key[i]);
    printMatrix(state);
    

    j++;
  }
  std::cout << "Ronda " << 10 << std::endl;
  state = subBytes(state);
  state = shiftRow(state);
  state = addRoundKey(state, key[10]);

  return state;
}


void printMatrix(std::vector<std::vector<std::string>> state){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      std::cout << state[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}



void pr5 () {

  std::cout << "Bienvenido al programa de cifrado AES" << std::endl;

  std::vector<std::vector<std::string>> key = {
    {"00", "04", "08", "0c"},
    {"01", "05", "09", "0d"},
    {"02", "06", "0a", "0e"},
    {"03", "07", "0b", "0f"}
  };
  int bloque = 1;
  std::cout << "Introduzca la clave de cifrado(0): o use la por defecto " << std::endl;

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

  std::cout << "Introduzca el bloque de texto(0): o use la por defecto" << std::endl;

  std::cin >> clave;
  
  std::vector<std::vector<std::string>> state = {
    {"00", "44", "88", "cc"},
    {"11", "55", "99", "dd"},
    {"22", "66", "aa", "ee"},
    {"33", "77", "bb", "ff"}
  };
  if (clave == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto es: " << std::endl;

  printMatrix(state);

  std::vector<std::vector<std::vector<std::string>>> keySchedule = KeySchedules(key);

  std::cout << "El bloque de texto cifrado es: " << std::endl;

  std::vector<std::vector<std::string>> stateCifrado = AES(state, keySchedule);

  printMatrix(stateCifrado);

  std::cout << "Las claves son: " << std::endl;

  for (int i = 0; i < keySchedule.size(); i++) {
    std::cout << "Clave " << i << std::endl;
    printMatrix(keySchedule[i]);
  }
  


}

#endif