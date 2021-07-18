//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEPHYSICS_H
#define GRA1_GAMEPHYSICS_H

#include "../object/GameObject.h"
#include <cmath>

namespace physics::physicsEngine {

    class gamePhysics {
    public:
        gamePhysics() = default;

        ~gamePhysics() = default;

        // Functions
        bool checkRectangleIntersection(object::gameobjects::GameObject* object1,
                                        object::gameobjects::GameObject* object2);

        //todo void checkShape(); [maybe unused] need to implement new shapes such as circle
        void calculateImpulse(object::gameobjects::GameObject* object1);

        void calculateDistance(object::gameobjects::GameObject* object1,
                               object::gameobjects::GameObject* object2);

        float calculateLength(object::gameobjects::GameObject* object1);


        sf::Vector2f  calculateRelativeVelocity(object::gameobjects::GameObject* object1,
                                                object::gameobjects::GameObject* object2);

        float calculateDotProduct(object::gameobjects::GameObject* object1,
                                  object::gameobjects::GameObject* object2);

        float findMinRestitution(object::gameobjects::GameObject* object1,
                                 object::gameobjects::GameObject* object2);

        void resolveCollision(object::gameobjects::GameObject* object1,
                              object::gameobjects::GameObject* object2);

        void calculateInverseMass(object::gameobjects::GameObject* object1);

    private:
        float inverseMass;
        float impulse;
        float distance;
        sf::Vector2f relativeVelocity;

        // Functions

    };

#endif //GRA1_GAMEPHYSICS_H
}