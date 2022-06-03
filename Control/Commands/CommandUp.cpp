#include "CommandUp.h"

CommandUp::CommandUp() {
    this->command = Commands::Up;
}

CommandUp::CommandUp(Commands command_user) {
    this->command = command_user;
}

Commands CommandUp::get_instruction() const {
    return this->command;
}

char CommandUp::execute() {
    return 'W';
}

void CommandUp::change(Commands instruction) {
    this->command = instruction;
}