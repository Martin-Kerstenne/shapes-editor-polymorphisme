#include "Circle.hpp"


//---Constructeurs & Destructeur-----//
Circle::Circle(EZColor col, uint x, uint y, uint _radius)
    : Shape::Shape(col, x, y), radius(_radius)
{}

Circle::Circle(std::istream& is)
    : Shape::Shape(is), radius(10)
{ is >> radius; }

Circle::~Circle() {}


//---Outils & Méthodes-----//

//--Fonctions pour le rayon--//
uint Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(uint r) {
    radius = r;
}

//--Autres fonctions--//
const char* Circle::getTypeName() const {
    return "Circle";
}

void Circle::draw(EZWindow& win) {
    Shape::draw(win);
    if (isFilled())
        win.fillCircle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + radius, getAnchor().getY() + radius);
    else
        win.drawCircle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + radius, getAnchor().getY() + radius);
}

void Circle::write(std::ostream& os) {
    Shape::write(os);
    os << radius;
}

void Circle::modifyAttributes()
{
    char c; int r;
    do
    {
        std::cout << "Current attributes values are:" << std::endl
        << "s : go to the sub-menu for the attributes of the Shape" << std::endl
        << "r - radius = " << getRadius() << std::endl
        << "q - quit or go back one level" << std::endl
        << "To modify an attribute, enter the designated letter." << std::endl
        << "Choice?>"; std::cin >> c;
        switch (c)
        {
            case 's': Shape::modifyAttributes(); break;
            case 'r': std::cout << "Give the new radius value>"; std::cin >> r; setRadius(r); break;
            case 'q': break;
            default:
                std::cout << "Error this choice does not exist. Try again." << std::endl;
        }
    } while (c != 'q');
}