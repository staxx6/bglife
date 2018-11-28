#ifndef BGLIFE_H
#define BGLIFE_H

#include "engine/GameInfo.h"

class BgLife : public Game
{
public:
    BgLife(GameInfo* info);
    ~BgLife() override;
    
protected:

private:
    int ticks = 0; // Debug ticks
};

#endif /* BGLIFE_H */