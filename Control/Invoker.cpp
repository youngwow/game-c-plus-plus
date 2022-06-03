#include "Invoker.h"
#include <iostream>

void Invoker::SetCommand(Command* up, Command* down, Command* left, Command* right) {
    this->Up = dynamic_cast<CommandUp*>(up);
    this->Down = dynamic_cast<CommandDown*>(down);
    this->Left = dynamic_cast<CommandLeft*>(left);
    this->Right = dynamic_cast<CommandRight*>(right);
    this->devices = new Console();

}

char Invoker::run() {
    char command;
    std::cout << "Enter command: ";
    std::cin >> command;
    std::cout << std::endl;

    if (command == 'F' or command == 'G' or command == 'H' or command == 'E'){
        return command;
    }
    if (devices->getCommand(command) == this->Up->get_instruction()){  // dir[command]
        return this->Up->execute();
    }
    else if (devices->getCommand(command) == this->Down->get_instruction()){
        return this->Down->execute();
    }
    else if (devices->getCommand(command) == this->Right->get_instruction()){
        return this->Right->execute();
    }
    else if (devices->getCommand(command) == this->Left->get_instruction()){
        return this->Left->execute();
    }
    else{
        std::cout << "Default: UP" << std::endl;
        return this->Up->execute();
    }


}

Invoker::Invoker() {
    devices = nullptr;
    Up = nullptr;
    Down = nullptr;
    Left = nullptr;
    Right = nullptr;
}

Invoker::~Invoker() {
    delete Up;
    delete Down;
    delete Left;
    delete Right;
    delete devices;
}
