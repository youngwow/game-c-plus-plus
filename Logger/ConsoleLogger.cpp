#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(Logger *logger) {
    this->logger = logger;
}

void ConsoleLogger::writeHero() const {
    std::cout << "Hero: \n";
    std::cout << "Health was: " << (*logger).player_stats[HP] << "\nDamage was: " << (*logger).player_stats[POWER]
    << "\nArmor was: " << (*logger).player_stats[AP] << "\nHero now: "
     << dynamic_cast<MainCharacter&>(*(*logger).subscriber_hero) << std::endl;
}

void ConsoleLogger::writeEnemy(CageEntity *enemy) const {

    std::cout << "Enemy: \n";
    std::cout << "Health was: " << (*logger).enemy_stats[enemy][HP] << "\nDamage was: " << (*logger).enemy_stats[enemy][POWER]
              << "\nEnemy now: " << (dynamic_cast<Enemies&>(*enemy)) << std::endl;  // << enemy_t <<
}