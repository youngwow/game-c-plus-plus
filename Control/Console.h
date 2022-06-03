#pragma once

#include <map>
#include "Devices.h"


class Console: public Devices{
private:
    std::map<char, Commands>dir;
public:
    Console();
    Commands getCommand(char direction) override;
};
