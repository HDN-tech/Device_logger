#include "buffer.h"
#include <iostream>

//Constructor
Buffer::Buffer(std::size_t size)
    : size(size), data(nullptr)
{
    data = new int[size];
    std::cout << "Buffer constructed (size = " <<size << ", this = " << this << ")\n";
}

//Destructor
Buffer::~Buffer()
{
    delete[] data;
    data = nullptr;
    size = 0;
    //std::cout << "Buffer destroyed (size = " << size << ")\n";
    std::cout << "Buffer destroyed (size = " << size << ", this = " << this << ")\n";
}

//Fill buffer with a value
void Buffer::fill(int value)
{
        for(std::size_t i = 0; i < size; ++i){
            data[i] = value;
        }
}

// Getter
std::size_t Buffer::getSize() const
{
    return size;
}

//Copy Constructor
Buffer::Buffer(const Buffer& other)
    : size(other.size), data(nullptr)
{
    data = new int[size];
    for(std::size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }

    //std::cout << "Buffer copied (deep copy, size = " << size << ")\n";
    std::cout << "Buffer COPY constructed (this = " << size << ")\n";

}

// Copy assignment operator (DEEP COPY)
Buffer& Buffer::operator=(const Buffer& other)
{
    if (this == &other)
        return *this; // self-assignment guard

    //Release current resources
    delete[] data;

    //Copy from other
    size = other.size;
    data = new int[size];
    for(std::size_t i = 0; i < size; ++i)
    {
        data[i] = other.data[i];
    }

    std::cout << "Buffer COPY ASSIGNED (deep copy)\n";
    return *this;
}

//Move constructor
Buffer::Buffer(Buffer&& other)
    : size(other.size), data(other.data)
{
    other.size = 0;
    other.data = nullptr;

    //std::cout << "Buffer MOVED (ownership transferred)\n";
    std::cout << "Buffer MOVE constructed (this = " << this << ")\n";
}

//Move assignment operator
Buffer& Buffer::operator=(Buffer&& other)
{
    if(this==&other)
        return *this;
    
    //Release current resource
    delete[] data;

    //Steal resources
    size = other.size;
    data = other.data;

    //Leave other in valid empty state
    other.size = 0;
    other.data = nullptr;

    std::cout << "Buffer MOVE ASSIGNED (ownership transferred)\n";
    return *this;
}

const int* Buffer::getData() const
{
    return data;
}
