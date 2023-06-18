#include "Character.hpp"
#include "Team2.hpp"
#include "Team.hpp"
#include <iostream>
#include <vector>
#include <cfloat>
#include <stdexcept>
using namespace std;

namespace ariel
{

    Team2::Team2(Character *leader) : Team(leader)
    {
        {
            this->setLeader(leader);
            this->setSize(1);
            this->getCharacters().push_back(this->getLeader());
        };
    }
    void Team2::attack(Team *enemy)
    {

        if (enemy == nullptr)
        {
            throw std::invalid_argument("Invalid team pointer - nullptr");
        }
        if (enemy->stillAlive() <= 0)
        {
            throw std::runtime_error("the team is dead");
        }
        if (this->stillAlive() <= 0)
        {
            throw std::runtime_error("the team is dead");
        }
        if (this == enemy)
        {
            throw std::runtime_error("No self harm");
        }

        // Check if leader alive. if not - find new leader.
        if (!this->getLeader()->isAlive())
        {
            Character *newLeader = findLeader();
            if (newLeader)
            {
                this->setLeader(newLeader);
            }
            else
            {
                // No living members in the attacking team, attack ends
                return;
            }
        }

        Character *victim = findVictim(enemy);

        if (victim)
        {
            for (Character *member : this->getCharacters())
            {
                if (member->isAlive())
                {
                    // Check victim still alive. if not - find new victim.
                    if (!victim->isAlive())
                    {
                        victim = findVictim(enemy);
                        if (victim == nullptr)
                            return; // No victims.
                    }
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member))
                    {
                        if (cowboy->hasboolets())
                        {
                            cowboy->shoot(victim);
                        }
                        else
                        {
                            // If cowboy has no bullets - reload.
                            cowboy->reload();
                        }
                    }
                    else if (Ninja *ninja = dynamic_cast<Ninja *>(member))
                    {

                        if (ninja->distance(victim) <= 1.0)
                        {
                            ninja->slash(victim);
                        }
                        else
                        {
                            // If ninja can't attack - get closer.
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }
    
    Character *Team2::findVictim(Team *enemy)
    {
        Character *victim = nullptr;
        double minDistance = DBL_MAX;

        for (Character *cha1 : enemy->getCharacters())
        {

            if (cha1->isAlive())
            {
                double distance = this->getLeader()->distance(cha1);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    victim = cha1;
                }
            }
        }
        return victim;
    }

    Character *Team2::findLeader()
    {

        Character *newLeader = nullptr;
        double minDistance = DBL_MAX;

        for (Character *member : this->getCharacters())
        {

            if (member->isAlive())
            {
                double distance = this->getLeader()->distance(member);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    newLeader = member;
                }
            }
        }

        return newLeader;
    }
    void Team2 ::print()
    {
        for (Character *c : this->getCharacters())
        {
            cout << c->print() << endl;
        }
    };
    int Team2::findClosestenemy(Team *enemy, Character *curr)
    {
        bool mindis = true;
        int index = -1;
        double mindistance = DBL_MAX;
        // Point currentPoint = curr->getLocation();
        // std::cout << enemy->characters.size()<< endl;
        for (size_t i = 0; i < enemy->getCharacters().size(); i++)
        {
            // std::cout << enemy->characters[i]->getName() << endl;
            if (enemy->getCharacters()[i]->isAlive() && mindis)
            {

                mindis = false;
                mindistance = curr->getLocation().distance(enemy->getCharacters()[i]->getLocation());
                index = (int)i;
            }
            if (enemy->getCharacters()[i]->isAlive() && curr->getLocation().distance(enemy->getCharacters()[i]->getLocation()) < mindistance)
            {
                mindistance = curr->getLocation().distance(enemy->getCharacters()[i]->getLocation());
                index = (int)i;
            }
        }
        return index;
    };

}