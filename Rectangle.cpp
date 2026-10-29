#include "Rectangle.hpp"


//---Constructeurs & destructeurs-----//
Rectangle::Rectangle(EZColor _col, uint x, uint y, uint _width, uint _height)//les paramètres
    : Shape::Shape(_col,x,y), width(_width), height(_height) 
{}

Rectangle::Rectangle(std::istream& is)
  : Shape::Shape(is), width(10),height(10)
{is>>width>>height;}

Rectangle::~Rectangle() 
{}

//--Fonctions pour la largeur--//
uint Rectangle::getWidth() { 
  return width; 
}

void Rectangle::setWidth(uint w) {
  width = w; 
}

//--Fonctions pour la hauteur--//
uint Rectangle::getHeight() { 
  return height; 
}
void Rectangle::setHeight(uint h) { 
  height = h; 
}

void Rectangle::draw(EZWindow& win) {
    Shape::draw(win);
    if(isFilled())
        win.fillRectangle(getAnchor().getX(), getAnchor().getY(),getAnchor().getX()+width,getAnchor().getY()+height);
    else
        win.drawRectangle(getAnchor().getX(), getAnchor().getY(),getAnchor().getX()+width,getAnchor().getY()+height);
}

void Rectangle::write(std::ostream& os) {
    Shape::write(os);
    os << width << " " << height;
}

const char* Rectangle::getTypeName() const {
  return "Rectangle";
}

void Rectangle::modifyAttributes() 
{
  char c; int w,h;
  do
  {
    std::cout << "Current attributes values are:" << std::endl
    << "s : go to the sub-menu for the attributes of the Shape " << std::endl
    << "w - width  = " << getWidth() << std::endl
    << "h - height = " << getHeight() << std::endl
    << "q - quit or go back one level" << std::endl
    << "To modify an attribute, enter the designated letter." << std::endl
    << "Choice?>"; std::cin >> c;
    switch(c)
    {
      case 's': Shape::modifyAttributes(); break;
      case 'w': std::cout << "Give the new width value>"; std::cin >> w; setWidth(w); break;
      case 'h': std::cout << "Give the new height value>"; std::cin >> h; setHeight(h); break;
      case 'q': break;
      default:
        std::cout << "Error this choice does not exist. Try again." << std::endl;
    }
  } while(c!='q');
} 
