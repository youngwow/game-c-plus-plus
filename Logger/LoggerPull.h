#pragma once
#include "ConsoleLogger.h"
#include "FileLogger.h"

class LoggerPull{
public:
    int mode;  // не знаю как сделать иначе
    Logger* mainLogger;
    ConsoleLogger* consoleLogger;
    FileLogger* fileLogger;
    LoggerPull() = default;
    LoggerPull(int mode, CageEntity* hero, Cage** enemies);
    void writeHero() const;
    void writeEnemy(CageEntity* enemy) const;
    ~LoggerPull();
};