#pragma once

#include "device.h"
#include <string>
#include <cstddef>

class FakeDevice : public device
{
private:
    std::string name;
    std::size_t sampleCount;
    int value;

public:

    FakeDevice(std::string name, std::size_t sampleCount, int value);

    Record read() override;

};
