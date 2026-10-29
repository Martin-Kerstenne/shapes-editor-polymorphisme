#include "Label.hpp"


//---Constructeurs & Destructeur-----//
Label::Label(EZColor _col, uint x, uint y, uint _fontNum, std::string _msg)
    : Shape::Shape(_col, x, y), fontNum(_fontNum), msg(_msg)
{}

Label::Label(std::istream& is)
    : Shape::Shape(is), fontNum(0), msg("")
{
    is >> fontNum;
    char c;
    is >> c;
    std::getline(is, msg, '"');
}

Label::~Label() {}


//---Outils & Méthodes-----//

//--Fonctions pour la police (d'écriture hein)--//
uint Label::getFontNum() const {
    return fontNum;
}

void Label::setFontNum(uint f) {
    fontNum = f;
}

//--Fonctions pour le message--//
std::string Label::getMsg() const {
    return msg;
}

void Label::setMsg(std::string m) {
    msg = m;
}


//--Autres fonctions--//
const char* Label::getTypeName() const {
    return "Label";
}

void Label::draw(EZWindow& win) {
    Shape::draw(win);
    win.setFont(fontNum);
    win.drawText(EZAlign::TL, getAnchor().getX(), getAnchor().getY(), msg);
}

void Label::write(std::ostream& os) {
    Shape::write(os);
    os << fontNum << " \"" << msg << "\"";  //prend tout le message entre ""
}

void Label::modifyAttributes()
{
    char c; int f; std::string m;
    do
    {
        std::cout << "Current attributes values are:" << std::endl
        << "s : go to the sub-menu for the attributes of the Shape" << std::endl
        << "f - fontNum = " << getFontNum() << std::endl
        << "m - msg = " << getMsg() << std::endl
        << "q - quit or go back one level" << std::endl
        << "To modify an attribute, enter the designated letter." << std::endl
        << "Choice?>"; std::cin >> c;
        switch (c)
        {
            case 's': Shape::modifyAttributes(); break;
            case 'f': std::cout << "Give the new font number>"; std::cin >> f; setFontNum(f); break;
            case 'm': std::cout << "Give the new message>"; std::cin >> m; setMsg(m); break;
            case 'q': break;
            default:
                std::cout << "Error this choice does not exist. Try again." << std::endl;
        }
    } while (c != 'q');
}