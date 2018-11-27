#include <iostream>
#include <iomanip>

#include "DebugPrint.h"

DebugPrint::DebugPrint(Type type, Level level)
{
    this->type = type;
    this->level = level;
}

DebugPrint::~DebugPrint()
{

}

void DebugPrint::print(std::string msg, Level level)
{
    if(type == Type::NONE) return;

    if(type == Type::TERMINAL)
    {
    // Set VERBOSE_1 >= Asking VERBOSE_0
        if(this->level >= level)
        {
            if(this->level == Level::NORMAL)
            {
                std::cout << msg << std::endl;
            }
            else
            {
                std::cout << std::setw(9) << getLevelName(level) 
                << ": " << msg << std::endl;
            }
        }
    }
}

std::string DebugPrint::getLevelName(Level level)
{
    switch(level)
    {
        case Level::ERROR:
            return "ERROR";
        case Level::WARN:
            return "WARN";
        case Level::NORMAL:
            return "Normal";
        case Level::VERBOSE_0:
            return "Verbose";
        case Level::VERBOSE_1:
            return "Verbose_1";
        case Level::VERBOSE_2:
            return "Verbose_2";
        default:
            return "DEBUG PRINT FAIL";
    }
}