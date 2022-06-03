#include "Console.h"


Commands Console::getCommand(char direction) {
    return dir[direction];
}

Console::Console() {
    dir['W'] = Commands::Up;
    dir['S'] = Commands::Down;
    dir['A'] = Commands::Left;
    dir['D'] = Commands::Right;
}
