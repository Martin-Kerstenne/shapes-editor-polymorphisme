#ifndef RECTANGLE_HPP 
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle 
    : public Shape
{
    private :
        uint width;
        uint height;
    
    public :
    //---Constructeurs & Destructeur-----//
        Rectangle(EZColor _col, uint x, uint y, uint _width, uint _height);
        Rectangle(std::istream& is);
        ~Rectangle();

    //---Outils & Méthodes-----//
        //--Fonctions pour la largeur--//
        uint getWidth();
        void setWidth(uint w);

        //--Fonctions pour la hauteur--//
        uint getHeight();
        void setHeight(uint h);

        //--Autres fonctions--//
        virtual const char* getTypeName() const override;
        virtual void modifyAttributes();
        virtual void draw(EZWindow& win);

    protected :
        virtual void write(std::ostream& os);
};


#endif