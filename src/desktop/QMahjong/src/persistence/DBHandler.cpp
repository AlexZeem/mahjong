#include <fstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>

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
    boost::archive::text_oarchive oa(ofs);
    oa << "s";
}

void DBHandler::load(const std::string &filepath)
{
    std::ifstream ifs(filepath);
    boost::archive::text_iarchive ia(ifs);

    // restore the schedule from the archive
    //ia >> s;
}

} //persistence
