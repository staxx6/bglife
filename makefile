#VERSION = 
CC=/bin/g++
CFLAGS= -Wall -Weffc++ -Wextra -Wsign-conversion

OBJ = engine/Stepper.o engine/Game.o engine/DebugPrint.o engine/State.h states/StateMenue.h 
#OBJ = *.o

main: $(OBJ) BgLife.cpp
	$(CC) $(CFLAGS) BgLife.cpp -o BgLife $(OBJ)

#%.o: %.h
#	$(CC) $(CFLAGS) -c $<

Game.o: engine/Game.cpp engine/Game.h 

GameInfo.o: engine/GameInfo.h
Stepper.o: engine/Stepper.h
DebugPrint.o: engine/DebugPrint.h
State.o: engine/State.h
StateMenue.o: states/StateMenue.h


#.PHONY	#prevent stuff if a files name is clean 
#clean:
#	-rm edit $(OBJ)