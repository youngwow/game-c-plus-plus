#pragma once
#include "../Tools/GameStats.h"

template<int EnemiesDied>  // 5 врагов должно умереть при создании поля 10 на 10
class Rules{
public:
    bool Check(GameStats &stats);
};

template<int EnemiesDied>
bool Rules<EnemiesDied>::Check(GameStats &stats) {
    return EnemiesDied <= stats.getEnemyKilled();
}

