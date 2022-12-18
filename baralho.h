#ifndef BARALHO_H
#define BARALHO_H
#include <iostream>
#include <vector>
#include "carta.h"

using namespace std;
class Baralho
{
public:
    Baralho();                        // Construtor
    void embaralhar();                // Embaralha as cartas do baralho
    void adicionarCarta(Carta carta); // Adiciona uma carta ao baralho
    Carta retirarCarta();             // Retira uma carta do baralho
    bool estaVazio();                 // Verifica se o baralho está vazio
    int tamanho();                    // Retorna o tamanho do baralho

private:
    vector<Carta> cartas; // Lista de cartas no baralho
};

#endif