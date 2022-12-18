#include <iostream>
#include <vector>
#include "jogo.h"

using namespace std;

// Função que distribui as cartas aos jogadores
void Jogo::darCartas()
{
    // Embaralha o baralho
    baralho.embaralhar();

    // Dá 3 cartas para cada jogador
    for (int i = 0; i < 3; i++)
    {
        jogador1.adicionarCarta(baralho.retirarCarta());
        jogador2.adicionarCarta(baralho.retirarCarta());
    }
}

// Função que inicializa o jogo com os jogadores
Jogo::Jogo(Jogador jogador1, Jogador jogador2)
{
    this->jogador1 = jogador1;
    this->jogador2 = jogador2;
    jogador1.setPontoRodada(0);
    jogador1.setPontoJogo(0);
    jogador2.setPontoRodada(0);
    jogador2.setPontoJogo(0);
    valorRodada = 1;
}

// Funçáo que inicia o jogo
void Jogo::iniciar()
{
    // Define o jogador que começa e o proximo jogador
    this->jogadorDoTurno = getJogador1();
    this->proximoJogador = getJogador2();

    this->venceu1Rodada = NULL;
}

// Função que retorna um ponteiro para o Jogador 1
Jogador *Jogo::getJogador1()
{
    return &jogador1;
}

// Função que retorna um ponteiro para o Jogador 2
Jogador *Jogo::getJogador2()
{
    return &jogador2;
}

// Função que faz a ação de jogar uma carta
void Jogo::jogarCarta(Carta carta)
{
    jogadorDoTurno->escolherCarta(carta);
}

// Função que inicia uma nova rodada
void Jogo::novaRodada()
{
    // Inicializa o baralho
    Baralho baralho;
    this->baralho = baralho;

    // Limpa a mao dos jogadores
    jogador1.limpaMao();
    jogador2.limpaMao();

    // Distribui as cartas para os jogadores
    darCartas();
    
    fimRodada = false;
    while (!fimRodada)
    {
        cout << "Programa: "
             << "Primeiro jogador: " << jogadorDoTurno->getNome() << endl;
        int fimDoTurno = 0;
        while (fimDoTurno == 0)
        {
            cout << "Programa: "
                 << "Escolha uma carta ou uma opcao:" << endl;
            cout << "Programa: " << jogadorDoTurno->mostrarMao() << "Truco Desistir Placar" << endl;
            cout << jogadorDoTurno->getNome() << ": ";
            string opcao;
            cin >> opcao;
            if (opcao == "Truco")
            {
                truco();
            }
            else if (opcao == "Desistir")
            {
                desistir();
                fimDoTurno = 1;
            }
            else if (opcao == "Placar")
            {
                placar();
            }
            else
            {
                Carta carta(opcao[0], opcao[1]);
                while (jogadorDoTurno->temCarta(carta) == false)
                {
                    cout << "Programa: "
                         << "Opcao invalda, jogador nao tem essa carta" << endl;
                    cout << "Programa: "
                         << "Escolha uma carta ou uma opcao:" << endl;
                    cout << "Programa: " << jogadorDoTurno->mostrarMao() << "Truco Desistir Placar" << endl;
                    cout << jogadorDoTurno->getNome() << ": ";
                    cin >> opcao;
                    carta = carta.getCarta(opcao[0], opcao[1]);
                }
                // Se chegar aqui é pq o jogador tem a carta
                carta = carta.getCarta(opcao[0], opcao[1]);
                jogarCarta(carta);

                // Vez do outro jogador
                trocaTurno();
            }
            // Verifica se os dois jogadores jogaram alguma carta
            if (jogador1.getCartaJogada().getNumero() != " " && jogador2.getCartaJogada().getNumero() != " ")
            {
                // Se jogaram, verifica quem ganhou
                verificarVencedor();
                fimDoTurno = 1;
                // Vez do outro jogador
                trocaTurno();
            }
        }
    }
}

// Função quer verifica o vencedor da rodada e do jogo
void Jogo::verificarVencedor()
{
    // Descobre qual carta cada um jogou
    Carta cartaJogador1 = jogador1.getCartaJogada();
    Carta cartaJogador2 = jogador2.getCartaJogada();

    // Verifica qual jogador venceu a rodada
    cout << "Programa: ";
    if (cartaJogador1.getPonto() > cartaJogador2.getPonto())
    {
        // Jogador do turno venceu
        jogador1.setPontoRodada(jogador1.getPontoRodada() + 1);
        cout << "Jogador vencedor da rodada: " << jogador1.getNome() << endl;

        // Se ninguem ainda venceu a primeira rodada
        if (venceu1Rodada == NULL){
            venceu1Rodada = getJogador1();
        }
    }
    else if (cartaJogador1.getPonto() < cartaJogador2.getPonto())
    {
        // Jogador 2 venceu
        jogador2.setPontoRodada(jogador2.getPontoRodada() + 1);
        cout << "Jogador vencedor da rodada: " << jogador2.getNome() << endl;

        // Se ninguem ainda venceu a primeira rodada
        if (venceu1Rodada == NULL){
            venceu1Rodada = getJogador2();
        }
    }
    else
    {
        cout << "Empate" << endl;
        if (venceu1Rodada == NULL){
            // Empatou na primeira rodada
            // Ganha quem vencer a segunda
            jogador1.setPontoRodada(1);
            jogador2.setPontoRodada(1);
        }else{
            // Empatou na segunda ou terceira rodada
            // Quem vence é quem ganhou a primeira rodada
            venceu1Rodada->setPontoRodada(2);
            
        }
    }

    if (jogador1.getPontoRodada() == 2)
    {
        cout << "Programa: "
             << "Jogador vencedor do ponto: " << jogador1.getNome() << endl;
        jogador1.setPontoJogo(jogador1.getPontoJogo() + valorRodada);
        jogador1.setPontoRodada(0);
        jogador2.setPontoRodada(0);
        placar();
        fimRodada = true;
        venceu1Rodada = NULL;
    }
    else if (jogador2.getPontoRodada() == 2)
    {
        cout << "Programa: "
             << "Jogador vencedor do ponto: " << jogador2.getNome() << endl;
        jogador2.setPontoJogo(jogador2.getPontoJogo() + valorRodada);
        jogador1.setPontoRodada(0);
        jogador2.setPontoRodada(0);
        placar();
        fimRodada = true;
        venceu1Rodada = NULL;
    }

    jogador1.limpaCartaJogada();
    jogador2.limpaCartaJogada();
}

// Função que imprime o placar
void Jogo::placar()
{
    cout << "Placar: " << endl;
    cout << jogador1.getNome() << ": " << jogador1.getPontoJogo() << endl;
    cout << jogador2.getNome() << ": " << jogador2.getPontoJogo() << endl;
}

// Função que realiza a ação do Truco
void Jogo::truco()
{
    // Identifica quem trucou e quem foi trucado
    Jogador *jogadorTrucou = jogadorDoTurno;
    Jogador *jogadorTrucado = proximoJogador;

    trocaTurno();
    valorRodada = 3;
    cout << "Escolha uma opcao: " << endl;
    cout << "Cartas: " << jogadorDoTurno->mostrarMao() << endl;
    int fimTruco = 0;
    while (fimTruco == 0 && valorRodada < 12)
    {
        cout << "Aceitar Aumentar Desistir" << endl;
        cout << jogadorDoTurno->getNome() << ": ";
        string opcao;
        cin >> opcao;
        if (opcao == "Aceitar")
        {
            // aceitou
            fimTruco = 1;
        }
        else if (opcao == "Aumentar")
        {
            trocaTurno();
            valorRodada += 3;
        }
        else if (opcao == "Desistir")
        {
            fimTruco = 1;
            desistir();
        }else{
            cout << "Opcao invalida, escolha uma opcao:" << endl;
        }
    }
    jogadorDoTurno = jogadorTrucou;
    proximoJogador = jogadorTrucado;
}

// Função que troca o turno entre os jogadores
void Jogo::trocaTurno()
{
    Jogador *jogadorAux;
    jogadorAux = jogadorDoTurno;
    jogadorDoTurno = proximoJogador;
    proximoJogador = jogadorAux;
}

// Função que realiza a função Desistir
void Jogo::desistir()
{
    cout << "Programa: "
         << "Jogador vencedor do ponto: " << proximoJogador->getNome() << endl;
    if (proximoJogador == &jogador1)
        jogador1.setPontoJogo(jogador1.getPontoJogo() + valorRodada);
    else
    {
        jogador2.setPontoJogo(jogador2.getPontoJogo() + valorRodada);
    }
    jogador1.setPontoRodada(0);
    jogador2.setPontoRodada(0);
    placar();
    fimRodada = true;
}

// Função que verifica se o jogo acabou
bool Jogo::fimJogo()
{
    if (jogador1.getPontoJogo() >= 12 || jogador2.getPontoJogo() >= 12)
    {
        cout << "Jogador vencedor do jogo: ";
        if (jogador1.getPontoJogo() >= 12)
            cout << jogador1.getNome() << endl;
        else
            cout << jogador2.getNome() << endl;
        return true;
    }
    return false;
}