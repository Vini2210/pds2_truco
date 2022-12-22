Informações importantes do código:

Definições:
    Turno: É o turno de uma rodada, define qual jogador vai jogar, se o turno mudar, 
    significa que é a vez do outro jogador

Possui 4 classes:
    Carta - Define o que compõe uma carta: Numero, naipe e ponto.

    Baralho - Define o que compõe o baralho: Guarda as cartas, embaralha as cartas,
    retira uma carta do baralho, adiciona uma carta no baralho.

    Jogador - Define o que compõe um jogador: O nome do jogador, as cartas que ele recebeu,
    quantos pontos ele tem na rodada inicial e quantos pontos ele tem no jogo.

    Jogo - Define a classe que gerencia o jogo, ele guarda as informações sobre os jogadores que
    estão jogando, de quem é a vez de jogar, quantos pontos a rodada está valendo (aumentada pelo Truco),
    quem venceu a primeira rodada, o baralho que está sendo distruibido, distribuir as cartas e verificar quem
    venceu o turno, a rodada e o jogo.

Observações:
    - A ordem dos jogadores é alternada a cada rodada.

    - Após a melhor de 3, o Jogador 1 sempre começa primeiro.

    - É possível trucar e aumentar o truco até que o valor da rodada seja 12 pontos.

    - Caso um jogador aceite o truco, o outro aumente, e ele desiste, o outro jogador recebe a pontuação 
    do último truco aceitado (no caso deste exemplo, receberia 3 pontos).

Funções principais:
    - Jogo::novaRodada()
        Gerencia uma rodada, começa inicializando o baralho, limpando a mão dos jogadores e distribuindo as cartas
        da rodada. O jogador 1 começa jogando e a ordem vai alternando entre os dois jogadores durante a rodada.
        Essa função verifica e chama as ações dos jogadores (Truco, Desistir, Placar, Joga uma carta).

    O objetivo das outras funções são triviais e estão comentadas em cima de cada função no código.

Exemplo de execução utilizando um terminal com GCC:
> g++ .\main.cpp .\jogador.cpp .\jogo.cpp .\carta.cpp .\baralho.cpp -o programa
> ./programa