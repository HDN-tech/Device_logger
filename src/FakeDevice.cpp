#include "FakeDevice.h"
#include "buffer.h"
#include <utility>

FakeDevice::FakeDevice(std::string name, std::size_t sampleCount, int value)
    :name(std::move(name)), sampleCount(sampleCount), value(value)
{

}

Record FakeDevice::read()
{
    //create data
    Buffer buf(sampleCount);
    buf.fill(value);

    //return by value (RVO applies)
    return Record(name, std::move(buf));

}