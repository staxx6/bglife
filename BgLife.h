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

};

#endif /* BGLIFE_H */