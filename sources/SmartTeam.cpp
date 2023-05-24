#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>
#include <cfloat>
#include <limits>
using namespace std;

namespace ariel
{

        SmartTeam ::SmartTeam(Character *leader) : Team(leader)
        {
                this->setLeader(leader);
                this->setSize(1);
                this->getCharacters().push_back(this->getLeader());
        };
        int SmartTeam::calculateAttackerDamage(Character *enemyFighter)
        {
                int ninjaDamage = 0;
                int cowboyDamage = 0;

                for (Character *fighter : this->getCharacters())
                {
                        if (fighter != nullptr && fighter->isAlive())
                        {
                                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);

                                if (ninja != nullptr && ninja->distance(enemyFighter) <= 1.0)
                                {
                                        ninjaDamage += 40; // Increment Ninja damage by 40
                                }

                                if (cowboy != nullptr && cowboy->hasboolets())
                                {
                                        cowboyDamage += 10; // Increment Cowboy damage by 10
                                }
                        }
                }

                return ninjaDamage + cowboyDamage + 1;
        }

        void SmartTeam::attack(Team *enemyTeam)
        {
                if (enemyTeam == nullptr || !stillAlive() || !enemyTeam->stillAlive())
                {
                        throw std::runtime_error("Invalid or dead team provided!");
                }

                Character *enemy = nullptr;
                double minDistance = std::numeric_limits<double>::max();
                int minEnemyAttacks = std::numeric_limits<int>::max();
                bool isTie = false;

                for (Character *enemyFighter : enemyTeam->getCharacters())
                {
                        if (enemyFighter != nullptr && enemyFighter->isAlive())
                        {
                                double distance = this->getLeader()->distance(enemyFighter);
                                int enemyAttacks = enemyFighter->getPoints() / calculateAttackerDamage(enemyFighter);

                                if (enemyAttacks < minEnemyAttacks)
                                {
                                        minDistance = distance;
                                        minEnemyAttacks = enemyAttacks;
                                        enemy = enemyFighter;
                                        isTie = false;
                                }
                                else if (enemyAttacks == minEnemyAttacks)
                                {
                                        if (!isTie || distance < minDistance)
                                        {
                                                minDistance = distance;
                                                enemy = enemyFighter;
                                                isTie = true;
                                        }
                                }
                        }
                }

                if (enemy == nullptr || !enemy->isAlive())
                {
                        return;
                }

                for (Character *fighter : this->getCharacters())
                {
                        if (fighter != nullptr && fighter->isAlive())
                        {
                                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                                Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);

                                if (ninja != nullptr && ninja->distance(enemy) <= 1.0)
                                {
                                        ninja->slash(enemy);
                                } 
                                else if (ninja != nullptr && ninja->distance(enemy) > 1.0)
                                {
                                        ninja->move(enemy);
                                }
                                else if (cowboy != nullptr && cowboy->hasboolets())
                                {
                                        cowboy->shoot(enemy);
                                } 
                                else if (cowboy != nullptr && !cowboy->hasboolets())
                                {
                                        cowboy->reload();
                                }
                                else
                                {
                                        // Handle the case when a fighter is neither Ninja nor Cowboy
                                        throw std::runtime_error("Invalid fighter type!");
                                }

                                if (!enemy->isAlive())
                                {
                                        minDistance = std::numeric_limits<double>::max();
                                        for (Character *enemyFighter : enemyTeam->getCharacters())
                                        {
                                                if (enemyFighter != nullptr && enemyFighter->isAlive())
                                                {
                                                        double distance = this->getLeader()->distance(enemyFighter);
                                                        if (distance < minDistance)
                                                        {
                                                                minDistance = distance;
                                                                enemy = enemyFighter;
                                                        }
                                                }
                                        }

                                        if (enemy == nullptr || !enemy->isAlive())
                                        {
                                                return;
                                        }
                                }
                        }
                }

                Character *enemyLeader = enemyTeam->getLeader();

                if (enemyLeader == nullptr || !enemyLeader->isAlive())
                {
                        minDistance = std::numeric_limits<double>::max();
                        for (Character *enemyFighter : enemyTeam->getCharacters())
                        {
                                if (enemyFighter != nullptr && enemyFighter->isAlive())
                                {
                                        double distance = enemyLeader->distance(enemyFighter);
                                        if (distance < minDistance)
                                        {
                                                minDistance = distance;
                                                enemyTeam->setLeader(enemyFighter);
                                        }
                                }
                        }
                }
        }
};
