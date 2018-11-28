#ifndef STATEMENUE_H
#define STATEMENUE_H

#include "../engine/State.h"

class StateMenue : public State
{
public:
    // StateMenue(Game *g);
    StateMenue();
    ~StateMenue();

    int init() override;
    int update() override;
    int render() override;

    StateMenue(const StateMenue&);
    StateMenue & operator = (const StateMenue &);

protected:
    

private:
    int ticks = 0;
};

#endif /* STATEMENUE_H */