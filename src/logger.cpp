#include "Logger.h"
#include <iostream>

//Constructor
Logger::Logger(const std::string& filename)
{
    file.open(filename, std::ios::out | std::ios::app);

    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open log file");
    }

    std::cout << "Logger opened file\n";
}

//Destructor
Logger::~Logger()
{
    if(file.is_open())
    {
        file.close();
        std::cout << "Logger closed file\n";
    }
}

//Move constructor
Logger::Logger(Logger&& other) noexcept
    : file(std::move(other.file))
{
    std::cout << "Logger Moved (ownership transferred)\n";
}

//Move assignment
Logger& Logger::operator=(Logger&& other) noexcept
{
    if(this != &other)
    {
        file = std::move(other.file);
        std::cout << "logger MOVE ASSIGNED\n";
    }
    return *this;
}

//write a line to the file
void Logger::writeLine(const std::string& line)
{
    if(!file.is_open())
    {
        throw std::runtime_error("attempt to write to closed log file");
    }

    file << line << '\n';
}

void Logger::write(Record&& record)
{
    if(!file.is_open())
        throw std::runtime_error("Logger is closed");

    file << record.getName() << ": ";
    //file << "[buffer size = " << record.getBuffer().getSize() << "]\n";
    const Buffer& buf = record.getBuffer();
    file << "[size=" << buf.getSize() <<", values=";

    for(std::size_t i = 0; i<buf.getSize(); ++i)
    {
        file << buf.getData()[i];
        if(i+1 < buf.getSize())
            file << ",";
    }

    file << "]\n";
}