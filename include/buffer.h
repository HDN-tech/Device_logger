#ifndef BUFFER_H
#define BUFFER_H

#include <cstddef>  //size_t

class Buffer
{
private:
    std::size_t size;
    int* data;

public:
    //Constructor
    Buffer(std::size_t size);

    //Destructor
    ~Buffer();

    //Copy Constructor
    Buffer(const Buffer& other);

    //Copy assignment operator
    Buffer& operator=(const Buffer& other);

    //Move constructor
    Buffer(Buffer&& other);

    //Move assignment operator
    Buffer& operator=(Buffer&& other);

    //Utility function
    void fill(int value);

    //Debug helper
    std::size_t getSize() const;

    const int* getData() const;
};

#endif