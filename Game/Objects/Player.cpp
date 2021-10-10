//
// Created by Bartosz Śnieg on 09.10.2021.
//

#include "Player.hpp"
#include "../../Engine/base/engineBase.hpp"
#include <iostream>
void Player::onInit()
{

    if(this->texture.loadFromFile("../assets/player.png"))
    {
        this->shape.setSize(sf::Vector2f(50.f,75.f));
        this->shape.setTexture(&this->texture);
        this->shape.setPosition(100,100);
    }
    this->isBlock = true;
}
void Player::onKeyPressEvent(std::vector<engine::event::Key> * keyList)
{
    float dt = engine::base::engineBase::deltaTime.asSeconds();
    if(this->isKeyPress(*keyList,sf::Keyboard::Key::Left)||this->isKeyPress(*keyList,sf::Keyboard::Key::A))
    {
        this->V2 = 100;
        flag2 = true;
        this->status = 'l';
        //left
    }

    if(this->isKeyPress(*keyList,sf::Keyboard::Key::Space)&&!this->flag)
    {
        flag = true;
        this->V1 = 100;

        //jump
    }




    if(this->isKeyPress(*keyList,sf::Keyboard::Key::Right)||this->isKeyPress(*keyList,sf::Keyboard::Key::D))
    {
        this->V2 = -100;
        flag2 = true;
        this->status = 'r';
        //right
    }

}

void Player::onUpdate() {


        float dt = engine::base::engineBase::deltaTime.asSeconds();
        auto pos = this->shape.getPosition();
    if(this->flag) {
        pos.y = pos.y - (this->V1 * dt - ((G * dt * dt) / 2));
        this->V1 = this->V1 - this->G * dt;
    }
    if((status == 'l'&& this->V2<1)||!flag2 )
    {
        this->V2 = 0;
        flag2 = false;
//        status = 'n';
    }else if((status == 'r'&& this->V2>-1)||!flag2 )
    {
        this->V2 = 0;
        flag2 = false;
//        status = 'n';
    }
    else {
        if(status == 'l') {
            pos.x -= (this->V2 * dt - ((T * dt * dt) / 2));
            this->V2 = this->V2 - this->T * dt;
        }
        else {
            pos.x -= (this->V2 * dt + ((T * dt * dt) / 2));
            this->V2 = this->V2 + this->T * dt;
        }

    }
    this->shape.setPosition(pos);

}

void Player::leftCollision(engine::object::GameObject *obj) {
    this->V2 *=-1.3;

    flag2 = true;
    this->status = 'r';

}

void Player::rightCollision(engine::object::GameObject *obj) {
    this->V2 *=-1.3;

    flag2 = true;
    this->status = 'l';

}

void Player::upCollision(engine::object::GameObject *obj) {
    this->V1 *=-1;
    this->flag = true;

}

void Player::downCollision(engine::object::GameObject *obj) {
    this->flag = false;
    T = 100;
}

void Player::downExitCollision(engine::object::GameObject *obj) {
    this->flag = true;
    T = 50;
}





