#pragma once
#include "../Tools/GameStats.h"

template<int Steps>
class Rules_second{
public:
    bool Check(GameStats &stats);
};

template<int Steps>
bool Rules_second<Steps>::Check(GameStats &stats) {
    return Steps <= stats.getStepsMade();
}
