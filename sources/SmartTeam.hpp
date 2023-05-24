#pragma once
#include "Character.hpp"
#include "Team.hpp"
#include <vector>
#include <iostream>
using namespace std;

namespace ariel {
    class SmartTeam : public Team{
        private:
            vector<Character*> characters;
            Character* leader_;

        public:
            SmartTeam(Character* leader);
            int calculateAttackerDamage(Character *enemyFighter);
            // bool compareCharactersByLocation(Character* c1, Character* c2);
            //  bool compareCharactersByLife(Character* c1, Character* c2);
            //  Character* findBestDefender(Character* attacker, Team* defender);
            void attack(Team* enemy) override;
            // int stillAlive();
            // void print()override;

            // Destructor to free allocated memory
            
            
    };
}
