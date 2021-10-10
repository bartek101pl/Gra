//
// Created by Bartosz Śnieg on 09.10.2021.
//

#include "Wall.hpp"

Wall::Wall(float x, float y, float w, float h) {
    this->shape.setSize(sf::Vector2f(w,h));
    this->shape.setFillColor(*new sf::Color(169,169,169));
    this->shape.setPosition(x,y);
    this->isBlock = true;
}
