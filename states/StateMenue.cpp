#include "StateMenue.h"
//#include "Game.h"

//StateMenue::StateMenue(Game *g) : State(g)
StateMenue::StateMenue() : State()
{

}

StateMenue::~StateMenue()
{

}

int StateMenue::init()
{
    // State::init();
    // g->printVV("StateMenue init: ");

    // g->printN("My very first game!");

    return 0;
}


int StateMenue::update()
{
    // State::update();
    // g->printVV("StateMenue update: ");

    if(ticks++ > 3)
    {
        // g->setExitGame(true);
    } 

    return 0;
}

int StateMenue::render()
{
    // State::render();
    // g->printVV("StateMenue render: ");

    return 0;
}