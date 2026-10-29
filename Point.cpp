#include "Point.hpp"

using namespace std;

//---Constructeur-----//
Point::Point(uint _x, uint _y)
    : x(_x), y(_y)
{}

//---Constructeur de copie-----//
Point::Point(const Point& p)
    : x(p.x), y(p.y)
{}

//---Destructeur-----//
Point::~Point()
{}

//---Méthodes-----//
uint Point::getX() {
    return x;
}

uint Point::getY() {
    return y;
}

void Point::setXY(uint _x, uint _y) {
    x = _x;
    y = _y;
}

bool Point::isOver(uint mouseX, uint mouseY) {
    return (mouseX <= x+size) && (mouseX >= x-size) && (mouseY <= y+size) && (mouseY >= y-size);
}

void Point::draw(EZWindow& w, bool isActive) const {
    if (isActive)
        w.fillRectangle(x-size, y-size, x+size, y+size);
    else
        w.drawRectangle(x-size, y-size, x+size, y+size);
}

//---Surcharge d'opérateurs-----//
ostream& operator<<(ostream& os, Point p) {
    os << p.x << " " << p.y; 
    return os;
}

istream& operator>>(istream& is, Point& p) { 
    is >> p.x >> p.y;
    return is;
}