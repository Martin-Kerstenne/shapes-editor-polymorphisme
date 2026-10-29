#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point.hpp"
#include "ez-draw++.hpp"


class Shape {
    private:
        EZColor color;
        bool filled;
        uint thickness = 1;
        Point anchor;

    public:
    //---Constructeurs & destructeur-----//
        Shape(EZColor col, uint x, uint y);
        Shape(std::istream& is);
        virtual ~Shape();
    
    //---Outils & Méthodes-----//
        //--fonctions pour la couleur--//
        EZColor getColor();
        void setColor(EZColor color);

        
        //--fonctions pour l'ancre--//
        void setAnchor(uint x, uint y);
        Point getAnchor();

        //--fonctions pour le remplissage--//
        void setFilled(bool new_value=false);
        bool isFilled();

        //--fonctions pour l'épaisseur--//
        uint getThickness() const;
        void setThickness(uint _thickness);

        //--autres fonctions--//
        virtual void draw(EZWindow& w);
        bool isOver(uint mouseX, uint mouseY);
        virtual void modifyAttributes();
        virtual const char* getTypeName() const =0;
        static Shape* load(std::istream& is);

    //---Surcharge d'opérateurs-----//
        friend std::ostream& operator<<(std::ostream& os, Shape& s);
    
    protected: 
        virtual void write(std::ostream& os);
};


#endif 