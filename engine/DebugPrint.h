#ifndef DEBUGPRINT_H
#define DEBUGPRINT_H

#include <string>

class DebugPrint
{
public:
    enum class Type
    {
        NONE,
        TERMINAL
    };

    enum class Level
    {
        ERROR = 0,
        WARN,
        NORMAL,
        VERBOSE_0,
        VERBOSE_1,
        VERBOSE_2,
    };

    DebugPrint(Type type, Level level);
    ~DebugPrint();

    void print(std::string msg, Level level);

    DebugPrint(const DebugPrint&);
    DebugPrint & operator = (const DebugPrint &);

protected:

private:
    std::string getLevelName(Level level);

    Type type;    
    Level level;
};

#endif /* DEBUGPRINT_H */