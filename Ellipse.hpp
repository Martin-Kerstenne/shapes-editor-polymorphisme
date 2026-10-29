#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Shape.hpp"

class Ellipse 
    : public Shape
{   
    private :
        uint semiWidth;
        uint semiHeight;

    public :
    //---Constructeurs & Destructeur-----//
        Ellipse(EZColor col, uint x, uint y, uint width, uint height);
        Ellipse(std::istream& is);
        ~Ellipse();
    
    //---Outils & Méthodes-----//
        //--Fonctions pour la largeur--//
        uint getSemiWidth();
        void setSemiWidth(uint w);

        //--Fonctions pour la hauteur--//
        uint getSemiHeight();
        void setSemiHeight(uint h);
    
    
        //--Autres fonctions--//
        virtual void draw(EZWindow& win);
        virtual const char* getTypeName() const override;
        virtual void modifyAttributes();

    protected :
        virtual void write(std::ostream& os);
};



#endif