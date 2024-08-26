#ifndef GAME_H
#define GAME_H

#include "pokedex.h"

// Estrutura para o jogo
typedef struct {
    Card *player_cards;
    int num_cards;
} Player;

// Fun��es para gerenciar o jogo
void start_game(Pokedex *pokedex, int num_cards_per_player);
void play_round(Player *players, int num_players);
void determine_winner(Player *players, int num_players);
void print_card(const Card *card);
void print_player_cards(const Player *player);

#endif
