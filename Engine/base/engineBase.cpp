//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "engineBase.hpp"

void engine::base::engineBase::init(engine::base::InitSetting setting) {
    this->window.create(sf::VideoMode(setting.width,setting.height),"test");
    this->eventController.setCurrentScene(&this->testowa);
}

void engine::base::engineBase::start() {
    while (this->window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                this->window.close();
            else
                this->eventController.event(e);
        }
    }
}
