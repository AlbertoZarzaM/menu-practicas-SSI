#ifndef RSA_H
#define RSA_H


#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

std::vector<long long int> splitString8(std::string input) {
    std::vector<long long int> values;
    std::stringstream ss(input);
    long long int temp;
    while (ss >> temp) {
        values.push_back(temp);
    }
    return values;
}

long long int exponenciacionRapida8(long long int a, long long int b, int n) {
    
  long long int x = 1;
  long long int y = a % n;
    while ((b > 0) && (y > 1)) {
        if (b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b = b / 2;
    }
    return x % n;
}

std::string encode8(std::string text, int j) {
    //eliminar espacios de text
    text.erase(std::remove_if(text.begin(), text.end(), [](char c) { return std::isspace(c); }), text.end());
    std::string encoded = "";
    long int block_size = j;
    long int num_blocks = ceil((double)text.length() / (double)block_size);
    long int padding = block_size - text.length() % block_size;
    
    // Add padding X's if necessary
    if (padding != block_size) {
        for (int i = 0; i < padding; i++) {
            text += 'X';
        }
    }
    
    // Encode each block of the text
    for (int i = 0; i < num_blocks; i++) {
        long int block_value = 0;
        for (int j = 0; j < block_size; j++) {
            char c = text[i*block_size+j];
            long int char_value = c - 'A';
            block_value += char_value * pow(26, block_size-j-1);
        }
        encoded += std::to_string(block_value) + " ";
    }
    
    return encoded;
}


//comprobar son números primos (con el test de Lehman-Peralta)

bool isPrimeLehmanPeralta8(long long int p) {
 
    // Comprobar que p no es divisible por ningún primo pequeño
    if (p == 2 || p == 3 || p == 5 || p == 7 || p == 11) {
        return true;
    } 
    else if ( p % 2 == 0 || p % 3 == 0 || p % 5 == 0 || p % 7 == 0 || p % 11 == 0) {
            return false;
    }

    else {
        // Elegir enteros aleatorios ai entre 2 y p-1
        srand(time(NULL));
        for (int i = 0; i < 50; i++) {
            long long a = 2 + rand() % (p - 2);

            // Si ai (P-1)/2 != 1 (mod p), p es compuesto
            long long exp = (p - 1) / 2;
            long long result = exponenciacionRapida8(a, exp, p);
            if (result != 1 && result != p - 1) {
                return false;
            }

            // Si ai (p-1)/24-1 (mod p), p es compuesto
            exp = (p - 1) / 24;
            result = exponenciacionRapida8(a, exp, p);
            if (result == p - 1) {
                return true;
            }
        }

        // Si no se encontró ningún i tal que ai (p-1)/24-1 (mod p), p tal vez es primo
        return true;
    }
}

int gcdExtended8(int a, int b, long int &x, long int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long int x1, y1;

    long int gcd = gcdExtended8(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;

    std::cout << "x: " << x << " y: " << y << std::endl;

    return gcd;
}

long int euclides_extendido8(long int a, long int b) {
  //std::cout << "a: " << a << " b: " << b << std::endl;  
  std::vector<long int> x = {0,a, b};
  std::vector<long int> z = {0,1};

  int i = 2;
  std::cout << std::endl;
  while (x[i-1] % x[i] != 0) {
    long int z_aux = 0;
   // std::cout << "x[i-1] % x[i]: " << x[i-1] % x[i] << std::endl; 
    x.push_back(x[i-1] % x[i]);
    // int q = x[i-1] / x[i];
    long int div = -((x[i-1] / x[i]));
    z_aux = div * z[i-1] + z[i-2];
    z_aux = z_aux % a;
    if (z_aux < 0) {
      z_aux = z_aux + a;
    }
   // std::cout << "z_aux: " << z_aux << std::endl;
    z.push_back(z_aux);
    i++;
  }
  std::cout << std::endl;
  if (x[i] == 1) {
    return z[i-1];
  } else {
    std::cout << "No existe inverso" << std::endl;
    return -1;
  }
}

bool is_d_coprime8(long int p, long int q, long int d) {
    long int phi = (p-1)*(q-1);
    // long int x, y;
    long int gcd = euclides_extendido8(phi, d);
    return (gcd == 1);
}


long long int encrypt8(long long int m, int e, int n) {
    return exponenciacionRapida8(m, e, n);
}


void pr8() {
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

    if (isPrimeLehmanPeralta8(p) && isPrimeLehmanPeralta8(q)) {
        std::cout << "p y q son primos" << std::endl;
    } else {
        std::cout << "p y q no son primos" << std::endl;
    }



    //• Se calcula e
    // e = inverso de d módulo φ(n)
    //int e;
    long int x, y;
   // std::cout << "phi1: " << phi << " d1: " << d << std::endl;
    long int gcd = euclides_extendido8(phi, d);

    //Se comprueba que d es primo con phi(n)
    if (gcd != -1) {
        std::cout << "d es primo con phi(n)" << std::endl;
    } else {
        std::cout << "d no es primo con phi(n)" << std::endl;
    }
    
    std::cout << "e = " << gcd << std::endl;

    //Se busca el valor de j 26^j-1<n<26^j

    int j = std::ceil(std::log(n+1)/std::log(26));
    std::cout << "j = " << j << std::endl;

    //Se pasa cada bloque a decimal para poder cifrar

    std::string encoded_text = encode8(original_text, j-1);

    std::cout << encoded_text << std::endl;


    //Se calcula en decimal el texto cifrado
    std::vector<long long int> encoded_text_vector = splitString8(encoded_text);

    for (int i = 0; i < encoded_text_vector.size(); i++) {
        std::cout << encrypt8(encoded_text_vector.at(i), gcd, n)<< " ";
    }


    
}

#endif /* RSA_H */