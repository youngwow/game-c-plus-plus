#pragma once
#include "Commands/Command.h"

class Devices{
public:
    virtual Commands getCommand(char direction) = 0;
    virtual ~Devices(){

    }
};