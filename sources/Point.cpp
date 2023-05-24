#include "Point.hpp"
#include "math.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
namespace ariel{
  
    
    double Point::distance(const Point& point2)const{
        double x = pow((point2.getX() - this->getX()),2);
        double y = pow((point2.getY() - this->getY()),2);
        return sqrt(x+y);
    }
    void Point::print()const{
        cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
    }
    Point Point::moveTowards(const Point& src ,const Point& dst, double distance) {
    //     if (distance < 0 )
    //     {
    //        throw std::invalid_argument("Invalid argument");
    //     }
        
    // double len = src.distance(dst);

    // if (len == 0) {
    //     return src;
    // }
  
    // double scaleFactor = distance / len;
    // if (len < distance)
    // {
    //     return dst;
    // }
    
    

    // double closestX = src.getX() + (scaleFactor * (dst.getX() - src.getX()));
    // double closestY = src.getY() + (scaleFactor * (dst.getY() - src.getY()));

    // return Point(closestX, closestY);
      if (distance < 0) 
      throw std::invalid_argument("argument must be non-negative");
        double d = src.distance(dst);
        if (d <= distance) {
            return dst;
        } 
        else {
            double dx = dst.getX() - src.getX();
            double dy = dst.getY() - src.getY();
            double factor = distance / d;
            double new_x = src.getX() + dx * factor;
            double new_y = src.getY() + dy * factor;
            return Point(new_x, new_y);
        }
}

}
      
