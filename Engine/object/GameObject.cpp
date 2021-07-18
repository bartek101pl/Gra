//
// Created by Banana on 19.04.2021.
//

#include "GameObject.h"



// Functions
sf::RectangleShape object::gameobjects::GameObject::getShape(){
    return this->shape;
}

void object::gameobjects::GameObject::initObject(){


     this->shape.setPosition(10.f, 10.f);               /* sets positions for object ( this coords just  for test, i have plan
                                                                           to make it random in bounds of our playing field */
     this->shape.setSize(sf::Vector2f(100.f, 100.f));
     this->shape.setScale(sf::Vector2f(0.5f, 0.5f));



}
