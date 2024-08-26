#ifndef CARD_H
#define CARD_H

#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type1[MAX_TYPE_LENGTH];
    char type2[MAX_TYPE_LENGTH];
    int hp;
    int attack;
    int defense;
    int sp_atk;
    int sp_def;
    int legendary; // 0 = n�o lend�rio, 1 = lend�rio
} Card;

#endif
