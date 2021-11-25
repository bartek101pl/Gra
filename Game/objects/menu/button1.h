//
// Created by Bartek on 29.10.2021.
//

#ifndef GRA_BUTTON1_H
#define GRA_BUTTON1_H

#include "../../../Engine/object/button.h"

class button1: public engine::object::button {
public:
    button1(std::string textureURL,sf::Color textColor,std::string context ,int fSize, float x, float y , float w, float h,float tx,float ty, int type): button(textureURL,textColor,context ,fSize, x, y , w, h, tx, ty){this->type = type;}

protected:
    int type;
    void onclick() override;
};


#endif //GRA_BUTTON1_H
