#include "CommandDown.h"

CommandDown::CommandDown() {
    this->command = Commands::Down;
}

CommandDown::CommandDown(Commands command_user) {
    this->command = command_user;
}

Commands CommandDown::get_instruction() const {
    return this->command;
}

char CommandDown::execute() {
    return 'S';
}

void CommandDown::change(Commands instruction) {
    this->command = instruction;
}
