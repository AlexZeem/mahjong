#pragma once
#include <memory>
#include <string>

namespace persistence {

class DBHandler
{
    struct impl_t;
    std::unique_ptr<impl_t> impl;

    DBHandler();
    ~DBHandler();

public:
    static DBHandler* instance();

    void load(const std::string &filepath = default_path());
    void save(const std::string &filepath = default_path());

    static std::string default_path() { return "persistence.txt"; }

    // delete copy and move constructors and assign operators
    DBHandler(DBHandler const&) = delete;             // Copy construct
    DBHandler(DBHandler&&) = delete;                  // Move construct
    DBHandler& operator=(DBHandler const&) = delete;  // Copy assign
    DBHandler& operator=(DBHandler &&) = delete;      // Move assign
};

} //persistence
