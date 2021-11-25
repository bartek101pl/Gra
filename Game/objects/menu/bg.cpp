//
// Created by Bartek on 28.10.2021.
//

#include "bg.h"
#include <iostream>
#include "../../../Engine/exception/EngineException.hpp"
void bg::onInit() {

this->shape.setSize(sf::Vector2f{1000,800});
this->shape.setPosition(0.f,0.f);
if(!tx.loadFromFile(this->file))
{
    throw engine::exception::EngineException("Not found img");
}
this->shape.setTexture(&tx);
std::cout<<"Imge read"<<std::endl;
this->isBlock = false;
}

bg::bg(std::string file) {
    this->file = file;

}
