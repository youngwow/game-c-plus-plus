#include "Caretaker.h"

Caretaker::Caretaker(Originator *originator) {
    this->originator_ = originator;
}

void Caretaker::Backup(std::string filename, bool flag) {

    if (!flag){
        this->history_.clear();
    }
    this->history_.push_back(this->originator_->save(std::move(filename), flag));
}

void Caretaker::Undo() {
    if (this->history_.empty()) {
        return;
    }
    Memento *memento = this->history_.back();
    this->history_.pop_back();
    try {
        this->originator_->restore(memento);
    } catch (...) {
        //this->Undo();
        return;
    }
}
