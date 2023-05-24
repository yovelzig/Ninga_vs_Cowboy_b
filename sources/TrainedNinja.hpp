#pragma once
#include "Ninja.hpp"
static const int TRAINED_HIT_POINTS = 120;
static const int TRAINED_SPEED = 12;
namespace ariel{
class TrainedNinja : public Ninja {

    public:
    TrainedNinja(string name,const Point& loc):Ninja(std::move(name),loc){
        this->setSpeed(TRAINED_SPEED);
        this->setPoints(TRAINED_HIT_POINTS);
    };
};
}