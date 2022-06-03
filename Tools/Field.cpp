#include "Field.h"
#include <iostream>
#include <cstdlib>


Field::Field() {
    this->width = 0;
    this->height = 0;
    this->board = nullptr;
    this->hero = nullptr;
    this->countEnemies = 0;
    this->countEnemiesDied = 0;
}

Field::Field(int w, int h){
    this->hero = nullptr;
    this->countEnemies = 0;
    this->countEnemiesDied = 0;
    if (w < 2 and h < 2){
        w = 2;
        h = 2;
    }
    this->width = w;
    this->height = h;
    board = new Cage * [height];
    for (int i = 0; i < height; i++) {
        board[i] = new Cage[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            board[i][j] = Cage(i, j);  // Cage(i, j)
            board[i][j].setTypeCage(TypeCage::EMPTY);
            board[i][j].setTypeObj(TypeObj::NOTHING);
        }
    }
    entry_exit_create();
    create_hero();  // инизализация hero нах-ся в этой ф-ии
    create_enemies();
    create_items();
}

Field::~Field(){
    //array_destroyer(board, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; ++j) {
            delete board[i][j].getEntity();  // board[j][i].entity;
        }
        delete [] board[i];
    }
    delete [] board;
}

Field::Field(const Field& obj):width(obj.width), height(obj.height){
    hero = obj.hero;
    start = obj.start;
    finish = obj.finish;
    countEnemies = obj.countEnemies;
    countEnemiesDied = obj.countEnemiesDied;
    board = new Cage * [height];
    for (int i = 0; i < height; ++i) {
        board[i] = new Cage[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j] = Cage(i, j);
            // prev: board[i][j].setTypeCage(typesCage[obj.board[i][j].getTypeCage()]);
            // prev: board[i][j].setTypeObj(typesObj[obj.board[i][j].getTypeObj()]);
            board[i][j].setTypeCage(obj.board[i][j].getTypeCage());
            board[i][j].setTypeObj(obj.board[i][j].getTypeObj());
        }
    }
}


Field& Field::operator=(const Field& obj){
    // исправить костыли (исправлено)
    //TypeCage typesCage[5] = {TypeCage::START, TypeCage::END, TypeCage::PASSABLE, TypeCage::IMPASSABLE, TypeCage::EMPTY};
    //TypeObj typesObj[4] = {TypeObj::NOTHING, TypeObj::PLAYER, TypeObj::ENEMY, TypeObj::INTERACTION_ELEMENTS};

    if (this != &obj){
        for (int i = 0; i < height; ++i) {
            delete[] board[i];
        }
        delete[] board;
        width = obj.width;
        height = obj.height;
        start = obj.start;
        finish = obj.finish;
        hero = obj.hero;
        countEnemies = obj.countEnemies;
        countEnemiesDied = obj.countEnemiesDied;
        board = new Cage * [height];
        for (int i = 0; i < height; ++i) {
            board[i] = new Cage[width];
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                board[i][j] = Cage(j, i);  // Cage(j, i)
                board[i][j].setTypeCage(obj.board[i][j].getTypeCage());
                board[i][j].setTypeObj(obj.board[i][j].getTypeObj());
//                board[i][j].setTypeCage(typesCage[obj.board[i][j].getTypeCage()]);
//                board[i][j].setTypeObj(typesObj[obj.board[i][j].getTypeObj()]);
            }
        }
    }
    return *this;
}

Field::Field(Field&& obj) noexcept{
    std::swap(width, obj.width);
    std::swap(height, obj.height);
    std::swap(start, obj.start);
    std::swap(finish, obj.finish);
    std::swap(board, obj.board);
    std::swap(hero, obj.hero);
    std::swap(countEnemies, obj.countEnemies);
    std::swap(countEnemiesDied, obj.countEnemiesDied);
}

Field& Field::operator=( Field&& obj) noexcept {
    if (this != &obj){
        std::swap(width, obj.width);
        std::swap(height, obj.height);
        std::swap(start, obj.start);
        std::swap(finish, obj.finish);
        std::swap(board, obj.board);
        std::swap(hero, obj.hero);
        std::swap(countEnemies, obj.countEnemies);
        std::swap(countEnemiesDied, obj.countEnemiesDied);
    }
    return *this;
}

//Cage** Field::getField() const{
//    return this->board;
//}

bool Field::isCorrectDistStartFinish(Cage start, Cage finish) const{
    int distStartFinish = std::max(((width + height) / 2), 2);
    return abs(start.getX() - finish.getX()) +
           abs(start.getY() - finish.getY()) >= distStartFinish;
}

Cage Field::generateBorderPoint() const {
    switch (rand() % 4) {
        case 0:
            return {0,
                    rand() % height};
        case 1:
            return {this->width - 1,
                    rand() % height};
        case 2:
            return {rand() % width,
                    0};
        case 3:
            return {rand() % width,
                    this->height - 1};
    }
    return {0, 0};
}

void Field::entry_exit_create() {
    srand(time(nullptr));
    while (!isCorrectDistStartFinish(this->start, this->finish)) {
        this->start = generateBorderPoint();
        this->finish = generateBorderPoint();
    }
    this->board[this->start.getX()][this->start.getY()].setTypeCage(TypeCage::START);
    this->board[this->finish.getX()][this->finish.getY()].setTypeCage(TypeCage::END);
}

void Field::create_hero() {  // стоит ли менять деконструктор?
    auto* Hero = new MainCharacter;
    // лишние this?
    this->board[this->start.getX()][this->start.getY()].entity = Hero;  // prev: ... .setEntity(Hero), но появляется баг
    this->hero = &board[this->start.getX()][this->start.getY()];        // который в таблице Objectов ставит start - pass
}

void Field::moveEntity(const Cage& cell, char dir, int numberEnemy = 0) {
    int x, y;
    bool flag = false;
    switch (dir) {
        case 'W':
            if (cell.getX() != 0){
                x = cell.getX() - 1;
                y = cell.getY();
                flag = true;
            }
            break;
        case 'S':
            if (cell.getX() != this->width - 1){
                x = cell.getX() + 1;
                y = cell.getY();
                flag = true;
            }
            break;
        case 'A':
            if (cell.getY() != 0){
                x = cell.getX();
                y = cell.getY() - 1;
                flag = true;
            }
            break;
        case 'D':
            if (cell.getY() != this->height - 1){
                x = cell.getX();
                y = cell.getY() + 1;
                flag = true;
            }
            break;
        default:
            x = cell.getX();
            y = cell.getY();
            flag = false;
            break;
    }
    if (flag){
        if (typeid(*cell.entity).name() == typeid(MainCharacter).name()){
            if (this->board[x][y].getEntity() != nullptr){
                // нужна проверка на то, что это не враг
                auto tmp = typeid(*board[x][y].entity).name();
//                std::cout << tmp << "\n";
                auto* enemy = dynamic_cast<Enemies*>(this->board[x][y].getEntity());  // auto? , возможно стоит занести в else
                auto* player = dynamic_cast<MainCharacter*>(cell.getEntity());
                // поменять условие
                if (tmp != typeid(Zombie).name() and tmp != typeid(Ghost).name() and tmp != typeid(Monster).name()){
                    if (tmp == typeid(Weapon).name() or tmp == typeid(Health).name() or tmp == typeid(Armor).name()){
                        (dynamic_cast<MainCharacter&>(*hero->entity).TakeItem(board[x][y].getEntity()));  // ? // pr &board[x][y]
                    }
                    // подумать как избежать дублирование кода
                    this->board[x][y].entity = cell.getEntity();
                    this->board[x][y].setTypeObj(TypeObj::PLAYER);
                    this->board[cell.getX()][cell.getY()].entity = nullptr;
                    this->board[cell.getX()][cell.getY()].setTypeObj(TypeObj::NOTHING);
                    hero = &board[x][y];
                } else{
                    player->fight(enemy); // dynamic_cast<MainCharacter*>(cell.entity)->fight(enemy)
                    enemy->fight(player);  // dynamic_cast<Enemies*>(this->board[x][y].entity)->fight(player);;
                    if (!enemy->isAlive()){
                        this->board[x][y].entity = cell.getEntity();
                        this->board[x][y].setTypeObj(TypeObj::PLAYER);
                        this->board[cell.getX()][cell.getY()].entity = nullptr;
                        this->board[cell.getX()][cell.getY()].setTypeObj(TypeObj::NOTHING);
                        hero = &board[x][y];
                        countEnemiesDied += 1;
                    }
                }

            } else{
                this->board[x][y].entity = cell.getEntity();
                this->board[x][y].setTypeObj(TypeObj::PLAYER);
                this->board[cell.getX()][cell.getY()].entity = nullptr;
                this->board[cell.getX()][cell.getY()].setTypeObj(TypeObj::NOTHING);
                hero = &board[x][y];
            }
        } else{  // прописать, чтобы враги тоже наносили урон, когда идут на игрока
            if (board[x][y].entity != nullptr){
                auto tmp = typeid(*board[x][y].entity).name();
                if (tmp != typeid(MainCharacter).name() and tmp != typeid(Zombie).name() and tmp != typeid(Ghost).name()
                and tmp != typeid(Monster).name()){
                    board[x][y].entity = cell.getEntity();
                    board[cell.getX()][cell.getY()].entity = nullptr;
                    arr_enemies[numberEnemy] = &board[x][y];
                }
            } else{
                board[x][y].entity = cell.getEntity();
                board[cell.getX()][cell.getY()].entity = nullptr;
                arr_enemies[numberEnemy] = &board[x][y];
            }
        }
//        }
    }
}

void Field::create_enemies() {  // подумать как сделать лучше

    for (int i = 0; i < (this->height * this->width / 20) + 1; ++i) {
        bool created = false;
        while (!created){
            int x = std::rand() % width;
            int y = std::rand() % height;
            if (this->board[x][y].getTypeCage() == TypeCage::EMPTY and this->board[x][y].getEntity() == nullptr){  // необходимо дополнить условие!!
                countEnemies++;
                if ((i % 3) == 0){
                    auto* modelZombie = new Zombie;
                    // std::cout << "hi";
                    this->board[x][y].setEntity(modelZombie);
                    this->arr_enemies[i] = &this->board[x][y];
                    created = true;
                } else if ((i % 3) == 1){
                    auto * modelGhost = new Ghost;
                    this->board[x][y].setEntity(modelGhost);
                    this->arr_enemies[i] = &this->board[x][y];
                    created = true;
                } else if ((i % 3) == 2){
                    auto* modelMonster = new Monster;
                    this->board[x][y].setEntity(modelMonster);
                    this->arr_enemies[i] = &this->board[x][y];
                    created = true;
                }
            }
        }
    }
}

int Field::getCountEnemies() const {
    return this->countEnemies;
}

void Field::create_items() const {
    for (int i = 0; i < (this->height * this->width / 15) + 1; ++i) {
        bool created = false;
        while (!created){
            int x = rand() % width;
            int y = rand() % height;
            if (this->board[x][y].getTypeCage() == TypeCage::EMPTY and this->board[x][y].getEntity() == nullptr){
                if ((i % 3) == 0){
                    auto* modelWeapon = new Weapon;
                    modelWeapon->setState(40);
                    this->board[x][y].setEntity(modelWeapon);
                    created = true;
                } else if ((i % 3) == 1){
                    auto* modelHealth = new Health;
                    modelHealth->setState(100);
                    this->board[x][y].setEntity(modelHealth);
                    created = true;
                } else if ((i % 3) == 2){
                    auto* modelArmor = new Armor;
                    modelArmor->setState(30);
                    this->board[x][y].setEntity(modelArmor);
                    created = true;
                }
            }
        }
    }
}

bool Field::HeroWin() const {
    if (this->board[hero->getX()][hero->getY()].getTypeCage() == TypeCage::END){
        return true;
    } else{
        return false;
    }
}

int Field::getCountEnemiesDied() const {
    return this->countEnemiesDied;
}

int Field::getWidth() const {
    return this->width;
}

int Field::getHeight() const {
    return this->height;
}
