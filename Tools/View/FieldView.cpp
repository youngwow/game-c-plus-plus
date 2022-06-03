#include "FieldView.h"

FieldView::FieldView(Field &obj): grid(obj){
}

void FieldView::printField() const{
    for (int i = 0; i < grid.height; i++) {
        for (int j = 0; j < grid.width; j++) {
            CageView tmpCage(this->grid.board[i][j]);
            tmpCage.printCage();
        }
        std::cout << "\n";
    }
}

void FieldView::printFieldObj() const {
    for (int i = 0; i < grid.height; i++) {
        for (int j = 0; j < grid.width; j++) {
            CageView tmpCage(this->grid.board[i][j]);
            tmpCage.printObj();
        }
        std::cout << "\n";
    }
}