#pragma once

#include "buffer.h"
#include <string>

class Record
{
private:
    std::string name;
    Buffer buffer;

public:
    //construct a record with data
    Record(std::string name, Buffer buffer);

    //destructor
    ~Record() = default;

    //disable copy (for now)
    Record (const Record&) = delete;
    Record& operator=(const Record&) = delete;

    //enable move
    Record(Record&& other) noexcept;
    Record& operator=(Record&& other) noexcept;

    //accessors
    const std::string& getName() const;
    const Buffer& getBuffer() const;
};