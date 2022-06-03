#pragma once

#include "Commands/CommandUp.h"
#include "Commands/CommandDown.h"
#include "Commands/CommandLeft.h"
#include "Commands/CommandRight.h"
#include "Devices.h"
#include "Console.h"




class Invoker{
private:

    Devices* devices;
    Command *Up;
    Command *Down;
    Command *Left;
    Command *Right;
public:
    Invoker();
    void SetCommand(Command* up, Command* down, Command* left, Command* right);

    char run();
    ~Invoker();
};

