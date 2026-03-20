#pragma once

#include "record.h"

class device
{
public:
    virtual ~device() = default;

    //produce one record (ownership returned)
    virtual Record read() = 0;
};