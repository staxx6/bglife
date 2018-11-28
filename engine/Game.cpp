#include <iostream>
#include <string>
#include <sstream>

#include "Game.h"
#include "State.h"

Game::Game(GameInfo *info) 
{
    this->info = info;
    this->debug = new DebugPrint(info->debugType, 
        info->debugLevel);

    printVVV("Game constructor: ");
        
    // TODO2 constructor with type variable
    // Game type?
    step = new Stepper(Stepper::Type::TERMINAL, 1, 1); 
}

void Game::addState(State *state)
{
    states.insert(std::pair<int, State *>(state->getId(), state));
}

void Game::setCurrentState(int id)
{
    currentState = states[id];
}

int Game::start() 
{
    printVVV("Game start: ");
    currentState->init();

    // prevent render bevore first update
    if(firstFrame) 
    {
        //update();
        currentState->update();
        firstFrame = false;
    }

    while(!exitGame)
    {
        while(!pauseGame && !exitGame)
        {
            if(!step->isTimeToUpdate() && !step->isTimeToRender())
            {
                // FIXME only for terminal
                step->letSleep();
            }
            else
            {
                if(step->isTimeToUpdate()) {
                    currentState->update();
                    step->updateFinished();
                }
                if(step->isTimeToRender())
                {
                    currentState->render();
                    step->renderFinished();
                }
            }
        }
        step->paused();
    }
    step->exit();

    printV(std::string("Update steps count: ") + std::to_string(step->getUpdateSteps()));
    printV(std::string("Frame steps count: ") + std::to_string(step->getRenderSteps()));

    return 0;
}

Game::~Game()
{
    printVVV("Game destructor: ");
    delete(step);
    delete(debug);

    // TODO! delete states array!
}