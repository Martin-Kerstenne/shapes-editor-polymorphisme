#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape.hpp"

class Square 
    : public Shape
{
    private :
        uint size;

    public :
    //---Constructeurs & Destructeur-----//
        Square(EZColor _col, uint x, uint y, uint size);
        Square(std::istream& is);
        ~Square();

    //---Outils & Méthodes-----//
        //--Fonctions pour le côté--//
        uint getSize() const;
        void setSize(uint size);

        //--Autres fonctions--//
        virtual const char* getTypeName() const override;
        virtual void modifyAttributes();
        virtual void draw(EZWindow& win);

    protected :
        virtual void write(std::ostream& os) override;
};

#endif