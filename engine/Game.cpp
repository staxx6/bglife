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
    return 0;
}

int Game::render() 
{
    return 0;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}