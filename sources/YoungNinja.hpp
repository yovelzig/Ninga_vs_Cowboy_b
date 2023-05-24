#pragma once
#include "Ninja.hpp"
static const int YOUNG_HIT_POINTS = 100;
static const int YOUNG_SPEED = 14;
namespace ariel{
class YoungNinja : public Ninja {
 
    public:
    YoungNinja(string name,const Point& loc):Ninja(std::move(name),loc){
        this->setSpeed(YOUNG_SPEED);
        this->setPoints(YOUNG_HIT_POINTS);
    };
};
}