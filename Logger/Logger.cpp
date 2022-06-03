#include "Logger.h"

void Logger::save_main() {
    if (subscriber_hero){
        this->player_stats[HP] = (dynamic_cast<MainCharacter&>(*subscriber_hero)).getHealth();
        this->player_stats[AP] = (dynamic_cast<MainCharacter&>(*subscriber_hero)).getArmor();
        this->player_stats[POWER] = (dynamic_cast<MainCharacter&>(*subscriber_hero)).getPower();
    }
}

Logger::Logger(CageEntity *hero, Cage **array_enemies) {
    subscriber_hero = hero;
    save_main();
    for (int i = 0; array_enemies[i] != nullptr; ++i) {  // ?
        enemy_stats.insert(std::pair<CageEntity*, std::vector<int>>(array_enemies[i]->getEntity(), {0,0}));
        save_enemy(array_enemies[i]->getEntity());
    }
}

void Logger::save_enemy(CageEntity *enemy_track) {
    if (enemy_track){
        this->enemy_stats[enemy_track][0] = (dynamic_cast<Enemies&>(*enemy_track)).getHealth();
        this->enemy_stats[enemy_track][1] = (dynamic_cast<Enemies&>(*enemy_track)).getDamage();
//        this->enemy_stats[enemy_track][2] = (dynamic_cast<Enemies&>(*enemy_track)).getArmor();
    }
}
