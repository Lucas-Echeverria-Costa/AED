CC = gcc

CFLAGS = -Wall -Wextra -std=c99

EXEC = poketrunfo

OBJS = main.o game.o pokedex.o card.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.c game.h pokedex.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h pokedex.h card.h
	$(CC) $(CFLAGS) -c game.c

pokedex.o: pokedex.c pokedex.h card.h
	$(CC) $(CFLAGS) -c pokedex.c

card.o: card.c card.h
	$(CC) $(CFLAGS) -c card.c

clean:
	rm -f $(EXEC) $(OBJS)
