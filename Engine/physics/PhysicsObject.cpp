//
// Created by Banana on 10.07.2021.
//

#include "PhysicsObject.h"
float engine::physics::PhysicsObject::getMass(){
    return this->mass;
}

sf::Vector2f engine::physics::PhysicsObject::getVelocity(){
    return this->velocity;
}

float engine::physics::PhysicsObject::getRestitution(){
    return this->restitution;
}