//
// Created by Banana on 19.04.2021.
//

#ifndef GRA1_GAMEOBJECT_H
#define GRA1_GAMEOBJECT_H

#include "../physics/PhysicsObject.h"
#include "../event/EventObject.hpp"
#include "../event/AbstractUserEventObject.hpp"
#include "AbstractGameObject.hpp"
#include "../view/scene.hpp"

namespace engine::object {


    class GameObject: public engine::physics::PhysicsObject,public engine::object::AbstractGameObject, public sf::Drawable{
    public:
        GameObject() = default;
        ~GameObject() = default;
        virtual void onCollision(GameObject *obj);
        virtual void enterCollision(GameObject*obj);
        virtual void exitCollision(GameObject *obj);
        virtual void leftCollision(GameObject *obj);
        virtual void rightCollision(GameObject *obj);
        virtual void upCollision(GameObject *obj);
        virtual void downCollision(GameObject *obj);
        virtual void leftExitCollision(GameObject *obj);
        virtual void rightExitCollision(GameObject *obj);
        virtual void upExitCollision(GameObject *obj);
        virtual void downExitCollision(GameObject *obj);
        virtual void enterCollision();
        virtual void exitCollision();

        //Functions
        sf::RectangleShape getShape();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void collisionCalc(GameObject *ob1);

    protected:
        // Variables

        sf::RectangleShape shape;
        GameObject *lastColButton = nullptr;
        GameObject *lastColUp = nullptr;
        GameObject *lastColLeft = nullptr;
        GameObject *lastColRight = nullptr;
        GameObject *lastCol = nullptr;
        bool  isBlock = false;



        // FunctionS

        void initObject();
        void help(GameObject *ob1);

    };
}
#endif //GRA1_GAMEOBJECT_H
