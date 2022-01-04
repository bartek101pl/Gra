//
// Created by Bartosz Śnieg on 02.01.2022.
//

#ifndef GRA_BUTTON3_HPP
#define GRA_BUTTON3_HPP


#include "../../../Engine/object/button.h"

class button3: public engine::object::button  {
public:
    button3(std::string textureURL, sf::Color textColor, std::string context , int fSize, float x, float y , float w, float h, float tx, float ty, int type): button(textureURL, textColor, context , fSize, x, y , w, h, tx, ty){ this->type = type;}

protected:
    int type;
    void onclick() override;
};


#endif //GRA_BUTTON3_HPP
