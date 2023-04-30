#ifndef Firmas_H
#define Firmas_H

#include "funciones.h"


void pr10() {
   std::string original_text;
    std::cout << "Introduce el texto original: ";
    std::getline(std::cin, original_text);
    std::cout << std::endl;

    long long int p;
    std::cout << "Introduce el valor de p: ";
    std::cin >> p;
    std::cout << std::endl;

    long long int q;
    std::cout << "Introduce el valor de q: ";
    std::cin >> q;
    std::cout << std::endl;

    int d;
    std::cout << "Introduce el valor de d: ";
    std::cin >> d;
    std::cout << std::endl;

    long long int n = p * q;
    long int phi = (p - 1) * (q - 1);

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "phi = " << phi << std::endl;

    //• Se comprueba que p y q son primos 

    if (isPrimeLehmanPeralta(p) && isPrimeLehmanPeralta(q)) {
        std::cout << "p y q son primos" << std::endl;
    } else {
        std::cout << "p y q no son primos" << std::endl;
    }



    //• Se calcula e
    // e = inverso de d módulo φ(n)
    //int e;
    long int x, y;
   // std::cout << "phi1: " << phi << " d1: " << d << std::endl;
    long int gcd = euclides_extendido(phi, d);

    //Se comprueba que d es primo con phi(n)
    if (gcd != -1) {
        std::cout << "Ea es primo con phi(n)" << std::endl;
    } else {
        std::cout << "Ea no es primo con phi(n)" << std::endl;
    }
    
    std::cout << "Da = " << gcd << std::endl;

    //Se busca el valor de j 26^j-1<n<26^j

    int j = std::ceil(std::log(n+1)/std::log(26));
    std::cout << "j = " << j << std::endl;

    //Se pasa cada bloque a decimal para poder cifrar

    std::string encoded_text = encode(original_text, j-1);

    std::cout << encoded_text << std::endl;


    //Se calcula en decimal el texto cifrado
    std::vector<long long int> encoded_text_vector = splitString(encoded_text);

    for (int i = 0; i < encoded_text_vector.size(); i++) {
        std::cout << encrypt(encoded_text_vector.at(i), gcd, n)<< " ";
    }

    std::cout << std::endl;

    std::cout << "Verificar: " << std::endl;
    std::cout << "Texto firmado recibido por B: " << std::endl;

    long long int signed_text;

    std::cin >> signed_text;

    std::cout << "Introduce el valor de e: ";
    long long int eaux;
    std::cin >> eaux;
    std::cout << std::endl;
    std::cout << "Introduce el valor de n: ";
    long long int naux;
    std::cin >> naux;
    std::cout << std::endl;
    
    long long int signed_text_aux = encrypt(signed_text, eaux, naux);

    std::cout << "Se calcula la potencia: " << signed_text_aux << std::endl;

    std::string decode1 = std::to_string(signed_text_aux);
    int jaux = std::ceil(std::log(naux+1)/std::log(26));

    std::cout << "Se decodifica obteniendo el texto original: " << decode(decode1, jaux-1) << std::endl;

}

#endif // Firmas_H