#include "Enemies.h"

std::ostream& operator<<(std::ostream& out, const Enemies& enemy) {
    out << "\nEnemy info: \nHealth: " << enemy.getHealth() << "\nDamage: " << enemy.getDamage() << "\n";
    return out;
}