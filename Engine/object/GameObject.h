//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEOBJECT_H
#define GRA1_GAMEOBJECT_H

#include "../physics/PhysicsObject.h"

namespace engine::object {


    class GameObject: public engine::physics::PhysicsObject{
    public:
        GameObject() = default;

        ~GameObject() = default;


        //Functions
        sf::RectangleShape getShape();


    private:
        // Variables
        sf::RectangleShape shape;




        // FunctionS

        void initObject();


    };
}
#endif //GRA1_GAMEOBJECT_H
