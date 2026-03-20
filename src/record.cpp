#include "record.h"
#include <utility>

//constructor
Record::Record(std::string name, Buffer buffer)
    : name(std::move(name)), buffer(std::move(buffer))
{
}

//move assignment
Record& Record::operator=(Record&& other) noexcept
{
    if(this != &other)
    {
        name = std::move(other.name);
        buffer = std::move(other.buffer);
    }
    return *this;
}

//accessors
const std::string& Record::getName() const
{
    return name;
}

const Buffer& Record::getBuffer() const
{
    return buffer;
}