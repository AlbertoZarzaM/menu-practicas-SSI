#ifndef ELG_H
#define ELG_H

#include "funcionesELG.h"


void pr9() {
   

    long int p = 0;
    long int a = 0;
    long int b = 0;
    long int Gx = 0;
    long int Gy = 0;
    long int dA = 0;
    long int dB = 0;
    long int message = 0;


    std::cout << "Introduce p: ";
    std::cin >> p;
    std::cout << "Introduce a: ";
    std::cin >> a;
    std::cout << "Introduce b: ";
    std::cin >> b;
    std::cout << "Introduce Gx: ";
    std::cin >> Gx;
    std::cout << "Introduce Gy: ";
    std::cin >> Gy;
    std::cout << "Introduce dA: ";
    std::cin >> dA;
    std::cout << "Introduce dB: ";
    std::cin >> dB;
    std::cout << "Introduce message: ";
    std::cin >> message;

    //Calamos puntos de la curva
    std::vector<std::pair<int, int>> puntos = calcularPuntosCurva(p, a, b);

    //los puntos de la curva son:
    std::cout << "Los puntos de la curva son: " << std::endl;
    for (int i = 0; i < puntos.size(); i++) {
        std::cout << "(" << puntos[i].first << ", " << puntos[i].second << ")" << std::endl;
    }

    //suma de puntos B

    std::pair<int, int> puntoB = calcularMultiplicacionPunto(std::make_pair(Gx, Gy), dB, p, a);

    std::cout << "El punto B es: (" << puntoB.first << ", " << puntoB.second << ")" << std::endl;

    //suma de puntos A 

    std::pair<int, int> puntoA = calcularMultiplicacionPunto(std::make_pair(Gx, Gy), dA, p, a);

    std::cout << "El punto A es: (" << puntoA.first << ", " << puntoA.second << ")" << std::endl;

    //Clave secreta A

    std::pair<int, int> claveA = calcularMultiplicacionPunto(puntoB, dA, p, a);

    std::cout << "La clave secreta A es: (" << claveA.first << ", " << claveA.second << ")" << std::endl;

    //Clave secreta B

    std::pair<int, int> claveB = calcularMultiplicacionPunto(puntoA, dB, p, a);

    std::cout << "La clave secreta B es: (" << claveB.first << ", " << claveB.second << ")" << std::endl;

    //Calculo de M

    int M = calculoM(message);

    std::cout << "M es: " << M << std::endl;

    //Calculo de H

    int H = escogerH(p, M);

    std::cout << "H es: " << H << std::endl;

    //Codificar punto de la curva

    std::pair<int, int> puntoCodificado = codificarPuntoCurva(message, H, puntos);

    std::cout << "El punto codificado es: (" << puntoCodificado.first << ", " << puntoCodificado.second << ")" << std::endl;

    //mensaje codificado

    std::pair<int, int> mensajeCodificado = calcularPuntoSuma(puntoCodificado, claveB, p, a);


    std::cout << "El mensaje codificado es: (" << mensajeCodificado.first << ", " << mensajeCodificado.second << ")  " ;
    //clave publica
    std::cout << "La clave publica es: (" << puntoA.first << ", " << puntoA.second << ")" << std::endl;



}

#endif // !ELG_H