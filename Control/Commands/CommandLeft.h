#pragma once
#include "Command.h"

class CommandLeft: public Command{
private:
    Commands command;
public:
    CommandLeft();
    CommandLeft(Commands command_user);
    [[nodiscard]] Commands get_instruction() const override;
    void change(Commands instruction) override;
    char execute() override;
};
