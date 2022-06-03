#pragma once
#include <vector>
#include "Cage.h"
#include "View/CageView.h"
#include "../Entity/MovableCharacters/MainCharacter.h"
//#include "Saver/Caretaker.h"

class Field{
private:
    int width;
    int height;
    Cage start;
    Cage finish;
    Cage* arr_enemies[32]{};
    int countEnemies;
    int countEnemiesDied;
    Cage* hero;
    Cage** board;
public:
    Field();  // Field():width(0), height(0), board(nullptr){};
    Field(int w, int h);
    Field(const Field& obj);  // конструктор копирования
    Field& operator=(const Field& obj);  // оператор присванивания с копированием
    Field(Field&& obj) noexcept; // конструктор перемещения
    Field& operator=( Field&& obj) noexcept; // оператор перемещения
    ~Field();
    friend class FieldView;
    friend class Memento;
    template<class... WinChecker> friend class Game;
    [[nodiscard]] bool isCorrectDistStartFinish(Cage start, Cage finish) const;
    [[nodiscard]] Cage generateBorderPoint() const;
    void entry_exit_create();
    void create_hero();
    void moveEntity(const Cage& cell, char dir, int numberEnemy);
    void create_enemies();
    [[nodiscard]] int getCountEnemies() const;
    void create_items() const;
    [[nodiscard]] bool HeroWin() const;
    [[nodiscard]] int getCountEnemiesDied() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
};