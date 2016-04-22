#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace persistence {

class Participant
{
public:
    Participant()
    { }

    Participant(unsigned long& _pid, unsigned long& _gid) :
        partId(_pid),
        gameId(_gid)
    { }

    Participant(const std::vector <std::string>& _uid) :
        userId(_uid)
    { }

private:
    unsigned long partId, gameId;
    std::vector <std::string> userId;

};

} //persistence
