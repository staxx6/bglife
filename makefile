#VERSION = 
CC=/bin/g++
CFLAGS= -Wall -Weffc++ -Wextra -Wsign-conversion

OBJ = engine/Game.o

main: $(OBJ) BgLife.cpp BgLife.h
	$(CC) $(CFLAGS) BgLife.cpp -o BgLife $(OBJ)

#%.o: %.c %.h
#	$(CC) $(CFLAGS) -c $<

Game.o: engine/Game.h #no need for *.c - implicit rule,

#.PHONY	#prevent stuff if a files name is clean 
#clean:
#-rm edit $(OBJ)