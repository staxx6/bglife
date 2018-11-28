#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>

#include "DebugPrint.h"
#include "GameInfo.h"
#include "Stepper.h"
#include "State.h"

class Game 
{
public:
    Game(GameInfo*);
    ~Game();

    int start();

    // States
    void addState(State *state);
    State getState(int id);
    void setCurrentState(int id);

    // Game arghhh cant think of the word :D
    GameInfo *getGameInfo() const { return info; }
    void setExitGame(bool exit) { exitGame = exit; }
    void setPauseGame(bool pause) { pauseGame = pause; }
    bool isExitGame() const { return exitGame; }
    bool isPauseGame() const { return exitGame; }

    // Short debug access
    void printE(std::string msg) { debug->print(msg, DebugPrint::Level::ERROR); };
    void printW(std::string msg) { debug->print(msg, DebugPrint::Level::WARN); };
    void printN(std::string msg) { debug->print(msg, DebugPrint::Level::NORMAL); };
    void printV(std::string msg) { debug->print(msg, DebugPrint::Level::VERBOSE_0); };
    void printVV(std::string msg) { debug->print(msg, DebugPrint::Level::VERBOSE_1); };
    void printVVV(std::string msg) { debug->print(msg, DebugPrint::Level::VERBOSE_2); };

    Game(const Game&);
    Game & operator = (const Game &);
    
protected:
    
private:
    GameInfo *info = nullptr;
    DebugPrint *debug = nullptr;

    std::map<int, State *> states;
    State *currentState = nullptr;

    bool firstFrame = true;
    bool exitGame = false;
    bool pauseGame = false;
    Stepper* step = nullptr;
};

#endif /* GAME_H */
