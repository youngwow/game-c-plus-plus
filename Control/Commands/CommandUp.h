#pragma once
#include "Command.h"

class CommandUp: public Command{
private:
    Commands command;
public:
    CommandUp();
    CommandUp(Commands command_user);
    [[nodiscard]] Commands get_instruction() const override;
    void change(Commands instruction) override;
    char execute() override;
};
