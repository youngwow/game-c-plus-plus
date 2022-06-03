#pragma once
#include "../CageEntity.h"

class MovableEntity: public CageEntity{
public:
    virtual void fight(MovableEntity* character) = 0;  // бой
    virtual bool isAlive() = 0;
    virtual void plusHealth(int number) = 0;
//    virtual int getState() = 0;
//    virtual void setState(int number) = 0;
};