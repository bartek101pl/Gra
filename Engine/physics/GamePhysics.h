//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEPHYSICS_H
#define GRA1_GAMEPHYSICS_H

#include "../object/GameObject.h"
#include "PhysicsObject.h"
#include <cmath>

namespace engine::physics{

    class gamePhysics {
    public:
        gamePhysics() = default;

        ~gamePhysics() = default;

        // Functions
        bool checkRectangleIntersection(engine::object::GameObject* object1,
        engine::object::GameObject* object2);

        //todo void checkShape(); [maybe unused] need to implement new shapes such as circle
        void calculateImpulse(engine::object::GameObject* object1);

        void calculateDistance(engine::object::GameObject* object1,
                               engine::object::GameObject* object2);

        float calculateLength(engine::object::GameObject* object1);


        sf::Vector2f  calculateRelativeVelocity(engine::object::GameObject* object1,
                                                engine::object::GameObject* object2);

        float calculateDotProduct(engine::object::GameObject* object1,
                                  engine::object::GameObject* object2);

        float findMinRestitution(engine::object::GameObject* object1,
                                 engine::object::GameObject* object2);

        void resolveCollision(engine::object::GameObject* object1,
                              engine::object::GameObject* object2);

        void calculateInverseMass(engine::object::GameObject* object1);

    private:
        float inverseMass;
        float impulse;
        float distance;
        sf::Vector2f relativeVelocity;

        // Functions

    };

#endif //GRA1_GAMEPHYSICS_H
}