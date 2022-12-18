#include <iostream>
#include <vector>
#include "carta.h"
#include "jogador.h"

using namespace std;

Jogador::Jogador()
{
    this->nome = "";
}

void Jogador::criaJogador(string nome)
{
    // Inicializa o jogador com o seu nome
    this->nome = nome;
    this->ptsJogo = 0;
    this->ptsRodada = 0;
}

void Jogador::adicionarCarta(Carta carta)
{
    // Adiciona a carta à mão do jogador
    mao.push_back(carta);
}

void Jogador::removerCarta(Carta carta)
{
    for (int i = 0; i < mao.size(); i++)
    {
        if (carta.getNumero() == mao[i].getNumero() && carta.getNaipe() == mao[i].getNaipe())
        {
            mao.erase(mao.begin() + i);
        }
    }
}

void Jogador::escolherCarta(Carta carta)
{
    string cartaJogada = "";
    this->cartaJogada += carta.getNumero() + carta.getNaipe();
    removerCarta(carta);
}

void Jogador::limpaCartaJogada()
{
    this->cartaJogada = "";
}

string Jogador::mostrarMao()
{
    // Converte a lista de cartas na mão do jogador para uma string
    string maoStr = "";
    for (Carta carta : mao)
    {
        maoStr += carta.getNumero() + carta.getNaipe() + " ";
    }
    return maoStr;
}

string Jogador::getNome()
{
    return this->nome;
}

Carta Jogador::getCartaJogada()
{

    if (cartaJogada == "")
        return Carta(' ', ' ');
    Carta carta(cartaJogada[0], cartaJogada[1]);
    return carta;
}

// Retorna true se o jogador tiver a carta na mao, false se nao tiver
bool Jogador::temCarta(Carta carta){
    for (Carta cartas : mao){
        if (cartas.getNumero() == carta.getNumero() && cartas.getNaipe() == carta.getNaipe())
            return true;
    }
    return false;
}

void Jogador::setPontoJogo(int ponto){
    this->ptsJogo = ponto;
}

void Jogador::setPontoRodada(int ponto){
    this->ptsRodada = ponto;
}

int Jogador::getPontoJogo(){
    return this->ptsJogo;
}

int Jogador::getPontoRodada(){
    return ptsRodada;
}

void Jogador::limpaMao(){
    mao.clear();
}