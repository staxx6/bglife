#include <iostream>

#include "engine/Game.h"
#include "BgLife.h"

int main()
{
    GameInfo info;
    info.setName("Background Life");
    info.setVersion("0.1");

    BgLife app(&info);
    app.start();

    return 0;
}

BgLife::BgLife(GameInfo* info) : Game(info)
{   
    std::cout << "BgLife constructor gameName: " 
        << getGameInfo()->getName() << std::endl;
}

int BgLife::init()
{
    std::cout << "BgLife init: "  << std::endl;

    return 0;
}


int BgLife::update()
{
    std::cout << "BgLife update: "  << std::endl;

    if(ticks++ > 3)
    {
        setExitGame(true);
    } 

    return 0;
}

int BgLife::render()
{
    std::cout << "BgLife render: "  << std::endl;

    return 0;
}

BgLife::~BgLife()
{
    //Game::~Game();
    std::cout << "BgLife destructor" << std::endl;
}