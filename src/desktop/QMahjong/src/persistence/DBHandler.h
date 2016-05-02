#pragma once
#include <memory>
#include <QString>

namespace persistence {

class DBHandler
{
    struct impl_t;
    std::unique_ptr<impl_t> impl;

    DBHandler();
    ~DBHandler();

public:
    static DBHandler* instance();

    void load(const QString& path = default_path());
    void save(const QString& path = default_path());

    static QString default_path() { return "persistence/"; }

    // delete copy and move constructors and assign operators
    DBHandler(DBHandler const&) = delete;             // Copy construct
    DBHandler(DBHandler&&) = delete;                  // Move construct
    DBHandler& operator=(DBHandler const&) = delete;  // Copy assign
    DBHandler& operator=(DBHandler &&) = delete;      // Move assign
};

} //persistence
