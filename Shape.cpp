#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "Ellipse.hpp"
#include "Label.hpp"

using namespace std;

//---Constructeurs & Destructeur-----//
Shape::Shape(EZColor _color, uint x, uint y)
    : color(_color), filled(false), thickness(1), anchor(x, y)
{}

Shape::Shape(istream& is)
    : color(EZColor::black), filled(false), thickness(1), anchor(0, 0)
{
    uint x, y;
    is >> color >> x >> y >> filled >> thickness;
    anchor.setXY(x, y);
}

Shape::~Shape()
{}

//---Fonctions pour la couleur-----//
EZColor Shape::getColor() {
    return color;
}

void Shape::setColor(EZColor _color) {
    color = _color;
}


//---Fonctions pour l'ancre-----//
Point Shape::getAnchor() {
    return anchor;
}

void Shape::setAnchor(uint x, uint y) {
    anchor.setXY(x, y);
}



//---Fonctions pour le remplissage-----//
bool Shape::isFilled() {
    return filled;
}

void Shape::setFilled(bool new_value) {
    filled = new_value;
}


//---Fonctions pour l'épaisseur-----//
uint Shape::getThickness() const {
    return thickness;
}

void Shape::setThickness(uint _thickness) {
    thickness = _thickness;
}


//---Autres fonctions-----//
bool Shape::isOver(uint mouseX, uint mouseY) {
    return anchor.isOver(mouseX, mouseY);
}

void Shape::draw(EZWindow& win) {
    win.setColor(color);
    win.setThick(thickness);
}


void Shape::write(ostream& os) {
    os << color << " " << anchor.getX() << " " << anchor.getY() << " " << filled << " " << thickness << " ";
}


Shape* Shape::load(istream& is) {
    string typeName;
    is >> typeName;
    if(typeName == "Rectangle") 
        return new Rectangle(is);

    else if (typeName == "Circle")
        return new Circle(is);

    else if (typeName == "Square")
        return new Square(is);

    else if (typeName == "Ellipse")
        return new Ellipse(is);

    else if (typeName == "Label")
        return new Label(is);

    else 
        return nullptr;
}


ostream& operator<<(ostream& os, Shape& s) {
    os << s.getTypeName() << " ";
    s.write(os);
    return os;
}




EZColor ask_color() 
{
  EZColor color;
  std::cout << "Please use the following values:" << std::endl
    << EZColor::black   << " for black" << std::endl
    << EZColor::white   << " for white" << std::endl
    << EZColor::grey    << " for grey" << std::endl
    << EZColor::red     << " for red" << std::endl
    << EZColor::green   << " for green" << std::endl
    << EZColor::blue    << " for blue" << std::endl
    << EZColor::yellow  << " for yellow" << std::endl
    << EZColor::cyan    << " for cyan" << std::endl
    << EZColor::magenta << " for magenta" << std::endl
    << "or type any other color using the HTML RGB two digits hexadecimal notation ('#RRGGBB')"
    << "Choice ?>"; std::cin >> color;
    return color;
}

void Shape::modifyAttributes()
{
  char c; int x,y;
  do
  {
    std::cout << "Current attributes values are:" << std::endl
    << "c - color     = " << getColor() << std::endl
    << "a - anchor    = " << getAnchor() << std::endl
    << "f - filled    = " << (isFilled()?"true":"false") << std::endl
    << "t - thickness = " << getThickness() << std::endl
    << "q - quit or go back one level" << std::endl
    << "To modify an attribute, enter the designated letter." << std::endl
    << "Choice?>"; std::cin >> c;
    switch(c)
    {
      case 'c': setColor(ask_color()); break;
      case 'a': std::cout << "Give the new x and y values separated by a space>"; std::cin >> x >> y; setAnchor(x,y); break;
      case 'f':
      {
        char res;
        std::cout << "Should the shape be filled (y/n)?>"; std::cin >> res; setFilled(res=='y');
      }
      break;
      case 't': std::cout << "Give the new thickness value>"; std::cin >> x; setThickness(x); break;
      case 'q': break;
      default:
        std::cout << "Error this choice does not exist. Try again." << std::endl;
    }
  } while(c!='q');
}