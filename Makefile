CC = g++
CFLAGS=-pedantic -Wall -Werror -g #`pkg-config libxml-2.0 --cflags`
RM = rm -fv


.PHONY: all clean

all: main.out
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -cpp -o $@ $<
main.out: main.o ligue.o journee.o match.o buteur.o equipes.o equipe.o joueurs.o joueur.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) *.o *.out
