#include "SetOfShapes.hpp"
using namespace std;

//---Constructeur & Destructeur-----//
SetOfShapes::SetOfShapes(size_t maxSize)
    : shapes(nullptr), maxSize(maxSize)
{
    shapes = new Shape*[maxSize];
    for (size_t i = 0; i < maxSize; i++)
        shapes[i] = nullptr;
}

SetOfShapes::~SetOfShapes()
{ delete[] shapes; }


void SetOfShapes::add(Shape* shape) {
    for (size_t i = 0; i < maxSize; i++) {
        if (shapes[i] == nullptr) {
            shapes[i] = shape;
            break;
        }
    }
}


Shape* SetOfShapes::isOver(uint mouse_x, uint mouse_y) const {
    for (size_t i = 0; i < maxSize; i++) {
        if (shapes[i] != nullptr) {
            if (shapes[i]->isOver(mouse_x, mouse_y))
                return shapes[i];
        }
    }
    return nullptr;
}


void SetOfShapes::draw(EZWindow& w) const {
    for (size_t i = 0; i < maxSize; i++) {
        if (shapes[i] != nullptr) {
            shapes[i]->draw(w);
            shapes[i]->getAnchor().draw(w);
        }
    }
}

//---Sauvegarde-----//
void SetOfShapes::save(std::ostream& os) {
    size_t count = 0;
    for (size_t i = 0; i < maxSize; i++)
        if (shapes[i] != nullptr) count++;
    os << count << std::endl;
    for (size_t i = 0; i < maxSize; i++)
        if (shapes[i] != nullptr)
            os << *shapes[i] << std::endl;
}

//---Chargement-----//
void SetOfShapes::load(std::istream& is) {
    // Libère les formes existantes
    for (size_t i = 0; i < maxSize; i++) {
        delete shapes[i];
        shapes[i] = nullptr;
    }
    size_t count;
    is >> count;
    for (size_t i = 0; i < count && i < maxSize; i++)
        shapes[i] = Shape::load(is);
}


std::ostream& operator<<(std::ostream& os, SetOfShapes set) {
    set.save(os);
    return os;
}