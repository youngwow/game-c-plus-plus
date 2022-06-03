#pragma once
#include "../MovableEntity.h"

class Enemies: public MovableEntity{
public:
    virtual void setHealth(int number) = 0;
    virtual void setDamage(int number) = 0;
    [[nodiscard]] virtual int getHealth() const = 0;
    [[nodiscard]] virtual int getDamage() const = 0;
    void fight(MovableEntity* character) override = 0;  // бой
    bool isAlive() override = 0;
    void plusHealth(int number) override = 0;
    friend std::ostream& operator<<(std::ostream& out, const Enemies& enemy);
};