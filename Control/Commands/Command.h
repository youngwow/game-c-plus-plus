#pragma once
enum Commands{
    Up,
    Down,
    Left,
    Right
};

class Command{
public:
    virtual char execute() = 0;
    virtual void change(Commands instruction) = 0;
    [[nodiscard]] virtual Commands get_instruction() const = 0;
    virtual ~Command(){

    }
};