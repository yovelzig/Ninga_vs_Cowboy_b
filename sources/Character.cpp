#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;
namespace ariel{
     Character::Character(string name,Point loc):location(loc){
        this->location = loc;
        this->Name = name;
        this->isleader = false;
     };
   //     Character::~Character() {
        
   //  }
     double Character:: distance(Character* cha1){

      return this->getLocation().distance(cha1->getLocation());};
      void Character::attack(Character& enemy){};
     void Character::hit(int hit){
      if (hit < 0 )
      {
         throw std::invalid_argument("negetive argument cannot be a hit");
      }
      
      this->hitPoint = this->hitPoint - hit;
     };
     
     string Character::print(){return "aa";};
  }
