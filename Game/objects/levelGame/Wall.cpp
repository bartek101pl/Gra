//
// Created by Bartek on 31.10.2021.
//

#include "Wall.h"
#include "../../../Engine/exception/NullObjectException.hpp"
Wall::Wall(std::string file, int x, int y, int w, int h) {
    this->file = file;
this->shape.setSize(sf::Vector2f{(float)w,(float)h});
this->shape.setPosition(x,y);
this->isBlock = true;
}

void Wall::onInit() {
if(this->tx.loadFromFile(file))
{
    this->shape.setTexture(&this->tx);
}else
{
    throw engine::exception::NullObjectException::EngineException("Not found");
}
}
