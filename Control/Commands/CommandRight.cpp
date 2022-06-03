#include "CommandRight.h"

CommandRight::CommandRight() {
    this->command = Commands::Right;
}

CommandRight::CommandRight(Commands command_user) {
    this->command = command_user;
}

Commands CommandRight::get_instruction() const {
    return this->command;
}

char CommandRight::execute() {
    return 'D';
}

void CommandRight::change(Commands instruction) {
    this->command = instruction;
}