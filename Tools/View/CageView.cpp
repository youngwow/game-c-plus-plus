#include "CageView.h"
#include <iostream>
#include <map>
#include <string>

CageView::CageView(Cage &obj): cell(obj){}

void CageView::printObj() const {
    std::map<TypeCage, std::string> outCage;
    std::map<TypeObj, std::string> out;  // можно ли использовать контейнер string?
    std::map<TypeItems, std::string> out_items;  // можно ли использовать контейнер string?
    std::map<TypeEnemy, std::string> out_enemy;  // можно ли использовать контейнер string?
    out[TypeObj::NOTHING] = "[ ]";
    out[TypeObj::PLAYER] = "[P]";
    out[TypeObj::ENEMY] = "[E]";
    out[TypeObj::INTERACTION_ELEMENTS] = "[I_E]";
    out_items[TypeItems::WEAPON] = "[W]";
    out_items[TypeItems::ARMOR] = "[A]";
    out_items[TypeItems::HEALTH] = "[H]";
    out_items[TypeItems::ARMOR] = "[A]";
    out_enemy[TypeEnemy::Zombies] = "[Z]";
    out_enemy[TypeEnemy::Ghosts] = "[G]";
    out_enemy[TypeEnemy::Monsters] = "[M]";
    outCage[TypeCage::END] = "[F]";
    outCage[TypeCage::START] = "[S]";
    if (cell.entity){
        if (typeid(*cell.entity).name() == typeid(Weapon).name()){
            std::cout << out_items[TypeItems::WEAPON];
        } else if (typeid(*cell.entity).name() == typeid(MainCharacter).name()){
            std::cout << out[TypeObj::PLAYER];
        } else if (typeid(*cell.entity).name() == typeid(Health).name()){
            std::cout << out_items[TypeItems::HEALTH];
        } else if (typeid(*cell.entity).name() == typeid(Armor).name()){
            std::cout << out_items[TypeItems::ARMOR];
        } else if (typeid(*cell.entity).name() == typeid(Zombie).name()){
            std::cout << out_enemy[TypeEnemy::Zombies];
        } else if (typeid(*cell.entity).name() == typeid(Ghost).name()){
            std::cout << out_enemy[TypeEnemy::Ghosts];
        } else if (typeid(*cell.entity).name() == typeid(Monster).name()) {
            std::cout << out_enemy[TypeEnemy::Monsters];
        }
    }
    else{
        if (cell.getTypeCage() == TypeCage::END){
            std::cout << outCage[TypeCage::END];
        } else if (cell.getTypeCage() == TypeCage::START){
            std::cout << outCage[TypeCage::START];
        }
        else{
            std::cout << out[cell.getTypeObj()];
        }
    }

}

void CageView::printCage() const {
    std::map<TypeCage, std::string> out;  // можно ли использовать контейнер string?
    out[TypeCage::START] = "[START]";
    out[TypeCage::END] = "[END]";
    out[TypeCage::PASSABLE] = "[PASS]";
    out[TypeCage::EMPTY] = "[EMPTY]";
    std::cout << out[cell.getTypeCage()];
}