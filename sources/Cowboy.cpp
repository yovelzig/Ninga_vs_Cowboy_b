#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <typeinfo>
#include <stdexcept>
#include <string>
namespace ariel{

    void Cowboy:: shoot(Character* cha1){
         if (!cha1->isAlive())
        {
            throw std::runtime_error("the enemy is dead");
        }
         if (!this->isAlive())
        {
            throw std::runtime_error("the cowboy is dead so he cannot shoot");
        }
         if (cha1 == this)
        {
            throw std::runtime_error("cannot shoot himself");
        }
        else if (this->hasboolets() && cha1->isAlive())
        {
            cha1->setPoints(cha1->getPoints()-10);
            if (cha1->getPoints() <= 0 )
            {
                cha1->setPoints(0);
            }
                     }
        this->bulletAmount -= 1;
    };
    void Cowboy::reload(){
         if (!this->isAlive())
        {
            throw std::runtime_error("the cowboy is dead so he cannot reload");
        }
        this->bulletAmount = 6;
    };
    string Cowboy:: print(){
        string a = "";
        if (this->isAlive()) {
        a.append(this->getName());
        a.append(" , ");
        a.append(std::to_string(this->getPoints()));
        a.append(" , ");
        a.append("(");
        a.append(std::to_string(this->getLocation().getX()));
        a.append(" , ");
        a.append(std::to_string(this->getLocation().getY()));
        a.append(")");
    }
    else
    {
        a.append("C ");
        a.append("(");
        a.append(this->getName());
        a.append(")");
        a.append(" , ");
        a.append("(");
        a.append(std::to_string(this->getLocation().getX()));
        a.append(" , ");
        a.append(std::to_string(this->getLocation().getY()));
        a.append(")");
    }
    
    return a;
    // if (typeid(*character2) == typeid(Cowboy)) {
    //     std::cout << "character2 is a Cowboy" << std::endl;
    // } 
    // else if (typeid(*character2) == typeid(Ninja)) {
    //     std::cout << "character2 is a Ninja" << std::endl;
    // }
        };
}


