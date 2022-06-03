#pragma once
#include "Logger.h"

class FileLogger: public Logger{
private:
    std::ofstream file;
public:
    Logger* logger;
    FileLogger(Logger* logger);
    void writeHero();
    void writeEnemy(CageEntity* enemy);
    ~FileLogger();
};