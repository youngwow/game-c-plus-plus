#include "Originator.h"

Originator::Originator(Field* state) {
    this->state_ = state;
}

Memento *Originator::save(std::string filename, bool flag) {
    return new Memento(this->state_, std::move(filename), flag);
}

void Originator::restore(Memento *memento) {
    this->state_ = memento->getState();
}

Field *Originator::getField() {
    return this->state_;
}

