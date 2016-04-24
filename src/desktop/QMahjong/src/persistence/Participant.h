#pragma once

#include <string>

namespace persistence {

class Participant
{
public:
    Participant(unsigned long _pid = 0, unsigned long _gid = 0,
                std::vector <std::string> _uid = std::vector<std::string>(4,"Login")) :
        partId(_pid),
        gameId(_gid),
        userId(_uid)

    { }

    unsigned long GetPartId() {
        return partId;
    }

    void SetPartId(unsigned long pid) {
        partId = pid;
    }

    unsigned long GetGameId() {
        return gameId;
    }

    void SetGameId(unsigned long gid) {
        gameId = gid;
    }

    std::vector<std::string> GetUsedId() {
        return userId;
    }

    void SetUserId (const std::vector<std::string>& u) {
        userId = u;
    }

private:
    unsigned long partId;
    unsigned long gameId;
    std::vector <std::string> userId;

};

} //persistence
