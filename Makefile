CC = g++
CFLAGS=-pedantic-errors -Wall -Werror -g
RM = rm -fv


.PHONY: all clean

all: foot
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<
foot: Player.o PlayerManager.o Team.o  TeamManager.o Scorer.o Match.o Day.o League.o Parser.o main.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) *.o foot
