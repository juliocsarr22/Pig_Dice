/**
 * @file main.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Função de IA (inteligencia artificial)
*/

#include <iostream>
#include "../include/gaming_pig_dice.h"


int main(void){

    jogador player1;
    jogador player2;

    jogador* turn = game_start(&player1, &player2);

    bool winner = false;
    float num_turn = 1; // Numero da rodada


    while(winner == 0){
        play_game(turn, num_turn);
        winner = check_winner(turn);
        
        if(!winner)
            turn = change_player(&player1, &player2, turn);
        num_turn += 0.5;
    }

    std::cout   << "\n\n\n" << turn->nome << " é o vencedor!! Com " 
                << turn->pontos_acumulados << " pontos." << std::endl;

    return 0;
}