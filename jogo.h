#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include <vector>
#include "carta.h"
#include "jogador.h"
#include "baralho.h"

using namespace std;
class Jogo
{
public:
    Jogo(Jogador jogador1, Jogador jogador2); // Construtor
    void iniciar();    // Inicia o jogo
    void darCartas(); // Distribui as cartas
    void novaRodada(); // Inicia uma nova rodada
    void jogarCarta(Carta carta); // Faz a ação de jogar uma carta
    void truco(); // Faz a ação do Truco
    void desistir(); // Faz a ação Desistir
    void placar(); // Imprime o placar
    void verificarVencedor(); // Verifica o vencedor da rodada atual
    void trocaTurno();        // Troca o turno, é a vez do outro jogador de jogar
    bool fimJogo();           // Verifica se o jogo chegou ao fim
    Jogador *getJogador1(); // Retorna ponteiro do Jogador 1
    Jogador *getJogador2(); // Retorna ponteiro do Jogador 2

private:
    Jogador jogador1;      // Primeiro jogador
    Jogador jogador2;      // Segundo jogador
    Jogador *jogadorDoTurno; // Ponteiro para o jogador do turno (que vai jogar/fazer ação)
    Jogador *proximoJogador; // Ponteiro para o próximo jogador
    Jogador *venceu1Rodada; // Jogador que venceu a primeira rodada
    Baralho baralho; // Baralho de cartas
    int valorRodada; // Quantos pontos a rodada vale
    bool fimRodada; // Se a rodada finalizou
};
#endif