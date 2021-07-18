//
// Created by Banana on 19.04.2021.
//
#include "GamePhysics.h"

bool physics::physicsEngine::gamePhysics::checkRectangleIntersection(object::gameobjects::GameObject *object1,
                                                                  object::gameobjects::GameObject *object2){

    return (object1->getShape().getGlobalBounds().intersects(object2->getShape().getGlobalBounds()));      // Checking intersection of two rect objects

}
void physics::physicsEngine::gamePhysics::calculateImpulse(object::gameobjects::GameObject *object1){

    this->impulse = (object1->getMass() * object1->getVelocity().x * object1->getVelocity().y);

}

void physics::physicsEngine::gamePhysics::calculateDistance(object::gameobjects::GameObject *object1,
                                                            object::gameobjects::GameObject *object2){

    this->distance= sqrt((((object1->getShape().getPosition().x - object2->getShape().getPosition().x)             // Calculating distance between two objects
                      * (object1->getShape().getPosition().x - object2->getShape().getPosition().x))
                     + ((object1->getShape().getPosition().y - object2->getShape().getPosition().y)
                      * (object1->getShape().getPosition().y - object2->getShape().getPosition().y))));
}

float physics::physicsEngine::gamePhysics::calculateLength(object::gameobjects::GameObject *object1){

    return (object1->getShape().getPosition().x * object1->getShape().getPosition().x +
            object1->getShape().getPosition().y * object1->getShape().getPosition().y );

}

sf::Vector2f physics::physicsEngine::gamePhysics::calculateRelativeVelocity(object::gameobjects::GameObject *object1,
                                                                     object::gameobjects::GameObject *object2){
    return (object1->getVelocity() - object2->getVelocity());
}

float physics::physicsEngine::gamePhysics::calculateDotProduct(object::gameobjects::GameObject *object1,
                                                               object::gameobjects::GameObject *object2){
          return ((object1->getShape().getPosition().x * object2->getShape().getPosition().x)
                + (object1->getShape().getPosition().y * object2->getShape().getPosition().y ));
}

float physics::physicsEngine::gamePhysics::findMinRestitution(object::gameobjects::GameObject *object1,
                                                              object::gameobjects::GameObject *object2){

    if(object1->getRestitution() > object2->getRestitution())
    {

        return object2->getRestitution();

    }
    else
    {

        return object1->getRestitution();

    }

}

void physics::physicsEngine::gamePhysics::calculateInverseMass(object::gameobjects::GameObject *object1){

     this->inverseMass = (1/object1->getMass());

}

void physics::physicsEngine::gamePhysics::resolveCollision(object::gameobjects::GameObject *object1,
                                                           object::gameobjects::GameObject *object2){
    this->relativeVelocity = calculateRelativeVelocity(object1, object2);

    float e = findMinRestitution(object1, object2);



}

