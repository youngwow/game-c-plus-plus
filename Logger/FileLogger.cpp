#include "FileLogger.h"

FileLogger::FileLogger(Logger *logger) {
    this->logger = logger;
    file.open("log.txt");
}

void FileLogger::writeHero(){
    file << "Hero: \n";
    file << "Health was: " << (*logger).player_stats[HP] << "\nDamage was: " << (*logger).player_stats[POWER]
              << "\nArmor was: " << (*logger).player_stats[AP] << "\nHero now: "
              << dynamic_cast<MainCharacter&>(*(*logger).subscriber_hero) << std::endl;
}

void FileLogger::writeEnemy(CageEntity* enemy){
    file << "Enemy: \n";
    file << "Health was: " << (*logger).enemy_stats[enemy][HP] << "\nDamage was: " << (*logger).enemy_stats[enemy][POWER]
              << "\nEnemy now: " << (dynamic_cast<Enemies&>(*enemy)) << std::endl;  // << enemy_t <<
}

FileLogger::~FileLogger() {
    file.close();
}
