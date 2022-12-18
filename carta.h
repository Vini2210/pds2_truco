#ifndef CARTA_H
#define CARTA_H
#include <iostream>

using namespace std;

class Carta
{
public:
    Carta(char numero, char naipe); // Construtor
    Carta getCarta(char numero, char naipe);
    string getNumero();             // Retorna o número da carta
    string getNaipe();              // Retorna o naipe da carta
    int getPonto();                 // Retorna o ponto da carta
private:
    string numero; // Número da carta
    string naipe;  // Naipe da carta
    int ponto; // Ponto da carta
};

#endif