#ifndef LABEL_HPP
#define LABEL_HPP

#include "Shape.hpp"

class Label 
    : public Shape
{
    private :
        uint fontNum;
        std::string msg;

    public :
    //---Constructeurs & Destructeur-----//
        Label(EZColor _col, uint x, uint y, uint _fontNum, std::string _msg);
        Label(std::istream& is);
        ~Label();

    //---Outils & Méthodes-----//
        //--Fonctions pour la police--//
        uint getFontNum() const;
        void setFontNum(uint f);

        //--Fonctions pour le message--//
        std::string getMsg() const;
        void setMsg(std::string m);

        //--Autres fonctions--//
        virtual const char* getTypeName() const override;
        virtual void modifyAttributes() override;
        virtual void draw(EZWindow& win) override;

    protected :
        virtual void write(std::ostream& os) override;
};

#endif