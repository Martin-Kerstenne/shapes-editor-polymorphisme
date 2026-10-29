#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle 
    : public Shape
{
    private :
        uint radius;

    public :
    //---Constructeurs & Destructeur-----//
        Circle(EZColor col, uint x, uint y, uint radius);
        Circle(std::istream& is);
        ~Circle();

    //---Outils & Méthodes-----//
        //--Fonctions pour le rayon--//
        uint getRadius() const;
        void setRadius(uint r);

        //--Autres fonctions--//
        virtual const char* getTypeName() const override;
        virtual void modifyAttributes();
        virtual void draw(EZWindow& win);

    protected :
        virtual void write(std::ostream& os) override;
};

#endif