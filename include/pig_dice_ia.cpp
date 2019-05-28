/**
 * @file pig_dice_ia.cpp
 * @author Janeto Erick
 * @author Julio Cesar
 * @brief Função de IA (inteligencia artificial)
*/

int ia_player(jogador* turn, int qnt);

/**
 * @brief Função que determina a jogada que o computador deve fazer.
 * @param turn          Jogador atual
 * @param qnt           quantidade de jogadas que ja fez neste turno
*/
int ia_player(jogador* turn, int qnt){
    if(turn->pontos_rodada + turn->pontos_acumulados >= 100)
        return 0;
    else{
        if(turn->pontos_rodada + turn->pontos_acumulados < 50){
            if(turn->pontos_rodada > 10)
                return 0;
            else
                return 1;
        } else if(turn->pontos_rodada + turn->pontos_acumulados < 80){
            if(turn->pontos_rodada > 8)
                return 0;
            else
                return 1;
        } else if(turn->pontos_rodada + turn->pontos_acumulados < 100){
            if(qnt == 0)
                return 1;
            else   
                return 0;
        }
    }
}