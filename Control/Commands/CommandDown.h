#pragma once
#include "Command.h"

class CommandDown: public Command{
private:
    Commands command;
public:
    CommandDown();
    CommandDown(Commands command_user);
    [[nodiscard]] Commands get_instruction() const override;
    void change(Commands instruction) override;
    char execute() override;
};

