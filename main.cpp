#include <iostream>
#include "jogador.h"
#include "jogo.h"

int main()
{
    int continuarJogando = 1;
    while (continuarJogando)
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

        cout << endl
             << "O jogo acabou, voce gostaria de continuar jogando?" << endl;
        cout << "Digite 'ok' para continuar, ou digite qualquer outra coisa para finalizar" << endl;
        string opcao;
        cout << "Jogador: ";
        cin >> opcao;
        if (opcao != "ok")
        {
            continuarJogando = 0;
        }
    }
    cout << "Jogo finalizado! Obrigado por jogar." << endl;
    return 0;
}
