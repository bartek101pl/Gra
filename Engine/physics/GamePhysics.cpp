//
// Created by Banana on 19.04.2021.
//
#include "GamePhysics.h"

bool engine::physics::gamePhysics::checkRectangleIntersection(engine::object::GameObject *object1,
                                                              engine::object::GameObject *object2){

    return (object1->getShape().getGlobalBounds().intersects(object2->getShape().getGlobalBounds()));      // Checking intersection of two rect objects

}
void engine::physics::gamePhysics::calculateImpulse(engine::object::GameObject *object1){

    this->impulse = (object1->getMass() * object1->getVelocity().x * object1->getVelocity().y);

}

void engine::physics::gamePhysics::calculateDistance(engine::object::GameObject *object1,
                                                     engine::object::GameObject *object2){

    this->distance= sqrt((((object1->getShape().getPosition().x - object2->getShape().getPosition().x)             // Calculating distance between two objects
                      * (object1->getShape().getPosition().x - object2->getShape().getPosition().x))
                     + ((object1->getShape().getPosition().y - object2->getShape().getPosition().y)
                      * (object1->getShape().getPosition().y - object2->getShape().getPosition().y))));
}

float engine::physics::gamePhysics::calculateLength(engine::object::GameObject *object1){

    return (object1->getShape().getPosition().x * object1->getShape().getPosition().x +
            object1->getShape().getPosition().y * object1->getShape().getPosition().y );

}

sf::Vector2f engine::physics::gamePhysics::calculateRelativeVelocity(engine::object::GameObject *object1,
                                                                     engine::object::GameObject *object2){
    return (object1->getVelocity() - object2->getVelocity());
}

float engine::physics::gamePhysics::calculateDotProduct(engine::object::GameObject *object1,
                                                        engine::object::GameObject *object2){
          return ((object1->getShape().getPosition().x * object2->getShape().getPosition().x)
                + (object1->getShape().getPosition().y * object2->getShape().getPosition().y ));
}

float engine::physics::gamePhysics::findMinRestitution(engine::object::GameObject *object1,
                                                       engine::object::GameObject *object2){

    if(object1->getRestitution() > object2->getRestitution())
    {

        return object2->getRestitution();

    }
    else
    {

        return object1->getRestitution();

    }

}

void engine::physics::gamePhysics::calculateInverseMass(engine::object::GameObject *object1){

     this->inverseMass = (1/object1->getMass());

}

void engine::physics::gamePhysics::resolveCollision(engine::object::GameObject *object1,
                                                           engine::object::GameObject *object2){
    this->relativeVelocity = calculateRelativeVelocity(object1, object2);

    float e = findMinRestitution(object1, object2);



}

