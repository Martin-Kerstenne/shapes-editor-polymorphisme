#ifndef SETOFSHAPE_HPP
#define SETOFSHAPE_HPP

#include "Shape.hpp"

class SetOfShapes {
    private:
        Shape** shapes;
        size_t maxSize;

    public:
    //---Constructeur & Destructeur-----//
        SetOfShapes(size_t maxSize);
        ~SetOfShapes();

    //---Outils & Méthodes-----//
        void add(Shape* shape);
        Shape* isOver(uint mouse_x, uint mouse_y) const;
        void draw(EZWindow& w) const;

        friend std::ostream& operator<<(std::ostream& os, SetOfShapes set);
        void save(std::ostream& os);    //sauvegarde
        void load(std::istream& is);    //chargement
};

#endif