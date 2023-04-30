/**
 * @file SSI-pr2
 * @author Alberto Zarza Martín (alu0101412993@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CHACHA2_H
#define CHACHA2_H

#include "ChaCha20.h"





void pr2() {

    //Leer archivo la clave y el nonce y guardarlo en un vector por palabras 
    std::string name_file = "";
    std::cout << "Ingrese el nombre del archivo: ";
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

};

#endif 