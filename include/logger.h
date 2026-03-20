#pragma once

#include <fstream>
#include <string>
#include "record.h"

class Logger
{
private:
    std::ofstream file;

public:
    //Constructor: open file
    explicit Logger(const std::string& filename);

    //Destructor: close file
    ~Logger();

    //Disable copy (two owners of same file is invalid)
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    //Enable move (transfer ownership)
    Logger(Logger&& other) noexcept;
    Logger& operator=(Logger&& other) noexcept;

    //Write data
    void writeLine(const std::string& line);

    void write(const Record& record) = delete;
    void write(Record&& record);

};