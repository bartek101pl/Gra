//
// Created by Banana on 10.07.2021.
//

#ifndef GRA1_PHYSICSOBJECT_H
#define GRA1_PHYSICSOBJECT_H
#include <SFML/Graphics.hpp>


namespace engine::physics {


    class PhysicsObject {
    public:
        PhysicsObject() = default;

        ~PhysicsObject() = default;


        //Functions
        float getMass();
        sf::Vector2f getVelocity();
        float getRestitution();



    private:
        // Variables
        float mass;
        sf::Vector2f velocity;
        float restitution;

    };
}

#endif //GRA1_PHYSICSOBJECT_H
