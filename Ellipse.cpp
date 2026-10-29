#include "Ellipse.hpp"

//---Constructeurs & Destructeur-----//
Ellipse::Ellipse(EZColor col, uint x, uint y, uint width, uint height)
    : Shape::Shape(col, x, y), semiWidth(width), semiHeight(height)
{}

Ellipse::Ellipse(std::istream& is)
    : Shape::Shape(is), semiWidth(10), semiHeight(10)
{ is >> semiWidth >> semiHeight; }

Ellipse::~Ellipse() {}


//---Outils & Méthodes-----//

//--Fonctions pour la largeur--//
uint Ellipse::getSemiWidth() {
    return semiWidth;
}

void Ellipse::setSemiWidth(uint w) {
    semiWidth = w;
}

//--Fonctions pour la hauteur--//
uint Ellipse::getSemiHeight() {
    return semiHeight;
}

void Ellipse::setSemiHeight(uint h) {
    semiHeight = h;
}

//--Autres fonctions--//
const char* Ellipse::getTypeName() const {
    return "Ellipse";
}

void Ellipse::draw(EZWindow& win) {
    Shape::draw(win);
    if (isFilled())
        win.fillCircle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + semiWidth, getAnchor().getY() + semiHeight);
    else
        win.drawCircle(getAnchor().getX(), getAnchor().getY(), getAnchor().getX() + semiWidth, getAnchor().getY() + semiHeight);
}

void Ellipse::write(std::ostream& os) {
    Shape::write(os);
    os << semiWidth << " " << semiHeight;
}

void Ellipse::modifyAttributes()
{
    char c; int w, h;
    do
    {
        std::cout << "Current attributes values are:" << std::endl
        << "s : go to the sub-menu for the attributes of the Shape" << std::endl
        << "w - semiWidth  = " << getSemiWidth() << std::endl
        << "h - semiHeight = " << getSemiHeight() << std::endl
        << "q - quit or go back one level" << std::endl
        << "To modify an attribute, enter the designated letter." << std::endl
        << "Choice?>"; std::cin >> c;
        switch (c)
        {
            case 's': Shape::modifyAttributes(); break;
            case 'w': std::cout << "Give the new semiWidth value>"; std::cin >> w; setSemiWidth(w); break;
            case 'h': std::cout << "Give the new semiHeight value>"; std::cin >> h; setSemiHeight(h); break;
            case 'q': break;
            default:
                std::cout << "Error this choice does not exist. Try again." << std::endl;
        }
    } while (c != 'q');
}