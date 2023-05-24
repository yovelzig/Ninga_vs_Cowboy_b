#pragma once
// #include <iostream>
#include <string>
using namespace std;
namespace ariel{
class Point {

private:
    double numA;
    double numB;
    
public:

    // Constructor. Also works as a conversion from double and
    // also as a default ctor.
     Point(double num1,double num2): numA(num1),numB(num2){};
     Point(Point const& other)= default;
     double distance (const Point& point2)const;
     void print()const;
     static Point moveTowards(const Point& src ,const Point& dst ,double distance);
     double getX()const{
        return this->numA;
     }
     double getY()const{
        return this->numB;
     }
      
    ~Point() = default;
    Point& operator=(const Point& other) = default;
    Point(Point&& other) = default;
    Point& operator=(Point&& other) = default;
     
  };
}