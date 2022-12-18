#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <vector>
#include "carta.h"

using namespace std;
class Jogador
{
public:
    Jogador();                        // Construtor
    void criaJogador(string nome);    //
    void adicionarCarta(Carta carta); // Adiciona uma carta à mão do jogador
    void removerCarta(Carta carta);   // Remove uma carta da mão do jogador
    string mostrarMao();              // Imprime a mão do jogador na tela e retorna a mão como string
    int tamanhoMao();                 // Retorna o tamanho da mão do jogador
    string getNome();
    void escolherCarta(Carta carta);
    void limpaCartaJogada();
    Carta getCartaJogada();
    bool temCarta(Carta carta); // Verifica se o jogador tem a carta
    void setPontoRodada(int ponto);
    void setPontoJogo(int ponto);
    int getPontoRodada();
    int getPontoJogo();
    void limpaMao();

private:
    string nome; // Nome do jogador
    string cartaJogada;
    vector<Carta> mao; // Lista de cartas na mão do jogador
    int ptsRodada;
    int ptsJogo;
};
#endif