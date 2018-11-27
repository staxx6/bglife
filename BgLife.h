#ifndef BGLIFE_H
#define BGLIFE_H

#include "engine/GameInfo.h"

class BgLife : public Game
{
public:
    BgLife(GameInfo* info);
    ~BgLife() override;

    int init() override;
    int update() override;
    int render() override;
protected:

private:
    int ticks = 0; // Debug ticks
};

#endif /* BGLIFE_H */