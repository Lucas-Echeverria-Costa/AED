#ifndef POKEDEX_H
#define POKEDEX_H

#include "card.h"

typedef struct {
    Card *cards;        // Array de cartas
    int size;           // Número total de cartas
} Pokedex;

Pokedex* create_pokedex();
void add_pokemon(Pokedex *pokedex, Card card);
Card* search_pokemon(Pokedex *pokedex, const char *name);
void load_pokedex_from_csv(Pokedex *pokedex, const char *filename);
void free_pokedex(Pokedex *pokedex);

#endif
