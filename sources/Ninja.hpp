#pragma once
#include "Character.hpp"
namespace ariel{
class Ninja : public Character {
    private:
    int speed;

    public:
    Ninja(string name,const Point& loc):Character(std::move(name),loc),speed(0){};
    ~Ninja() override = default;
    void move(Character* cha1);
    void slash(Character* cha1);
    string print()override;
    void setSpeed(int speed){
        this->speed = speed;
    }
     Ninja(const Ninja&) = delete;
        Ninja& operator=(const Ninja&) = delete;
        Ninja(Ninja&&) = delete;
        Ninja& operator=(Ninja&&) = delete;
    
};
}

