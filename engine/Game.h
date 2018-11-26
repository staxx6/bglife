#ifndef GAME_H
#define GAME_H

#include <string>

#include "GameInfo.h"
#include "Stepper.h"

class Game 
{
public:
    Game(GameInfo*);
    virtual ~Game();

    int start();

    GameInfo *getGameInfo() const { return info; }
    void setExitGame(bool exit) { exitGame = exit; }
    void setPauseGame(bool pause) { pauseGame = pause; }
    bool isExitGame() const { return exitGame; }
    bool isPauseGame() const { return exitGame; }

    Game(const Game&);
    Game & operator = (const Game &);
    
protected:
    virtual int init();
    virtual int update();
    virtual int render();
    
private:
    GameInfo* info = nullptr;

    bool firstFrame = true;
    bool exitGame = false;
    bool pauseGame = false;
    Stepper* step = nullptr;
};

#endif /* GAME_H */
