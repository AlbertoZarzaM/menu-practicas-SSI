#ifndef DiffieHellman_H
#define DiffieHellman_H

#include <iostream>

int exponenciacionRapidaINT(int a, int b, int n) {
    int x = 1;
    int y = a % n;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b = b / 2;
    }
    return x % n;
}

bool isPrime(int n) {

    if (n == 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int diffieHellman(int g, int p, int a, int b) {
    int A = exponenciacionRapidaINT(g, a, p);
    int B = exponenciacionRapidaINT(g, b, p);
    

    std::cout << "El valor de Ya es: " << A << std::endl;
    std::cout << "El valor de Yb es: " << B << std::endl;

    int s1 = exponenciacionRapidaINT(A, b, p);

    int s2 = exponenciacionRapidaINT(B, a, p);


    std::cout << "El valor de la llave compartida es: " << s1 << std::endl;
    std::cout << "El valor de la llave compartida es: " << s2 << std::endl;

    if (s1 == s2) {
        std::cout << "Las llaves son iguales" << std::endl;
    } else {
        std::cout << "Las llaves son diferentes" << std::endl;
    }
    return s1;
}

void pr7() {
  std::cout << "Bienvenido al programa de Diffie-Hellman" << std::endl;

  int p, a, b, g;
  std::cout << "Ingrese el valor del primo p: " << std::endl;
  std::cin >> p;
  
  if (!isPrime(p)) {
      std::cout << "El valor ingresado no es primo" << std::endl;
  }
  

  std::cout << "Ingrese el valor del alfa: " << std::endl;
  std::cin >> g;
  std::cout << "Ingrese el valor del secreto a: " << std::endl;
  std::cin >> a;
  std::cout << "Ingrese el valor del secreto b: " << std::endl;
  std::cin >> b;

  std::cout << "El valor de la llave compartida es:\n " << diffieHellman(g, p, a, b) << std::endl;
}

#endif