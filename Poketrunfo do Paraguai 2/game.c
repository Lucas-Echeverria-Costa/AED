#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

// Função para embaralhar as cartas
void shuffle_cards(Card *cards, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void start_game(Pokedex *pokedex, int num_cards_per_player) {
    int num_players = 2;
    Player players[num_players];

    shuffle_cards(pokedex->cards, pokedex->size);

    for (int i = 0; i < num_players; i++) {
        players[i].player_cards = malloc(num_cards_per_player * sizeof(Card));
        if (players[i].player_cards == NULL) {
            perror("Erro ao alocar memória para as cartas do jogador");
            exit(EXIT_FAILURE);
        }
        players[i].num_cards = num_cards_per_player;
        for (int j = 0; j < num_cards_per_player; j++) {
            players[i].player_cards[j] = pokedex->cards[i * num_cards_per_player + j];
        }
    }

    int game_ongoing = 1;

    printf("Iniciando o jogo...\n");
    printf("Número de jogadores: %d\n", num_players);
    printf("Número de cartas por jogador: %d\n", num_cards_per_player);

    while (game_ongoing) {
        play_round(players, num_players);

        int players_with_cards = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[i].num_cards > 0) {
                players_with_cards++;
            }
        }

        if (players_with_cards <= 1) {
            game_ongoing = 0;
        }
    }

    determine_winner(players, num_players);

    for (int i = 0; i < num_players; i++) {
        free(players[i].player_cards);
    }
}

void print_card(const Card *card) {
    printf("Nome: %s\n", card->name);
    printf("Tipo 1: %s\n", card->type1);
    printf("Tipo 2: %s\n", card->type2);
    printf("HP: %d\n", card->hp);
    printf("Ataque: %d\n", card->attack);
    printf("Defesa: %d\n", card->defense);
    printf("Ataque Especial: %d\n", card->sp_atk);
    printf("Defesa Especial: %d\n", card->sp_def);
    printf("Lendário: %d\n", card->legendary);
}

void print_player_cards(const Player *player) {
    for (int i = 0; i < player->num_cards; i++) {
        print_card(&player->player_cards[i]);
        printf("\n");
    }
}

void play_round(Player *players, int num_players) {
    Card played_cards[num_players];
    int winner_index = 0;
    int max_value = -1;
    int attribute;
    int values[num_players];

for (int i = 0; i < num_players; i++) {
        if (players[i].num_cards > 0) {
            played_cards[i] = players[i].player_cards[0];
            printf("Jogador %d joga:\n", i + 1);
            print_card(&played_cards[i]);

            attribute = rand() % 5;

            switch (attribute) {
                case 0: values[i] = played_cards[i].hp; break;
                case 1: values[i] = played_cards[i].attack; break;
                case 2: values[i] = played_cards[i].defense; break;
                case 3: values[i] = played_cards[i].sp_atk; break;
                case 4: values[i] = played_cards[i].sp_def; break;
            }

            if (values[i] > max_value) {
                max_value = values[i];
                winner_index = i;
            }
        }
    }

    printf("O vencedor da rodada é o Jogador %d\n", winner_index + 1);
    for (int i = 0; i < num_players; i++) {
        if (i != winner_index && players[i].num_cards > 0) {
            for (int j = 0; j < num_players; j++) {
                if (players[j].num_cards > 0) {
                    players[winner_index].player_cards[players[winner_index].num_cards++] = played_cards[j];
                }
            }
        }
    }
    for (int i = 0; i < num_players; i++) {
        if (i != winner_index && players[i].num_cards > 0) {
            for (int j = 0; j < num_players - 1; j++) {
                players[i].player_cards[j] = players[i].player_cards[j + 1];
            }
            players[i].num_cards--;
        }
    }
}

void determine_winner(Player *players, int num_players) {
    int max_cards = 0;
    int winner_index = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].num_cards > max_cards) {
            max_cards = players[i].num_cards;
            winner_index = i;
        }
    }
    printf("O vencedor do jogo é o Jogador %d\n", winner_index + 1);
}
