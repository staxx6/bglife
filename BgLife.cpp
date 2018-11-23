#include <iostream>

#include "engine/Game.h"
#include "BgLife.h"

int main()
{
    GameInfo info;
    info.setName("Background Life");
    info.setVersion("0.1");

    BgLife app(&info);

    app.init();

    return 0;
}

BgLife::BgLife(GameInfo* info) : Game(info)
{   
    std::cout << "BgLife constructor gameName: " 
                << getGameInfo()->getName() << std::endl;
}

int BgLife::init()
{
    

    return 0;
}


int BgLife::update()
{
    

    return 0;
}

int BgLife::render()
{
    

    return 0;
}

BgLife::~BgLife()
{
    //Game::~Game();
    std::cout << "BgLife destructor" << std::endl;
}