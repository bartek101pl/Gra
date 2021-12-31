//
// Created by Bartek on 12.12.2021.
//

#ifndef GRA_TIMERBACK_H
#define GRA_TIMERBACK_H

#include "../../../Engine/object/GameObject.h"

class timerBack: public engine::object::GameObject{
public:
    timerBack(float x, float y, float w, float h,sf::Color c);
    void setSize(float w, float h);
};


#endif //GRA_TIMERBACK_H
