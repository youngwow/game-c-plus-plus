#include "Memento.h"

// РЕАЛИЗОВАНО СОХРАНЕНИЕ В ФАЙЛ
Memento::Memento(Field* state, std::string filename, bool flag) {
    this->state_ = state;
    this->filename_ = std::move(filename);
    if (flag){
        save_file();
    }
//    save_file();
}
// ВОССТАНОВЛЕНИЕ ИЗ ФАЙЛА
Field* Memento::getState() {
    // std::cout << "filename: " << filename_ << std::endl;
    load_file();
    return this->state_;
}

void Memento::save_file() {
    std::ofstream file;
    file.open(filename_, std::ofstream::trunc);
    file << "height " << state_->getHeight() << std::endl;
    file << "width " << state_->getHeight() << std::endl;
    file << "CountEnemy " << state_->getCountEnemies() << std::endl;
    //file << "CountEnemy " << state_->getCountEnemies() << std::endl;
    file << std::endl;
    for (int i = 0; i < state_->getHeight(); ++i) {
        for (int j = 0; j < state_->getWidth(); ++j) {
            // file << "Cage " << state_->board[i][j].getX() << " " << state_->board[i][j].getY() << std::endl;
            file << "TypeObj " << state_->board[i][j].getTypeObj() << std::endl;
            file << "TypeCage " << state_->board[i][j].getTypeCage() << std::endl;
            if ((dynamic_cast<MainCharacter*>(state_->board[i][j].getEntity()))){
                file << "MainHero" << std::endl;
            }
            else if ((dynamic_cast<Zombie*>(state_->board[i][j].getEntity()))){
                file << "Zombie" << std::endl;
            }
            else if ((dynamic_cast<Ghost*>(state_->board[i][j].getEntity()))){
                file << "Ghost" << std::endl;
            }
            else if ((dynamic_cast<Monster*>(state_->board[i][j].getEntity()))){
                file << "Monster" << std::endl;
            }
            else if ((dynamic_cast<Armor*>(state_->board[i][j].getEntity()))){
                file << "Armor" << std::endl;
            }
            else if ((dynamic_cast<Health*>(state_->board[i][j].getEntity()))){
                file << "Health" << std::endl;
            }
            else if ((dynamic_cast<Weapon*>(state_->board[i][j].getEntity()))){
                file << "Weapon" << std::endl;
            } else{
                file << "nothing" << std::endl;
            };
        }
    }
    file << "MainHeroStats" << std::endl;
    file << (dynamic_cast<MainCharacter*>(state_->hero->getEntity()))->getHealth() << std::endl;
    file << (dynamic_cast<MainCharacter*>(state_->hero->getEntity()))->getPower() << std::endl;
    file << (dynamic_cast<MainCharacter*>(state_->hero->getEntity()))->getArmor() << std::endl;
    for (int i = 0; i < state_->getCountEnemies(); ++i) {
        if ((dynamic_cast<Enemies*>(state_->arr_enemies[i]->getEntity()))) {
            file << "Enemy" << '\n';
        }
        file << "X " << state_->arr_enemies[i]->getX() << '\n';
        file << "Y " << state_->arr_enemies[i]->getY() << '\n';
        file << "EnemyHealth " << (dynamic_cast<Enemies&>(*state_->arr_enemies[i]->getEntity())).getHealth() << std::endl;
        file << "EnemyPower " << (dynamic_cast<Enemies&>(*state_->arr_enemies[i]->getEntity())).getDamage() << std::endl;
    }
    file.close();
}

void Memento::load_file() {
    std::ifstream file;
    file.open(filename_);
    std::string nothing;
    std::string name_enemy;
    int h, w, typeObj, typeCage, HealthHero, ArmorHero, PowerHero, HealthEnemy, PowerEnemy, x, y, countEnemy;
    int x_new_hero , y_new_hero;
    file >> nothing;
    file >> h;
    file >> nothing;
    file >> w;
    file >> nothing;
    file >> countEnemy;
    state_ = new Field(w, h);
    for (int i = 0; i < state_->getCountEnemies(); ++i) {
        state_->arr_enemies[i] = nullptr;
    }

    MainCharacter* newMainCharacter = new MainCharacter();
    Zombie* newZombie = new Zombie();
    Ghost* newGhost = new Ghost();
    Monster* newMonster = new Monster();
    Health* newHealth = new Health();
    Armor* newArmor = new Armor();
    Weapon* newWeapon = new Weapon();
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            state_->board[i][j].setEntity(nullptr);
            file >> nothing;
            file >> typeObj;
            switch (typeObj) {
                case 0:
                    state_->board[i][j].setTypeObj(TypeObj::NOTHING);
                    break;
                case 1:
                    state_->board[i][j].setTypeObj(TypeObj::PLAYER);
                    break;
                case 2:
                    state_->board[i][j].setTypeObj(TypeObj::ENEMY);
                    break;
                case 3:
                    state_->board[i][j].setTypeObj(TypeObj::INTERACTION_ELEMENTS);
                    break;
            }
            file >> nothing;
            file >> typeCage;
            switch (typeCage) {
                case 0:
                    state_->board[i][j].setTypeCage(TypeCage::START);
                    break;
                case 1:
                    state_->board[i][j].setTypeCage(TypeCage::END);
                    break;
                case 2:
                    state_->board[i][j].setTypeCage(TypeCage::PASSABLE);
                    break;
                case 3:
                    state_->board[i][j].setTypeCage(TypeCage::IMPASSABLE);
                    break;
                case 4:
                    state_->board[i][j].setTypeCage(TypeCage::EMPTY);
                    break;
            }
            file >> nothing;
            if (nothing == "MainHero"){
                x_new_hero = i;
                y_new_hero = j;
                state_->board[i][j].setEntity(newMainCharacter);
            }
            else if (nothing == "Zombie"){
                state_->board[i][j].setEntity(newZombie);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
            else if (nothing == "Ghost"){
                state_->board[i][j].setEntity(newGhost);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
            else if (nothing == "Monster"){
                state_->board[i][j].setEntity(newMonster);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
            if (nothing == "Health"){
                state_->board[i][j].setEntity(newHealth);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
            else if (nothing == "Armor"){
                state_->board[i][j].setEntity(newArmor);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
            else if (nothing == "Weapon"){
                state_->board[i][j].setEntity(newWeapon);
                // state_->arr_enemies[i] = &state_->board[i][j];
            }
        }
    }
    file >> nothing;
    file >> HealthHero;
    file >> PowerHero;
    file >> ArmorHero;
    newMainCharacter->setHealth(HealthHero);
    newMainCharacter->setPower(PowerHero);
    newMainCharacter->setArmor(ArmorHero);
    state_->hero = &state_->board[x_new_hero][y_new_hero];
    for (int i = 0; i < countEnemy; ++i) {
        file >> nothing;
        if (nothing == "Enemy"){
            file >> nothing;
            file >> x;
            file >> nothing;
            file >> y;
            state_->arr_enemies[i] = &state_->board[x][y];
        }
        file >> nothing;
        file >> HealthEnemy;
        file >> nothing;
        file >> PowerEnemy;
        dynamic_cast<Enemies*>(state_->board[x][y].getEntity())->setHealth(HealthEnemy);
        dynamic_cast<Enemies*>(state_->board[x][y].getEntity())->setDamage(PowerEnemy);
    }
    file.close();
}
