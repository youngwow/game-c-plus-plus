#pragma once
#include "Enemies.h"

class Monster: public Enemies{
private:
    int health;
    int damage;
public:
    Monster();
    explicit Monster(int h, int d);
    void setHealth(int number) final;
    void setDamage(int number) final;
    [[nodiscard]] int getHealth() const final;
    [[nodiscard]] int getDamage() const final;
    bool isAlive() final;
    void plusHealth(int number) final;
    void fight(MovableEntity* character) final;
//    friend std::ostream& operator<<(std::ostream& out, const Monster& monster);
};