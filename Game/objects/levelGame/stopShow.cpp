//
// Created by Bartosz Śnieg on 31.12.2021.
//

#include "stopShow.hpp"
#include "../../scenes/levelGame.h"
#include "button2.h"
#include "../../../Engine/object/Lable.hpp"
void stopShow::onInit() {
    this->shape.setSize(sf::Vector2f(500,400));
    this->shape.setFillColor(sf::Color(0,0,0));
    this->visibility = false;
    this->addChildren(new button2("../assets/buttonBG.png", sf::Color::White, "Resume", 30, (1000 - 200) / 2, 400, 200, 100, 45, 25, 0));
    this->addChildren(new button2("../assets/buttonBG.png", sf::Color::White, "Exit", 30, (1000 - 200) / 2, 500, 200, 100, 75, 25, 1));
    this->addChildren(new Lable("Pause",375,200,90));
}

void stopShow::onKeyPressEvent(std::vector<engine::event::Key> *keyList) {
    if(isKeyPress(*keyList,sf::Keyboard::Escape))
        ((levelGame*)this->parent)->resume();
}
