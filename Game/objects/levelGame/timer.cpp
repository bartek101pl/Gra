//
// Created by Bartek on 12.12.2021.
//

#include "timer.h"
#include "../../../Engine/base/engineBase.hpp"
#include "timerBack.h"
#include "../../scenes/levelGame.h"

timer::timer(float time, float x, float y) {
this->addChildren(new timerBack(x,y,200,20,sf::Color(100,100,100)));
this->addChildren(new timerBack(x,y,200,20,sf::Color::Red));
this->time =time;
this->maxTime = time;

//this->shape.setSize(sf::Vector2f (200.f,20.f));
//this->shape.setFillColor(sf::Color::Red);
//this->shape.setPosition(x,y);
}

void timer::onUpdate() {

    float dt = engine::base::engineBase::deltaTime.asSeconds();
    this->time -= dt;
    this->timeStart +=dt;
    if(this->time <0){
        this->time = 0;
        ((levelGame*)engine::base::SceneController::getInstance()->getCurrentScene())->hit();
        return;
    }
    if(this->children->size() > 0)
    ((timerBack*)this->children->at(1))->setSize((time/maxTime)*200.f,20.f);
}

void timer::addTime(float t) {
this->time+=t;
if(this->time > this->maxTime)
    this->time = maxTime;
}

void timer::onDestroyed() {
    AbstractUserEventObject::onDestroyed();

}
