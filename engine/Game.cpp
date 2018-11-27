#include <iostream>
#include <string>
#include <sstream>

#include "Game.h"

Game::Game(GameInfo* info) 
{
    this->info = info;
    this->debug = new DebugPrint(info->debugType, 
        info->debugLevel);

    printVVV("Game constructor: ");
        
    // TODO2 constructor with type variable
    // Game type?
    step = new Stepper(Stepper::Type::TERMINAL, 1, 1); 
}

int Game::init() 
{
    printVVV("Game init: ");

    return 0;
}

int Game::update() 
{
    printVVV("Game update: ");

    return 0;
}

int Game::render() 
{
    printVVV("Game render: ");

    return 0;
}

int Game::start() 
{
    printVVV("Game start: ");
    init();

    // prevent render bevore first update
    if(firstFrame) 
    {
        update();
        firstFrame = false;
    }

    while(!exitGame)
    {
        while(!pauseGame && !exitGame)
        {
            if(!step->isTimeToUpdate() && !step->isTimeToRender())
            {
                step->letSleep();
            }
            else
            {
                if(step->isTimeToUpdate()) {
                    update();
                    step->updateFinished();
                }
                if(step->isTimeToRender())
                {
                    render();
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
}