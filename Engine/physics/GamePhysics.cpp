//
// Created by Banana on 19.04.2021.
//
#include "GamePhysics.h"

bool physics::physicsEngine::gamePhysics::checkRectangleCollision(object::gameobjects::GameObject *object1,
                                                                  object::gameobjects::GameObject *object2){
    return (object1->getObject().getGlobalBounds().intersects(object2->getObject().getGlobalBounds()));
}
