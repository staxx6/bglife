#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <string>

class GameInfo
{
public:
    void setName(std::string name) { this->name = name; }
    void setVersion(std::string version) { this->version = version; }
    std::string getName() const { return name; }
    std::string getVersion() const { return version; }

protected:
    

private:
    std::string name = "No name";
    std::string version = "-1";
};

#endif /* GAMEINFO_H */