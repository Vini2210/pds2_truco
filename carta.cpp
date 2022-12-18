#include <iostream>
#include "carta.h"

Carta::Carta(char numero, char naipe)
{
    // Inicializa o número e o naipe da carta
    this->numero = numero;
    this->naipe = naipe;
}

// Recebe um numero e um naipe e retorna uma carta
Carta Carta::getCarta(char numero, char naipe){
    Carta carta(numero, naipe);
    return carta;
}

// Retorna o número da carta
string Carta::getNumero()
{
    return numero;
}

// Retorna o naipe da carta
string Carta::getNaipe()
{
    return naipe;
}

// Retorna quantos pontos a carta vale
int Carta::getPonto()
{
    // Sequencia das cartas da mais fraca para a mais forte
    string sequencia[11] = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};
    for (int i = 0; i < 10; i++)
    {
        // Procura a carta no vetor da sequencia
        if (sequencia[i] == this->getNumero())
        {
            // Se achou, verifica se é manilha
            if (this->getNumero() == "4" && this->getNaipe() == "P")
                return 13;

            if (this->getNumero() == "7" && this->getNaipe() == "C")
                return 12;

            if (this->getNumero() == "A" && this->getNaipe() == "E")
                return 11;

            if (this->getNumero() == "7" && this->getNaipe() == "O")
                return 10;

            // Se chegar até aqui, é por que não é uma manilha, retorna a posicao
            return i;
        }
    }
    return 0;
}