#include "Square.hpp"


//---Constructeurs & Destructeur-----//
Square::Square(EZColor _col, uint x, uint y, uint size)
    : Shape::Shape(_col, x, y), size(size)
{}

Square::Square(std::istream& is)
    : Shape::Shape(is), size(10)
{ is >> size; }

Square::~Square() 
{}


//---Outils & Méthodes-----//

//--Fonctions pour le côté--//
uint Square::getSize() const {
    return size;
}

void Square::setSize(uint s) {
    size = s;
}

//--Autres fonctions--//
const char* Square::getTypeName() const {
    return "Square";
}

void Square::draw(EZWindow& win) {
    Shape::draw(win);
    if (isFilled())
        win.fillRectangle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + size, getAnchor().getY() + size);
    else
        win.drawRectangle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + size, getAnchor().getY() + size);
}

void Square::write(std::ostream& os) {
    Shape::write(os);
    os << size;
}

void Square::modifyAttributes()
{
    char c; int s;
    do
    {
        std::cout << "Current attributes values are:" << std::endl
        << "s : go to the sub-menu for the attributes of the Shape" << std::endl
        << "c - size = " << getSize() << std::endl
        << "q - quit or go back one level" << std::endl
        << "To modify an attribute, enter the designated letter." << std::endl
        << "Choice?>"; std::cin >> c;
        switch (c)
        {
            case 's': Shape::modifyAttributes(); break;
            case 'c': std::cout << "Give the new size value>"; std::cin >> s; setSize(s); break;
            case 'q': break;
            default:
                std::cout << "Error this choice does not exist. Try again." << std::endl;
        }
    } while (c != 'q');
}