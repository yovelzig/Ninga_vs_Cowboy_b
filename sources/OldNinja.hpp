#pragma once
#include "Ninja.hpp"
static const int OLD_HIT_POINTS = 150;
static const int OLD_SPEED = 8;
namespace ariel{
class OldNinja : public Ninja {

    public:
    OldNinja(string name,const Point& loc):Ninja(std::move(name),loc){
        this->setSpeed(OLD_SPEED);
        this->setPoints(OLD_HIT_POINTS);
    };
};
}