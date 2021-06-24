//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEPHYSICS_H
#define GRA1_GAMEPHYSICS_H

#include "../object/GameObject.h"

namespace physics::physicsEngine {

    class gamePhysics {
    public:
        gamePhysics() = default;

        ~gamePhysics() = default;

        // Functions
        bool checkRectangleCollision(object::gameobjects::GameObject* object1,
                                     object::gameobjects::GameObject* object2);

        //todo void checkShape(); [maybe unused] need to implement new shapes such as circle



    private:




        // Functions

    };

#endif //GRA1_GAMEPHYSICS_H
}