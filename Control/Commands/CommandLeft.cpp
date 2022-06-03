#include "CommandLeft.h"

CommandLeft::CommandLeft() {
    this->command = Commands::Left;
}

CommandLeft::CommandLeft(Commands command_user) {
    this->command = command_user;
}

Commands CommandLeft::get_instruction() const {
    return this->command;
}

char CommandLeft::execute() {
    return 'A';
}

void CommandLeft::change(Commands instruction) {
    this->command = instruction;
}