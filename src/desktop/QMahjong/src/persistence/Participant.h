#pragma once

#include <string>
#include <vector>

namespace persistence {

class Participant
{
public:
    Participant(unsigned long _pid = 0,
                unsigned long _gid = 0,
                std::vector <std::string> _uid = std::vector<std::string>(4,"Login"));
    //Getters:
    unsigned long GetPartId();
    unsigned long GetGameId();
    std::vector <std::string> GetUserId();

    //Setters:
    void SetPartId(unsigned long);
    void SetGameId(unsigned long);
    void SetUserId(const std::vector <std::string>&);

private:
    unsigned long partId;
    unsigned long gameId;
    std::vector <std::string> userId;

};

} //persistence
