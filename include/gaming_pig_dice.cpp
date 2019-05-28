/**
 * @file gaming_pig_dice.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Funcoes para rodar o jogo
*/

#include <iostream>
#include <time.h> 
#include <unistd.h> //  sleep()
#include "../include/struct.h"
#include "pig_dice_ia.cpp"

/**
 * @brief Função para iniciar o jogo. Declarando quem começa e o nome de cada jogador.
 * @param player1       Primeiro jogador
 * @param player2       Segundo jogador
*/
jogador* game_start(jogador* player1, jogador* player2){

    std::cout   << "Opções de jogo :" << std::endl
                << "1 - PC x PC" << std::endl
                << "2 - Player1 x PC" << std::endl
                << "3 - Player1 x Player2" << std::endl;
    int op;            
    while(true){
        std::cout << "~> Escolha a opção: ";
        std::cin >> op;
        if(op == 1){
            player1->nome = "player1";
            player2->nome = "player2";
            break;
        } else if(op == 2){
            std::string name;
            std::cout << "Digite o nome do player1: ";
            std::cin >> name;
            player1->nome = name;
            player1->machine = false;

            if(name != "player2")
                player2->nome = "player2";
            else
                player2->nome = "player1";

            break;
        }else if(op == 3){
            std::string name;
            std::cout << "Digite o nome do player1: ";
            std::cin >> name;
            player1->nome = name;
            player1->machine = false;

            std::cout << "Digite o nome do player2: ";
            std::cin >> name;
            player2->nome = name;
            player2->machine = false;

            break;

        }else
            std::cout << "Opção invalida. Tente novamente" << std::endl;
    }

    std::cout << "\n\n";

    srand(time(NULL));
    int turn = rand()%2;

    if(turn == 0)
        return player1;
    else
        return player2;

}

/**
 * @brief Função que roda o jogo. Mostrando os pontos e informando as jogadas possiveis.
 * @param player        Ponteiro que diz de qual dos jogadores é a vez.
 * @param turn          Inteiro que determina a rodada que o jogo esta.
*/
void play_game(jogador* player, int turn){

    std::cout   << "\n############################ TURN \"" << turn<< "\"############################" << std::endl
                << "Vez do jogador [ " << player->nome << " ]" << std::endl
                << "Jogador tem salvo: " << player->pontos_acumulados << std::endl;

    int op;
    int qnt_repeticoes = 0; // Indica quantas vezes ja jogou na rodada
    while(true){
        std::cout   << "Pontos do turno: " << player->pontos_rodada << std::endl
                    << "1 - Jogar Pigs | "
                    << "0 - Passar a vez" << std::endl;

        if(player->machine){
            op = ia_player(player, qnt_repeticoes);
            std::cout << op << std::endl;
        }else 
            std::cin >> op;

        if(op == 0){
            player->pontos_acumulados += player->pontos_rodada;
            break; 
        }else if(op == 1){
            qnt_repeticoes += 1;
            std::cout   << "------------------------------------------------------------------------------" << std::endl
                        << "Jogando pigs..." << std::endl;
            
            
            //if(!player->machine)
            //    sleep(1);

            int dice = rand()%7;
            if(dice == 0)
                dice = 1;

            std::cout << "... " << dice << " !" << std::endl;
            if(dice == 1){
                std::cout << "Perdeu a vez!" << std::endl;
                break;
            } else
                player->pontos_rodada += dice;
        } else {
            std::cout << "Opção invalida! Tente novamente" << std::endl;
        }

    }
    //if(!player->machine)
    //        sleep(1);
    player->pontos_rodada = 0;
    
}

/**
 * @brief Função que muda a vez de quem vai jogar.
 * @param player1       Primeiro jogador
 * @param player2       Segundo jogador
 * @param turn          Jogador atual
*/
jogador* change_player(jogador* player1, jogador* player2, jogador* turn){
    if(player1->nome == turn->nome)
        return player2;
    else
        return player1;
}

/**
 * @brief Função que checa se o jogador ganhou.
 * @param player       Jogador atual
*/
bool check_winner(jogador* player){
    if(player->pontos_acumulados >= 100)
        return true;
    return false;
}
