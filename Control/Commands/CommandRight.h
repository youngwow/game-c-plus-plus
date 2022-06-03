#pragma once
#include "Command.h"

class CommandRight: public Command{
private:
    Commands command;
public:
    CommandRight();
    CommandRight(Commands command_user);
    [[nodiscard]] Commands get_instruction() const override;
    void change(Commands instruction) override;
    char execute() override;
};
