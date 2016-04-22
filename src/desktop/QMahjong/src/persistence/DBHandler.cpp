#include <fstream>

#include "Limit.h"
#include "DBHandler.h"

namespace persistence {

struct DBHandler::impl_t
{
    impl_t()
    { }

    ~impl_t()
    { }

    Limit l;
};

DBHandler::DBHandler()
    : impl(new impl_t())
{ //load();
}

DBHandler::~DBHandler()
{ save(); }

DBHandler* DBHandler::instance()
{
    static DBHandler*  ptr = 0;
    if (!ptr)
        ptr = new DBHandler();

    return ptr;
}

void DBHandler::save(const std::string &filepath)
{
    std::ofstream ofs(filepath);

}

void DBHandler::load(const std::string &filepath)
{
    std::ifstream ifs(filepath);

    // restore the schedule from the archive
    //ia >> s;
}

} //persistence
