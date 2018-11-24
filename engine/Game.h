#ifndef GAME_H
#define GAME_H

#include <string>

#include "GameInfo.h"

class Game 
{
public:
    // Game();
    Game(GameInfo*);
    virtual ~Game();

    int start();

    GameInfo *getGameInfo() const { return info; }
    void setExitGame(bool exit) { exitGame = exit; }
    void setPauseGame(bool pause) { pauseGame = pause; }
    bool isExitGame() { return exitGame; }
    bool isPauseGame() { return exitGame; }

    Game(const Game&);
    Game & operator = (const Game &);
    
protected:
    virtual int init();
    virtual int update();
    virtual int render();
    
private:
    GameInfo* info = nullptr;
    bool exitGame = false;
    bool pauseGame = false;
};

#endif /* GAME_H */
