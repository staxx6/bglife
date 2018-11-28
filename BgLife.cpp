#include <iostream>

// #include "BgLife.h"
#include "engine/GameInfo.h"
#include "engine/Game.h"
#include "engine/DebugPrint.h"

#include "states/StateMenue.h"
//#include "states/StateGame.h"

int main()
{
    // Game infos
    GameInfo info;
    info.name = "Background Life";
    info.version = "0.1";
    info.debugType = DebugPrint::Type::TERMINAL;
    info.debugLevel = DebugPrint::Level::VERBOSE_2;

    // Create Game
    Game game(&info);

    //StateMenue stateMenue(&game);
    StateMenue menue;
    //StateGame stateGame(&game);
    game.addState(&menue);
    //game.addState(&stateGame);

    game.setCurrentState(menue.getId());

    game.start();

    return 0;
}

// BgLife::BgLife(GameInfo *info) : Game(info)
// {   
//     printVV("BgLife constructor gameName: " + info->name);
// }

// BgLife::~BgLife()
// {
//     printVV("BgLife destructor: ");
// }