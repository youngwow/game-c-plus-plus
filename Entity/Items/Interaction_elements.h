#pragma once
#include "../CageEntity.h"

class Interaction_elements: public CageEntity{  // нужены деконструкторы к дочерним классам
public:
    virtual void setState(int number) = 0;
    virtual int getState() = 0;
};