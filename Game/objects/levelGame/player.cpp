//
// Created by Bartek on 31.10.2021.
//

#include "player.h"

#include "../../../Engine/base/engineBase.hpp"

void player::onInit()
{

    this->idle = new engine::animation::Animation(&this->shape,"../assets/player/"+this->file,"idle.am",25,true);
    this->LRun = new engine::animation::Animation(&this->shape,"../assets/player/"+this->file,"LRun.am",25,true);
    this->RRun = new engine::animation::Animation(&this->shape,"../assets/player/"+this->file,"RRun.am",25,true);
    this->Rjump = new engine::animation::Animation(&this->shape,"../assets/player/"+this->file,"RJump.am",25,false);
    this->Ljump = new engine::animation::Animation(&this->shape,"../assets/player/"+this->file,"LJump.am",25, false);

    this->shape.setSize(sf::Vector2f(55.f,71.f));
//        this->shape.setTexture(&this->texture);
    this->shape.setPosition(100,699);

    this->isBlock = true;
}
void player::onKeyPressEvent(std::vector<engine::event::Key> * keyList)
{
    float dt = engine::base::engineBase::deltaTime.asSeconds();
    if(this->isKeyPress(*keyList,sf::Keyboard::Key::Left)||this->isKeyPress(*keyList,sf::Keyboard::Key::A))
    {
        this->V2 = 100;
        flag2 = true;
        this->status = 'l';
        //left
    }

    if((this->isKeyPress(*keyList,sf::Keyboard::Key::Space)||this->isKeyPress(*keyList,sf::Keyboard::Key::Up)||this->isKeyPress(*keyList,sf::Keyboard::Key::W))&&!this->flag)
    {
        flag = true;
        this->V1 = 100;

        //jump
    }
    if(this->isKeyPress(*keyList, sf::Keyboard::Key::Down)||this->isKeyPress(*keyList,sf::Keyboard::Key::S))
    {
        this->V1-=10;
    }



    if(this->isKeyPress(*keyList,sf::Keyboard::Key::Right)||this->isKeyPress(*keyList,sf::Keyboard::Key::D))
    {
        this->V2 = -100;
        flag2 = true;
        this->status = 'r';
        //right
    }

}

void player::onUpdate() {


    float dt = engine::base::engineBase::deltaTime.asSeconds();
    auto pos = this->shape.getPosition();
    if(this->flag) {
        pos.y = pos.y - (this->V1 * dt - ((G * dt * dt) / 2));
        this->V1 = this->V1 - this->G * dt;
        if((this->V2<1)||!flag2 )
        {
            this->Rjump->update();
        }else  if(( this->V2>-1)||!flag2 )
        {
            this->Ljump->update();
        }
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
            if(!this->flag)
                this->LRun->update(this->V2/100.f);
        }
        else {
            pos.x -= (this->V2 * dt + ((this->T * dt * dt) / 2));
            this->V2 = this->V2 + this->T * dt;
            if(!this->flag)
                this->RRun->update(this->V2/-100.f);
        }

    }
    this->shape.setPosition(pos);
    if(!this->flag && !this->flag2)
    {
        this->idle->update();
    }
}

void player::leftCollision(engine::object::GameObject *obj) {
    this->V2 *=-1.3;

    flag2 = true;
    this->status = 'r';

}

void player::rightCollision(engine::object::GameObject *obj) {
    this->V2 *=-1.3;

    flag2 = true;
    this->status = 'l';

}

void player::upCollision(engine::object::GameObject *obj) {
    this->V1 *=-1;
    this->flag = true;

}

void player::downCollision(engine::object::GameObject *obj) {
    this->flag = false;
    this->V1 = 0;
    T = 100;
}

void player::downExitCollision(engine::object::GameObject *obj) {
    this->flag = true;
    T = 50;
}

player::player(std::string file) {
this->file = file;

}
