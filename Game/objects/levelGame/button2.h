//
// Created by Bartek on 29.10.2021.
//

#ifndef GRA_BUTTON2_H
#define GRA_BUTTON2_H

#include "../../../Engine/object/button.h"

class button2: public engine::object::button {
public:
    button2(std::string textureURL, sf::Color textColor, std::string context , int fSize, float x, float y , float w, float h, float tx, float ty, int type): button(textureURL, textColor, context , fSize, x, y , w, h, tx, ty){ this->type = type;}

protected:
    int type;
    void onclick() override;
};


#endif //GRA_BUTTON2_H
