#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"
#include "game.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo_csv> <num_cartas_por_jogador>\n", argv[0]);
        return 1;
    }

    const char *csv_filename = argv[1];
    int num_cards_per_player = atoi(argv[2]);
    if (num_cards_per_player <= 0) {
        fprintf(stderr, "Número inválido de cartas por jogador.\n");
        return 1;
    }

    Pokedex *pokedex = create_pokedex();
    load_pokedex_from_csv(pokedex, csv_filename);

    start_game(pokedex, num_cards_per_player);

    free_pokedex(pokedex);

    return 0;
}
