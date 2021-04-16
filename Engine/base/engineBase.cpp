//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "engineBase.hpp"

void engine::base::engineBase::init(engine::base::InitSetting setting) {
    //todo make all logic this i only for test
    this->window.create(sf::VideoMode(setting.width,setting.height),"test");
    this->eventController.setCurrentScene(&this->testowa);
}

void engine::base::engineBase::start() {
    while (this->window.isOpen())//todo main game loop with all nessery logig to show img, events, etc.
    {
        //todo you mas add event for freeze game and resume (ALT+TAB itp.)
        //https://www.sfml-dev.org/tutorials/2.5/window-events.php <-helps
        sf::Event e;
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                this->window.close(); // is necessary
            else
                this->eventController.event(e); //all events from Keyboard and Mouse are handled by the event controller
        }
    }
}
