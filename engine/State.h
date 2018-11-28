#ifndef STATE_H
#define STATE_H

//#include "Game.h"

class State
{
public:
    //State(Game *g);
    State();
    virtual ~State();

    int getId() { return id; }

    virtual int init();
    virtual int update();
    virtual int render();

    State(const State&);
    State & operator = (const State &);

protected:
    // Game *g;

private:
    int id;
    static int idCount;
};

#endif /* STATE_H */