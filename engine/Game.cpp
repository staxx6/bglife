#include <iostream>

#include "Game.h"

// Game::Game()
// {
//     std::cout << "Game constructor nothing" << std::endl;
// }

Game::Game(GameInfo* info) 
{
    this->info = info;
    
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
            update();
            render();
        }
    }

    return 0;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}