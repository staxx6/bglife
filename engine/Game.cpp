#include <iostream>

#include "Game.h"

Game::Game(GameInfo* info) 
{
    this->info = info;

    // TODO2 constructor with type variable
    // Game type?
    step = new Stepper(Stepper::Type::TERMINAL, 0.8, 3); 
    
    std::cout << "Game constructor with info" << std::endl;
}

int Game::init() 
{
    std::cout << "init from Game" << std::endl;


    return 0;
}

int Game::update() 
{
    std::cout << "Game update: "  << std::endl;

    return 0;
}

int Game::render() 
{
    std::cout << "Game render: "  << std::endl;

    return 0;
}

int Game::start() 
{
    std::cout << "Game start: "  << std::endl;
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


    std::cout << "UpdateTicks: " << step->getUpdateSteps() << std::endl;
    std::cout << "FrameTicks: " << step->getRenderSteps() << std::endl;

    return 0;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
    delete(step);
}