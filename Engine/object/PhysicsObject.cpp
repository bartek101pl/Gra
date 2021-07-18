//
// Created by Banana on 10.07.2021.
//

#include "PhysicsObject.h"
float object::physicsobjects::PhysicsObject::getMass(){
    return this->mass;
}

sf::Vector2f object::physicsobjects::PhysicsObject::getVelocity(){
    return this->velocity;
}

float object::physicsobjects::PhysicsObject::getRestitution(){
    return this->restitution;
}