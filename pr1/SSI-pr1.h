#ifndef C_H
#define C_H


/**
 * @file SSI-pr1 
 * @author Alberto Zarza Martín (alu0101412993@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string vigenere_cifrado(std::vector<char> alfabeto, string texto, string clave) {
  int n = texto.length();
  int m = clave.length();
  string cifrado = "";
  
  //buscar en el alfabeto la posición de la letra del texto
  for (int i = 0; i < n; i++) {
    int pos_texto = find(alfabeto.begin(), alfabeto.end(), texto[i]) - alfabeto.begin(); //posición de la letra en el alfabeto    
    int pos_clave = find(alfabeto.begin(), alfabeto.end(), clave[i % m]) - alfabeto.begin(); //buscar en el alfabeto la posición de la letra de la clave
    cifrado += alfabeto[(pos_texto + pos_clave) % alfabeto.size()]; //sumar posiciones y obtener el módulo del tamaño del alfabeto
  }


  return cifrado;
}

string vigenere_descifrado(std::vector<char> alfabeto, std::string cifrado, std::string clave) {
  int n = cifrado.length();
  int m = clave.length();
  string texto = "";

  //buscar en el alfabeto la posición de la letra del texto
  for (int i = 0; i < n; i++) {
    int pos_cifrado = find(alfabeto.begin(), alfabeto.end(), cifrado[i]) - alfabeto.begin(); //posición de la letra en el alfabeto
    int pos_clave = find(alfabeto.begin(), alfabeto.end(), clave[i % m]) - alfabeto.begin(); //buscar en el alfabeto la posición de la letra de la clave
    texto += alfabeto[(pos_cifrado - pos_clave + alfabeto.size()) % alfabeto.size()]; //restar posiciones y obtener el módulo del tamaño del alfabeto
  }

  return texto;
}




void pr1() {

   std::vector<char> alfabeto = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  
  // dos modos cifrar y descifrar
  int modo;
  cout << "Introduzca el modo de cifrado (1 para cifrar, 2 para descifrar): ";

  cin >> modo;

  string texto ;
  string clave ;

  if (modo == 1) {
    cout << "Introduzca el texto a cifrar: ";
    getline(cin >> ws, texto);

    cout << "Introduzca la clave: ";
    cin >> clave;

    //Eliminar espacios de texto
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());
    


    int n = texto.length();
    int m = clave.length();
    int num_bloques = n / m;
    if (n % m != 0) {
      num_bloques++;
    }

    string bloques[num_bloques];
    for (int i = 0; i < num_bloques; i++) {
      bloques[i] = texto.substr(i * m, m);
    }

    //imprimir bloques
    for (int i = 0; i < num_bloques; i++) {
      cout << "Bloque " << i + 1 << ": " << bloques[i] << endl;
    }
    //cifrar bloque a bloque
    string cifrado = "";
    for (int i = 0; i < num_bloques; i++) {
      cifrado += vigenere_cifrado(alfabeto, bloques[i], clave);
    }
    cout << "Texto cifrado: " << cifrado << endl;
  } 
  
  else if (modo == 2) {
    cout << "Introduzca el texto a descifrar: ";
    getline(cin >> ws, texto);
    cout << "Introduzca la clave: ";
    cin >> clave;
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());
    string descifrado = vigenere_descifrado(alfabeto, texto, clave);
    cout << "Texto descifrado: " << descifrado << endl;
  } 
  else {
    cout << "Modo incorrecto" << endl;
  }

}

#endif  // CHACHA20_H