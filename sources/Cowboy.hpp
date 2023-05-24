#pragma once
#include "Character.hpp"
static const int HIT_POINTS = 110;
static const int BULLETS = 6;
namespace ariel{
class Cowboy : public Character {
    private:
    int bulletAmount;

    public:
    Cowboy(string name,const Point& loc):Character(std::move(name) , loc),bulletAmount(BULLETS) {
        this->setPoints(HIT_POINTS);
        
    };
    ~Cowboy() override = default;
    bool hasboolets()const{
         return bulletAmount > 0;  
    }
    void shoot(Character* cha1);
    void reload();
    string print()override;
     Cowboy(const Cowboy&) = delete;
        Cowboy& operator=(const Cowboy&) = delete;
        Cowboy(Cowboy&&) = delete;
        Cowboy& operator=(Cowboy&&) = delete;
};
}

