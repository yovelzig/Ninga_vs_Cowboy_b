#pragma once
#include "Character.hpp"
#include "Team.hpp"
#include <vector>
using namespace std;

namespace ariel {
    class Team2 : public Team{
     
        public:
            Team2(Character* leader);
            void attack(Team* enemy)override;
            int findClosestenemy(Team *enemy , Character* curr)override;
            void  print() override;
            Character* findLeader();
            Character* findVictim(Team *other);
    };
}
