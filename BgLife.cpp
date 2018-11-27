#include <iostream>

#include "engine/Game.h"
#include "engine/DebugPrint.h"
#include "BgLife.h"

int main()
{
    GameInfo info;
    info.name = "Background Life";
    info.version = "0.1";
    info.debugType = DebugPrint::Type::TERMINAL;
    info.debugLevel = DebugPrint::Level::VERBOSE_0;

    BgLife app(&info);
    app.start();

    return 0;
}

BgLife::BgLife(GameInfo* info) : Game(info)
{   
    printVV("BgLife constructor gameName: " + info->name);
}

int BgLife::init()
{
    Game::init();
    printVV("BgLife init: ");

    printN("My very first game!");

    return 0;
}


int BgLife::update()
{
    Game::update();
    printVV("BgLife update: ");

    if(ticks++ > 3)
    {
        setExitGame(true);
    } 

    return 0;
}

int BgLife::render()
{
    Game::render();
    printVV("BgLife render: ");

    return 0;
}

BgLife::~BgLife()
{
    printVV("BgLife destructor: ");
}