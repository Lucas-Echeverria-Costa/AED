#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

Pokedex *create_pokedex() {
    Pokedex *pokedex = (Pokedex *)malloc(sizeof(Pokedex));
    if (pokedex == NULL) {
        perror("Erro ao alocar memória para a Pokédex");
        exit(EXIT_FAILURE);
    }
    pokedex->cards = NULL;
    pokedex->size = 0;
    return pokedex;
}

void load_pokedex_from_csv(Pokedex *pokedex, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo CSV");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        pokedex->cards = (Card *)realloc(pokedex->cards, (count + 1) * sizeof(Card));
        if (pokedex->cards == NULL) {
            perror("Erro ao realocar memória para as cartas");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        sscanf(line, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",
               pokedex->cards[count].name,
               pokedex->cards[count].type1,
               pokedex->cards[count].type2,
               &pokedex->cards[count].hp,
               &pokedex->cards[count].attack,
               &pokedex->cards[count].defense,
               &pokedex->cards[count].sp_atk,
               &pokedex->cards[count].sp_def,
               &pokedex->cards[count].legendary);

        count++;
    }

    pokedex->size = count;
    fclose(file);
}

void free_pokedex(Pokedex *pokedex) {
    free(pokedex->cards);
    free(pokedex);
}
