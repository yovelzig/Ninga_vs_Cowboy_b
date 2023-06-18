#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;
TEST_CASE("initialization") {
    Point a(6,2),b(8,2),c(5,4);    
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *soso = new TrainedNinja("soso", c);
    YoungNinja *ishimoto = new YoungNinja("ishimoto", a);
    CHECK(a.getX() == 6);
    CHECK(a.getY() == 2);
    CHECK(tom->getName() == "Tom");
    CHECK(tom->getPoints() == 110);
    CHECK(sushi->getName() == "sushi");
    CHECK(soso->getName() == "soso");
    CHECK(sushi->getName() == "ishimoto");
    CHECK(sushi->getPoints() == 150);
    CHECK(soso->getPoints() == 120);
    CHECK(ishimoto->getPoints() == 100);
    CHECK(tom->hasbullets() == true);
    CHECK_NOTHROW(tom->shoot(sushi));
    CHECK_NOTHROW(sushi->move(tom));
    CHECK_NOTHROW(sushi->slash(tom));
    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    CHECK(team_B.getSize()>0);
}
TEST_CASE("check functions") {
    Point a(6,2),b(8,2);    
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    CHECK(a.distance(a) == 0);
    CHECK(b.distance(b) == 0);
    tom->shoot(sushi);
    CHECK(sushi->getPoints() < 150);
    for (int i = 0; i < 4; i++)
    {
        tom->shoot(sushi);
    }
    CHECK(sushi->getPoints() < 145);
    CHECK(tom->hasbullets() == false);
    tom->reload();
    CHECK(tom->hasbullets() == true);
    sushi->move(tom);
    CHECK(sushi->getLocation().distance(b) != 0);
    if (sushi->getLocation().distance(tom->getLocation()) < 100)
    {
        sushi->slash(tom);
        CHECK(tom->getPoints()== 79);
    }
    
    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    CHECK(team_B.getSize()>0);
    
    // CHECK(tom->getName() == "Tom");
    // CHECK(tom->getPoints() == 110);
    // CHECK(sushi->getName() == "sushi");
    // CHECK(sushi->getPoints() == 150);
    // CHECK_NOTHROW();
    // CHECK_NOTHROW(sushi->move(tom));
    // CHECK_NOTHROW(sushi->slash(tom));
    // Team team_B(sushi);
    // team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    // CHECK(team_B.getSize()>0);
}
 TEST_CASE("team functionality") {
     Point a(6,2),b(8,2);    
    Cowboy *tom = new Cowboy("Tom", a);
    CHECK_THROWS(tom->shoot(tom));
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_B(sushi);
    CHECK_THROWS(team_B.add(sushi));
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    CHECK(team_B.getSize() == 2);
    CHECK(team_B.stillAlive() == 2);
    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));
     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
     }
    CHECK(team_B.stillAlive() == 2);
    team_A.add(new YoungNinja("Yog", Point(66,27)));
    team_A.add(new YoungNinja("pgi", Point(64,57)));
    team_A.add(new YoungNinja("zz", Point(22,57)));
    team_A.add(new YoungNinja("cc", Point(33,57)));
    team_A.add(new YoungNinja("bb", Point(44,57)));
    team_A.add(new YoungNinja("mm", Point(55,57)));
    team_A.add(new YoungNinja("kk", Point(66,57)));
    team_A.add(new YoungNinja("ll", Point(77,57)));
    CHECK_THROWS(team_A.add(new YoungNinja("oop", Point(32,57))));
 }
TEST_CASE("check for notThrow error") {
    Point a(6,2),b(8,2);    
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    CHECK_NOTHROW(a.distance(b));
    CHECK_NOTHROW(sushi->getPoints());
    CHECK_NOTHROW(tom->shoot(sushi));
    CHECK_NOTHROW(sushi->move(tom));
    CHECK_NOTHROW(sushi->slash(tom));
    
} 
