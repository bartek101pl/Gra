//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEOBJECT_H
#define GRA1_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

namespace object::gameobjects {
    struct Object{                 //todo struct of known shape types
    };


    class GameObject {
    public:
        GameObject() = default;

        ~GameObject() = default;


        //Functions
        sf::RectangleShape getObject();


    private:
        // Variables
        std::vector<sf::RectangleShape> objects;
        sf::RectangleShape object;




        // Functions
       // void setVelocity(Object* object, float velocity); [maybe unused]

        void initObject();


    };
}
#endif //GRA1_GAMEOBJECT_H
