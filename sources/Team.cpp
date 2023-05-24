#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <vector>
#include <cfloat>
#include <stdexcept>
using namespace std;

namespace ariel
{
        Team ::Team(Character *leader)
        {
                if (leader->getisLeader()== true)
                {
                        throw std::runtime_error("he is already a leader");
                }
                
                this->leader_ = leader;
                this->leader_->setisLeader(true);
                this->size = 1;
                this->characters.push_back(leader_);
        };
        int Team ::stillAlive()
        {
                 int count = 0;
                  for (Character* c : this->characters) {
                    if (c->isAlive())
                        {
                                count++;
                        }
                }
                this->size = count;
                return this->size;
        }
        void Team ::add(Character *cha1)
        {
                if (this->characters.size() >= 10)
                {
                        throw std::runtime_error("the team is full");
                }
                else if (cha1->getisLeader())
                {
                         throw std::runtime_error("the player already in a team");
                }
                else if (cha1 == nullptr)
                {
                         throw std::runtime_error("the player doesnt exist");
                }
                
                else
                {
                        this->characters.push_back(cha1);
                        this->size++;
                        cha1->setisLeader(true);
                }
        };
        void Team::attack(Team *enemy){
       
        if (enemy == nullptr){
                        throw std::invalid_argument("Invalid team pointer - nullptr");
                }
                if (enemy->stillAlive() <= 0)
                {
                        throw std::runtime_error("the team is dead");
                }
                 if (this->stillAlive()<=0)
                {
                        throw std::runtime_error("the team is dead");
                }
                 if (this == enemy){
                        throw std::runtime_error("No self harm");
                }

        // Check if leader alive. if not - find new leader.
        if (!this->leader_->isAlive()) {
            Character* newLeader = findLeader();
            if (newLeader) {
                this->leader_ = newLeader;
            }
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

       
        Character* victim = findVictim(enemy);

        if (victim) { 
            for (Character* member : this->characters) {
                if (member->isAlive()) {
                    // Check victim still alive. if not - find new victim.
                    if (!victim->isAlive()) {
                        victim = findVictim(enemy);
                        if (victim == nullptr) return; // No victims.
                    }
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(victim);
                        } else {
                            // If cowboy has no bullets - reload.
                            cowboy->reload();
                        }
                    }
                }
            }
            for (Character* member : this->characters) {
                if (member->isAlive()) {
                    if (!victim->isAlive()) {
                        victim = findVictim(enemy);
                    }
                    if (victim == nullptr) return;
                    if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                        if (ninja->distance(victim) <= 1.0) {
                            ninja->slash(victim);
                        }
                        else {
                            // If ninja can't attack - get closer.
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }
        void Team ::print() { 
                 for (Character* c : characters) {
                        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(c))
                        {
                                cout << c->print() << endl;
                        }                   
                }
                for (Character* c : characters) {
                     if (Ninja *ninja = dynamic_cast<Ninja *>(c))
                        {
                                cout << c->print() << endl;
                        } 
                }
                 };
        int Team::findClosestenemy(Team *enemy, Character* curr)
        {
                // cout << "CCCCCCCCC" << endl;
                if (enemy == nullptr)
                {
                        return -1;
                }
                if (curr == nullptr)
                {
                        return -1;
                }
                // cout << "PPPPPPP" << endl;
                bool mindis = true;
                int index =-1;
                double mindistance = DBL_MAX;
                // Point currentPoint = curr->getLocation();
                // std::cout << enemy->characters.size()<< endl;
                for (size_t i = 0; i < enemy->characters.size(); i++)
                {
                        // std::cout << enemy->characters[i]->getName() << endl;
                        // cout << "XXXXXX" << endl;
                        
                        if( Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy->characters[i])){
                                // cout << "AAAAA" << endl;
                        if (enemy->characters[i]->isAlive() && mindis)
                        {
                                // cout << "ZZZZZ" << endl;
                                mindis = false;
                                mindistance = curr->getLocation().distance(enemy->characters[i]->getLocation());
                                index = (int)i;
                        }
                        // cout << "NNNNNN" << endl;
                        if (enemy->characters[i]->isAlive() && curr->getLocation().distance(enemy->characters[i]->getLocation()) < mindistance)
                        {
                                // cout << "JJJJ" << endl;
                                mindistance = curr->getLocation().distance(enemy->characters[i]->getLocation());
                                index = (int)i;
                        }
                        // cout << "MMMMM" << endl;
                        }
                        
                }
                //  cout << "KKKKK" << endl;
                 for (size_t i = 0; i < enemy->characters.size(); i++)
                {
                        if(Ninja *ninja = dynamic_cast<Ninja *>(enemy->characters[i])){
                        // std::cout << enemy->characters[i]->getName() << endl;
                        if (enemy->characters[i]->isAlive() && mindis)
                        {

                                mindis = false;
                                mindistance = curr->getLocation().distance(enemy->characters[i]->getLocation());
                                index = (int)i;
                        }
                        if (enemy->characters[i]->isAlive() && curr->getLocation().distance(enemy->characters[i]->getLocation()) < mindistance)
                        {
                                mindistance = curr->getLocation().distance(enemy->characters[i]->getLocation());
                                index = (int)i;
                        }
                        }
                }
                // cout << "GGGGGG" << endl;
                return index;
                
        }
          Character* Team::findVictim(Team *enemy) {
        Character* victim = nullptr;
        double minDistance = DBL_MAX;

        for (Character* enemy : enemy->characters) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy)) {
                if (cowboy->isAlive()) {
                    double distance = leader_->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        victim = cowboy;
                    }
                }
            }
        }
        for (Character* enemy : enemy->characters) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(enemy)) {
                if (ninja->isAlive()) {
                    double distance = leader_->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        victim = ninja;
                    }
                }
            }
        }
        return victim;
    }

    // Find leader - iterates over cowboys and then ninjas.
    Character* Team::findLeader() {
        // Find the nearest living character to be the new leader
        Character* newLeader = nullptr;
        double minDistance = DBL_MAX;

        for (Character* member : this->characters) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                if (cowboy->isAlive()) {
                    double distance = this->getLeader()->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = cowboy;
                    }
                }
            }
        }
        for (Character* member : this->characters) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(member)) {
                if (ninja->isAlive()) {
                    double distance = this->getLeader()->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = ninja;
                    }
                }
            }
        }
        return newLeader;
    }
};
