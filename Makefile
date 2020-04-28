CC = g++
CFLAGS=-pedantic -Wall -Werror -g #`pkg-config libxml-2.0 --cflags`
RM = rm -fv


.PHONY: all clean

all: main.out
%.o: %.cpp %.h
main.out: Joueur.o JoueursManager.o Equipe.o  EquipesManager.o Buteur.o Match.o Journee.o Ligue.o Parse.o main.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) *.o *.out
