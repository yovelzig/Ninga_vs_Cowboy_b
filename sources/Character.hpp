#pragma once
// #include <iostream>
#include <string>
#include "Point.hpp"

namespace ariel{
class Character {

private:
    Point location;
    int hitPoint;
    string Name;
    bool isleader;
    
public:

    // Constructor. Also works as a conversion from double and
    // also as a default ctor.
     Character(string name,Point loc);
      Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;
     virtual ~Character() = default; // Destructor
     double distance(Character* cha1);
     void hit(int hit);
     virtual string print();
     Point getLocation(){
        return this->location;
     }
     void setLocation( const Point& curr){
       this->location = curr; 
     }
     string getName(){
        return this->Name;
     }
     bool getisLeader()const{
        return this->isleader;
     }
     void setisLeader(bool curr){
         this->isleader = curr;
     }
     bool isAlive()const{
        return  this->hitPoint > 0 ;
     }
     void setPoints(int hit){
        this->hitPoint = hit;
    }
    int getPoints()const {
      return this->hitPoint;
    }
    virtual void attack(Character& enemy);
  };
}