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


#include "ChaCha20.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>





int main() {

    //Leer archivo la clave y el nonce y guardarlo en un vector por palabras 
    std::string name_file = "";
    std::cout << "Ingrese el nombre del archivo que contiene la secuencia de entrada: ";
    std::cin >> name_file;

    std::ifstream file(name_file);
    std::string str = "";
    std::vector<std::string> key = {};
    //Leer el archivo linea por linea y guardar cada linea en un vector
    while (std::getline(file, str)){ 
        key.push_back(str);
    }
    file.close();
    //Imprimir el vector
    std::stringstream aux;
    std::vector<uint32_t> key_int(16);

    for (int i = 0; i < key.size(); ++i) {
        aux << std::hex << key[i];
        aux >> key_int[i];
        aux.clear();
    }
    
    for (int i = 4; i < key_int.size(); ++i) {
        
       key_int[i] = tolittleendian(key_int[i]);
        
        
    }

    std::cout << "Estado inicial= " << std::endl;
    for (int i = 0; i < key_int.size(); ++i) {
        if(i == 0 || i == 4 || i == 8 || i == 12 ){
            std::cout << std::endl;
        }
        std::cout << std::hex << key_int[i] << " ";
    }
    std::cout << std::endl;
    
    
  
    std::vector <uint32_t> out(16);
   
    chachablock(key_int, out);

    std::cout << std::endl;

    
    std::cout << "Estado de salida del generador="<< std::endl;

    for (int i = 0; i < out.size(); ++i) {
        if(i == 0 || i == 4 || i == 8 || i == 12 ){
            std::cout << std::endl;
        }
        std::cout << std::hex << out[i] << " ";
    }
   std::cout << std::endl;

   // hacer una xor bit a bit con el mensaje y el estado de salida del generador
    std::string name_file2 = "";
    std::cout << "Ingrese el nombre del archivo que contiene el mensaje: ";
    std::cin >> name_file2;

    std::ifstream file2(name_file2);
    std::string str2 = "";
    std::vector<std::string> message = {};

    while (std::getline(file2, str2)) {
        message.push_back(str2);
    }
    file2.close();

    std::stringstream aux2;
    std::vector<uint32_t> message_int(16);


    for (int i = 0; i < message.size(); ++i) {
        aux2 << std::hex << message[i];
        aux2 >> message_int[i];
        aux2.clear();
    }

    std::cout << "Mensaje= " << std::endl;
    for (int i = 0; i < message_int.size(); ++i) {
        if (i == 0 || i == 4 || i == 8 || i == 12) {
            std::cout << std::endl;
        }
        std::cout << std::hex << message_int[i] << " ";
    }
    std::cout << std::endl;

    std::vector<uint32_t> xor_message(16);

    for (int i = 0; i < message_int.size(); ++i) {
        xor_message[i] = message_int[i] ^ out[i];
    }

    std::cout << "Mensaje cifrado/descifrdo= " << std::endl;
    for (int i = 0; i < xor_message.size(); ++i) {
        if (i == 0 || i == 4 || i == 8 || i == 12) {
            std::cout << std::endl;
        }
        std::cout << std::hex << xor_message[i] << " ";
    }
    std::cout << std::endl;

    return 0;




};