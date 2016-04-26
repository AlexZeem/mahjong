#include "Participant.h"

namespace persistence {
Participant::Participant(unsigned long _pid,
                         unsigned long _gid,
                         std::vector <std::string> _uid):
    partId(_pid),
    gameId(_gid),
    userId(_uid)
{ }

//Getters:
unsigned long Participant::GetPartId(){return partId;}
unsigned long Participant::GetGameId() {return gameId;}
std::vector<std::string> Participant::GetUserId() {return userId;}

//Setters:
void Participant::SetPartId(unsigned long pid){
    partId = pid;
}

void Participant::SetGameId(unsigned long gid) {
    gameId = gid;
}

void Participant::SetUserId(const std::vector<std::string>& uid){
    userId = uid;
}

} // persistence
