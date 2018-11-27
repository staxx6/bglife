#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <string>

#include "DebugPrint.h"

struct GameInfo {
    std::string name = "No name";
    std::string version = "-1";

    DebugPrint::Type debugType = DebugPrint::Type::TERMINAL;
    DebugPrint::Level debugLevel = DebugPrint::Level::NORMAL;
};

#endif /* GAMEINFO_H */