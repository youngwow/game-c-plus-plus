#pragma once
#include "Logger.h"

class ConsoleLogger: public Logger{
public:
    Logger* logger;
    ConsoleLogger(Logger* logger);
    void writeHero() const;
    void writeEnemy(CageEntity* enemy) const;
};