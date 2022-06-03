#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../Entity/CageEntity.h"
#include "../Entity/MovableCharacters/MainCharacter.h"
#include "../Entity/MovableCharacters/Enemies/Enemies.h"
#include "../Entity/MovableCharacters/Enemies/Zombie.h"
#include "../Entity/MovableCharacters/Enemies/Ghost.h"
#include "../Entity/MovableCharacters/Enemies/Monster.h"

enum characteristics{
    HP,
    POWER,
    AP
};

class Logger{
public:
    Logger() = default;
    Logger(CageEntity* hero, Cage** array_enemies);
    CageEntity* subscriber_hero = nullptr;
    std::map<characteristics, int> player_stats;
//    std::map<characteristics, int> enemy;
    std::map<CageEntity*, std::vector<int>> enemy_stats;
    //    explicit Logger(CageEntity* cage_entity);
//    Logger(CageEntity** pCageEntities);
    void save_main();
    void save_enemy(CageEntity* enemy_track);
//    virtual void write(const std::string &info);

};