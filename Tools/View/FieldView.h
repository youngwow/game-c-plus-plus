#pragma once
#include "../Field.h"

class FieldView{
private:
    Field& grid;
public:
    explicit FieldView(Field& obj);
    void printField() const;
    void printFieldObj() const;
};