//
// Created by Banana on 19.04.2021.
//

#include "GameObject.h"



// Functions
sf::RectangleShape engine::object::GameObject::getShape(){

//    auto*  a =(GameObject *)  this->children->at(1);
    return this->shape;
}

void engine::object::GameObject::initObject(){


     this->shape.setPosition(10.f, 10.f);               /* sets positions for object ( this coords just  for test, i have plan
                                                                           to make it random in bounds of our playing field */
     this->shape.setSize(sf::Vector2f(100.f, 100.f));
     this->shape.setScale(sf::Vector2f(0.5f, 0.5f));



}

void engine::object::GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //TODO implements texture!
    target.draw(this->shape,states);
    if(this->children!= nullptr)
        for (auto& item : *this->children)
        {
            ((GameObject*)item)->draw(target,states);
        }
}

void engine::object::GameObject::collisionCalc(GameObject *ob1) {
    if((this->isBlock&& ob1->isBlock)) {
        if (this->shape.getPosition().x < ob1->shape.getPosition().x + ob1->shape.getSize().x &&
            this->shape.getPosition().x + this->shape.getSize().x > ob1->shape.getPosition().x &&
            this->shape.getPosition().y < ob1->shape.getPosition().y + ob1->shape.getSize().y &&
            this->shape.getPosition().y + this->shape.getSize().y > ob1->shape.getPosition().y) {
            this->onCollision(this);
            ob1->onCollision(this);


            if (this->shape.getPosition().y < ob1->shape.getPosition().y + ob1->shape.getSize().y &&
                this->shape.getPosition().y > ob1->shape.getPosition().y &&
                this->shape.getPosition().y + this->shape.getSize().y >
                ob1->shape.getPosition().y + ob1->shape.getSize().y && (lastColUp != ob1)) {
                this->upCollision(ob1);
                ob1->downCollision(this);
                this->enterCollision(ob1);
                ob1->enterCollision(this);
                lastColUp = ob1;

            }

            if (this->shape.getPosition().y + this->shape.getSize().y > ob1->shape.getPosition().y &&
                this->shape.getPosition().y + this->shape.getSize().y <
                ob1->shape.getPosition().y + ob1->shape.getPosition().y &&
                this->shape.getPosition().y < ob1->shape.getPosition().y &&
                (lastColButton != ob1)) {
                this->downCollision(ob1);
                ob1->upCollision(this);
                this->enterCollision(ob1);
                ob1->enterCollision(this);
                lastColButton = ob1;

            }

            if (this->shape.getPosition().x < ob1->shape.getPosition().x + ob1->shape.getSize().x &&
                this->shape.getPosition().x > ob1->shape.getPosition().x &&
                this->shape.getPosition().x + this->shape.getSize().x >
                ob1->shape.getPosition().x + ob1->shape.getSize().x &&
                (lastColLeft != ob1)) {
                this->leftCollision(ob1);
                ob1->rightCollision(this);
                this->enterCollision(ob1);
                ob1->enterCollision(this);
                lastColLeft = ob1;
                //right
            }

            if (this->shape.getPosition().x + this->shape.getSize().x > ob1->shape.getPosition().x &&
                this->shape.getPosition().x + this->shape.getSize().x <
                ob1->shape.getPosition().x + ob1->shape.getPosition().x &&
                this->shape.getPosition().x < ob1->shape.getPosition().x &&
                (lastColRight != ob1)) {
                this->rightCollision(ob1);
                ob1->leftCollision(this);
                this->enterCollision(ob1);
                ob1->enterCollision(this);
                lastColRight = ob1;

            }

        } else if (lastColUp == ob1) {
            this->exitCollision(ob1);
            ob1->exitCollision(this);
            this->downExitCollision(ob1);
            ob1->upExitCollision(this);
            lastColUp = nullptr;
        } else if (lastColButton == ob1) {
            this->exitCollision(ob1);
            ob1->exitCollision(this);
            this->downExitCollision(ob1);
            ob1->upExitCollision(this);
            lastColButton = nullptr;
        } else if (lastColLeft == ob1) {
            this->exitCollision(ob1);
            ob1->exitCollision(this);
            this->leftExitCollision(ob1);
            ob1->rightExitCollision(this);
            lastColLeft = nullptr;
        } else if (lastColRight == ob1) {
            this->exitCollision(ob1);
            ob1->exitCollision(this);
            this->rightExitCollision(ob1);
            ob1->leftExitCollision(this);
            lastColRight = nullptr;
        }
    }
    else
    {
        auto a = this->shape.getPosition();
        auto as = this->shape.getSize();
        auto b = ob1->shape.getPosition();
        auto bs = ob1->shape.getSize();

            if  (a.x < b.x + bs.x &&
                 a.x + as.x > b.x &&
                 a.y < b.y + bs.y &&
                 as.y + a.y > b.y)
            {
                if(!this->isBlock)
                {
                    this->enterCollision(ob1);
                }
                if(!ob1->isBlock)
                {
                    ob1->enterCollision(this);
                }
            }else
            {
                if(!this->isBlock)
                {
                    this->exitCollision();
                }
                if(!ob1->isBlock)
                {
                    ob1->exitCollision();
                }
            }

    }
}

void engine::object::GameObject::onCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::enterCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::exitCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::leftCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::rightCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::upCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::downCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::leftExitCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::rightExitCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::upExitCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::downExitCollision(engine::object::GameObject *obj) {

}

void engine::object::GameObject::enterCollision() {

}
void engine::object::GameObject::exitCollision(){}