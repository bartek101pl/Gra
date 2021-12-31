//
// Created by Bartek on 12.12.2021.
//

#include "timerBack.h"

timerBack::timerBack(float x, float y, float w, float h , sf::Color c) {
this->shape.setSize(sf::Vector2f(w,h));
this->shape.setPosition(x,y);
this->shape.setFillColor(c);
}

void timerBack::setSize(float w , float  h) {
    this->shape.setSize(sf::Vector2f(w,h));
}
