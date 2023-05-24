#include "Ninja.hpp"
#include <stdexcept>
#include <typeinfo>
namespace ariel{
    
    void Ninja::move(Character* cha1){
     if (!isAlive() || !cha1->isAlive()) {
            return;
        }
        Point new_location = Point::moveTowards(getLocation(), cha1->getLocation(), speed);
        setLocation(new_location);
        //this->setLocation(this->getLocation().moveTowards(this->getLocation(),cha1->getLocation(),this->speed));
    };
    void Ninja::slash(Character* cha1){
        if (!cha1->isAlive())
        {
            throw std::runtime_error("the enemy is dead");
        }
         else if (cha1 == this)
        {
            throw std::runtime_error("cannot slash himself");
        }
        else if (!this->isAlive())
        {
            throw std::runtime_error("this Character is dead");
        }
        
        else if (this->getLocation().distance(cha1->getLocation()) <= 1 && cha1->isAlive())
        {
            cha1->hit(40);
            if (cha1->getPoints() <= 0 )
            {
                cha1->setPoints(0);
            }
             
        }
        
    };
    string Ninja::print(){
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
        a.append("N ");
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
    };
    
}


