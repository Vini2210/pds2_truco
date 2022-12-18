#include <iostream>
#include <vector>
#include <algorithm> // para usar o shuffle
#include <random>    // para usar o mt19937 e o uniform_int_distribution
#include <chrono>    // para usar o time_point_cast
#include "baralho.h"

using namespace std;

// Inicializa o baralho com todas as cartas do jogo
Baralho::Baralho()
{
    cartas = {Carta('3', 'C'), Carta('3', 'E'), Carta('3', 'O'), Carta('3', 'P'),
              Carta('2', 'C'), Carta('2', 'E'), Carta('2', 'O'), Carta('2', 'P'),
              Carta('A', 'C'), Carta('A', 'E'), Carta('A', 'O'), Carta('A', 'P'),
              Carta('K', 'C'), Carta('K', 'E'), Carta('K', 'O'), Carta('K', 'P'),
              Carta('J', 'C'), Carta('J', 'E'), Carta('J', 'O'), Carta('J', 'P'),
              Carta('Q', 'C'), Carta('Q', 'E'), Carta('Q', 'O'), Carta('Q', 'P'),
              Carta('7', 'C'), Carta('7', 'E'), Carta('7', 'O'), Carta('7', 'P'),
              Carta('6', 'C'), Carta('6', 'E'), Carta('6', 'O'), Carta('6', 'P'),
              Carta('5', 'C'), Carta('5', 'E'), Carta('5', 'O'), Carta('5', 'P'),
              Carta('4', 'C'), Carta('4', 'E'), Carta('4', 'O'), Carta('4', 'P')};
}

// Embaralha o baralho
void Baralho::embaralhar()
{
    int n = cartas.size();
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 39);
    // Embaralha as cartas no baralho usando o método de Fisher-Yates
    for (int i = 0; i < n - 1; i++)
    {
        int j = dist(mt);
        swap(cartas[i], cartas[j]);
    }
}

// Adiciona uma carta no baralho
void Baralho::adicionarCarta(Carta carta)
{
    // Adiciona a carta ao final do baralho
    cartas.push_back(carta);
}

// Retira uma carta do topo do baralho
Carta Baralho::retirarCarta()
{
    // Verifica se o baralho está vazio
    if (estaVazio())
    {
        // Retorna uma carta vazia se o baralho estiver vazio
        return Carta(' ', ' ');
    }

    // Retira a última carta do baralho
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

// Retorna se o baralho está vazio
bool Baralho::estaVazio()
{
    // Verifica se o baralho está vazio usando a função empty do vector
    return cartas.empty();
}

// Retorna o tamanho do baralho
int Baralho::tamanho()
{
    // Retorna o tamanho do baralho usando a função size do vector
    return cartas.size();
}