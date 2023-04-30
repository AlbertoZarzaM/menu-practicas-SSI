#ifndef FUNCIONESELG_H
#define FUNCIONESELG_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <utility>
//#include "funciones.h"

std::vector<std::pair<int, int>> calcularPuntosCurva(int p, int a, int b) {
    std::vector<std::pair<int, int>> puntos;
    for (int x = 0; x < p; x++) {
        for (int y = 0; y < p; y++) {
            int lhs = std::pow(y, 2.0);
            int rhs = std::pow(x, 3.0)+ (a*x) + b;
            if (lhs % p == rhs % p) {
                puntos.push_back(std::make_pair(x, y));
            }
        }
    }
    return puntos;
}

int modulo(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}


int gcdExtended(int a, int b, int* x, int* y) {
  // Caso base
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  // Variables para guardar los valores de x1 e y1
  int x1, y1;
  // Recursión para obtener el valor de x1 e y1
  int gcd = gcdExtended(b%a, a, &x1, &y1);
  // Actualización de los valores de x e y
  *x = y1 - (b/a) * x1;
  *y = x1;
  // Retornar el gcd
  return gcd;
}

// Función para obtener el inverso modular de un número
int modInverse(int a, int m) {
  int x, y;
  int gcd = gcdExtended(a, m, &x, &y);
  if (gcd != 1) {
    std::cout << "No se puede obtener el inverso modular." << std::endl;
    return -1;
  }
  else {
    // Hacer el resultado positivo
    int result = (x % m + m) % m;
    return result;
  }
}

std::pair<int, int> calcularPuntoSuma(std::pair<int, int> p1, std::pair<int, int> p2, int p, int a) {


    

    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    x1 = p1.first;
    y1 = p1.second;
    x2 = p2.first;
    y2 = p2.second;


    std::cout << "p1: " << x1 << ", " << y1 << std::endl;
    std::cout << "p2: " << x2 << ", " << y2 << std::endl;


    int lambda = 0;
    int x3, y3;

    if (x1 == x2 && y1 == y2) {
        int denominator = (2 * y1);
        int numerator = (3 * std::pow(x1, 2.0) + a);
        if (numerator % denominator != 0) {
            // euclide extendido
           lambda = numerator * modInverse(denominator, p);
           lambda = modulo(lambda, p);
        } else {
            lambda = (numerator / denominator);
            lambda = modulo(lambda, p);
        }


    } else {
        
        int denominator = (x2 - x1);
        int numerator = (y2 - y1);
        if (x2 - x1 < 0) {
            denominator = (x1 - x2);
            numerator = (y1 - y2);
        }        
        if (numerator % denominator != 0 || denominator == 0) {
    
           lambda = numerator * modInverse(denominator, p);
                  std:: cout << "jlsfau: "  << std::endl;
    
           lambda = modulo(lambda, p);
        } else {
            lambda = (numerator / denominator);
            lambda = modulo(lambda, p);
        }

    }

    x3 = std::pow(lambda, 2.0) - x1 - x2;
    y3 = lambda * (x1 - x3) - y1;

    x3 = modulo(x3, p);
    y3 = modulo(y3, p);
    
    return std::make_pair(x3, y3);
}


int calculoM (int m){
    // M tiene que potencia de dos mayor a m

    int M = 2 * pow(2, floor(log2((m-1)/2)+1)); // cálculo de M
    return M;   
}

int escogerH (int p, int M) {
    int H = p/M;
    return H;
}




std::pair<int, int> buscarPunto(int x, std::vector<std::pair<int, int>> puntos) {
    for (int i = 0; i < puntos.size(); i++) {
        if (puntos[i].first == x) {
            return puntos[i];
        }
    }
    return std::make_pair(-1, -1);
}

std::pair <int, int> codificarPuntoCurva(int m, int h, std::vector<std::pair<int, int>> puntos){
    int x = m*h;

    for (int i = 0; i < h; i++) {
        std::pair<int, int> punto = buscarPunto(x, puntos);
        if (punto.first != -1 && punto.second != -1) {
            return punto;
        }
        x = x + 1;
    }
    return std::make_pair(-1, -1);
}


std::pair<int, int> calcularMultiplicacionPunto(std::pair<int, int> p1, int k, int p, int a) {
    std::pair<int, int> p2 = p1;
    for (int i = 0; i < k-1; i++) {
        p2 = calcularPuntoSuma(p1, p2, p, a);
    }
    return p2;
}

#endif /* FUNCIONESELG_H */