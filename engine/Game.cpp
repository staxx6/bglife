#include <iostream>

#include "Game.h"

Game::Game(GameInfo* info) 
{
    this->info = info;
    step = new Stepper(Stepper::Type::NORMAL); //PERHAPS constructor with variable
    
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

    while(!exitGame)
    {
        while(!pauseGame && !exitGame)
        {
            if(step->timeToUpdate()) {
                update();
            }
            step->updateFinished();
            if(step->timeToRender())
            {
                render();
            }
            step->renderFinished();
        }
        step->paused();
    }
    step->exit();

    return 0;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
    delete(step);
}