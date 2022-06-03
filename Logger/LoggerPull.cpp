#include "LoggerPull.h"

LoggerPull::LoggerPull(int mode, CageEntity *hero, Cage **enemies) {
    this->mode = mode;
    mainLogger = new Logger(hero, enemies);
    if (mode == 0 or mode == 2){
        consoleLogger = new ConsoleLogger(mainLogger);
    }
    if (mode == 1 or mode == 2){
        fileLogger = new FileLogger(mainLogger);
    }
}

void LoggerPull::writeHero() const {
    if (mode == 0 || mode == 2) {
        consoleLogger->writeHero();
    }
    if (mode == 1 || mode == 2) {
        fileLogger->writeHero();
    }
}


void LoggerPull::writeEnemy(CageEntity* enemy) const {
    if (mode == 0 || mode == 2) {
        consoleLogger->writeEnemy(enemy);
    }
    if (mode == 1 || mode == 2) {
        fileLogger->writeEnemy(enemy);
    }
}

LoggerPull::~LoggerPull() {
    delete mainLogger;
    if (mode == 0 || mode == 2) {
        delete consoleLogger;
    }
    if (mode == 1 || mode == 2) {
        delete fileLogger;
    }
}