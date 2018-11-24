#VERSION = 
CC=/bin/g++
CFLAGS= -Wall -Weffc++ -Wextra -Wsign-conversion

OBJ = engine/Stepper.o engine/Game.o

main: $(OBJ) BgLife.cpp BgLife.h
	$(CC) $(CFLAGS) BgLife.cpp -o BgLife $(OBJ)

%.o: %.h
#	$(CC) $(CFLAGS) -c $<

#Game.o: engine/Game.h #no need for *.c - implicit rule,
#GameInfo.o: engine/GameInfo.h
#Stepper.o: engine/Stepper.h

#.PHONY	#prevent stuff if a files name is clean 
#clean:
#-rm edit $(OBJ)