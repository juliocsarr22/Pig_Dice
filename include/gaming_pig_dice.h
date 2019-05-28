/**
 * @file gaming_pig_dice.h
 * @author Janeto Erick
 * @author Julio Cesar
*/

#include "gaming_pig_dice.cpp"

jogador* game_start(jogador* player1, jogador* player2);
void play_game(jogador* player, int turn);
jogador* change_player(jogador* player1, jogador* player2, jogador* turn);
bool check_winner(jogador* player);
void announce_winner(jogador* player);