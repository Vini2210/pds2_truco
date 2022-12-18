#include <iostream>
#include "jogador.h"
#include "jogo.h"

int main()
{
    // Inicaliza os jogadores
    Jogador jogador1;
    Jogador jogador2;

    // Cria os jogadores
    jogador1.criaJogador("Jogador 1");
    jogador2.criaJogador("Jogador 2");

    // Inicializa o jogo com os jogadores
    Jogo jogo(jogador1, jogador2);

    // Inicia o jogo
    jogo.iniciar();

    // Enquanto alguem nao pontuar 12 ou mais pontos, continua
    while (jogo.fimJogo() == false)
        jogo.novaRodada();
    return 0;
}