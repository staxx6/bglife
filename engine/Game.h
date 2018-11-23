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

    virtual int init();
    virtual int update();
    virtual int render();

    GameInfo *getGameInfo() const { return info; }

protected:

private:
    GameInfo* info;
};

#endif /* GAME_H */
