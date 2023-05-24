#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include <vector>
#include <iostream>
using namespace std;

namespace ariel {
    class Team {
        private:
            vector<Character*> characters;
            Character* leader_;
            int size;

        public:
            Team(Character* leader);
            void add(Character* cha1);
            virtual void attack(Team* enemy);
            int stillAlive();
            virtual void print();
            int getSize(){
                return (int)characters.size();
            }
            void setSize(int curr){
                this->size = curr;
            }
            Character* getLeader(){
                return this->leader_;
            }
            void setLeader(Character * cha1){
                 this->leader_= cha1;
            }
            virtual int findClosestenemy(Team *enemy , Character* curr);
            vector<Character*> getCharacters(){
                return this->characters;
            }
            Character* findLeader();
            Character* findVictim(Team *other);
            // Destructor to free allocated memory
            virtual ~Team() {
                for (Character* cha1 : this->characters) {
                    delete cha1;
                }
            }
        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;
    };
}
