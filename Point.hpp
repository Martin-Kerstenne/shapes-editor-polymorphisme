#ifndef POINT_HPP 
#define POINT_HPP

#include <iostream>
#include <istream>
#include "ez-draw++.hpp"
typedef unsigned int uint;

class Point {
    private:
        static const uint size = 5;
        uint x;
        uint y;

    public:
    //---Constructeurs & Destructeurs-----//
        Point(uint x, uint y);
        Point(const Point& p);
        ~Point();

    //---Outils & Méthodes-----//
        uint getX();
        uint getY();
        void setXY(uint _x, uint _y);
        bool isOver(uint mouseX, uint mouseY);
        void draw(EZWindow& w, bool isActive=false) const;

    //---Surcharge d'opérateurs-----//
        friend std::ostream& operator<<(std::ostream& os, Point p);
        friend std::istream& operator>>(std::istream& is, Point& p);
};

#endif