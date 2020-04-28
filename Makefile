CC = g++
CFLAGS=-pedantic -Wall -Werror -g
RM = rm -fv


.PHONY: all clean

all: foot
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<
foot: Joueur.o JoueursManager.o Equipe.o  EquipesManager.o Buteur.o Match.o Journee.o Ligue.o main.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) *.o foot
