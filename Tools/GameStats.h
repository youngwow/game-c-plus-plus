#pragma once

class GameStats{
private:
    int enemy_killed;
    int steps_made;
public:
    GameStats();
    [[nodiscard]] int getEnemyKilled() const;
    [[nodiscard]] int getStepsMade() const;
    void setEnemyKilled(int number);
    void setStepsMade();
};