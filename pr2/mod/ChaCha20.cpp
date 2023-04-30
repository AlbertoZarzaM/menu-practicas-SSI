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

#include "ChaCha20.h"

uint32_t ROTL (uint32_t& x, int y) {
   uint32_t resultado;
   resultado = (x << y) | (x >> (32 - y));
   return resultado;
}
void QR(uint32_t& a, uint32_t& b, uint32_t& c, uint32_t& d) {
    a += b, d ^= a, d = ROTL(d, 16);
    c += d, b ^= c, b = ROTL(b, 12);
    a += b, d ^= a, d = ROTL(d, 8);
    c += d, b ^= c, b = ROTL(b, 7);
}

void chachablock (std::vector <uint32_t> const& in, std::vector <uint32_t>& out) {
    std::vector <uint32_t> x(16);
    for (int i = 0; i < 16; ++i) {
        x[i] = in[i];
    }
    for (int i = 0; i < ROUNDS; i += 2) {    
        QR(x[0], x[4], x[8], x[12]);
        QR(x[1], x[5], x[9], x[13]);
        QR(x[2], x[6], x[10], x[14]);
        QR(x[3], x[7], x[11], x[15]);
      
        QR(x[0], x[5], x[10], x[15]);
        QR(x[1], x[6], x[11], x[12]);
        QR(x[2], x[7], x[8], x[13]);
        QR(x[3], x[4], x[9], x[14]);
    }
    std::cout << std::endl;
    std::cout << "Estado final tras las 20 iteraciones="<< std::endl;
    for (int i = 0; i < x.size(); ++i) {
        if(i == 0 || i == 4 || i == 8 || i == 12 ){
            std::cout << std::endl;
        }
        std::cout << std::hex << x[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 16; ++i) {
        out[i] = x[i] + in[i];
    }
}

uint32_t tolittleendian(uint32_t& x) {
    uint32_t resultado;
    resultado = (x << 24) | (x >> 24) | ((x << 8) & 0x00FF0000) | ((x >> 8) & 0x0000FF00);
    return resultado;
}