//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "engineBase.hpp"

void engine::base::engineBase::init(engine::base::InitSetting setting) {
    //todo make all logic this i only for test;
    if(setting.fullScreen) {
        this->window.create(sf::VideoMode::getFullscreenModes()[0],
                            "test",
                            sf::Style::Fullscreen);
                                                                                    /* If setting.fullScreen is  true - sets Fullscreen.
                                                                                         Function getFullscreenModes returns an array
                                                                                          which sorted from higher quality to lower.
                                                                                          So the first element with index 0 - best ratio.
                                                                                          At this moment it's the best choice IMO
                                                                                                  */
    }
     else if(!setting.fullScreen)
    this->window.create(sf::VideoMode(setting.width,setting.height),"test");


    if(setting.lockFPS)                                                              //  If setting.lockFPS is  true - sets FPS lock.
        this->window.setFramerateLimit(setting.FPS);


    this->eventController.setCurrentScene(&this->testowa);

}

void engine::base::engineBase::saveSettingsToMap(std::map<std::string, int> m){      // Saves m from function parameter to our class variable m
    this->m = m;

}


void engine::base::engineBase::loadFromFile(std::string filePath){
    /* @return void
     * This function takes path to file as a parameter, then stores
     * std::string files to key and int to value, as example: FPS = 30,
     * FPS will be stored as key and 30 will be stored as value
     * Later it calls function saveSettingsToMap to save this map value in our class.
     * IMO if we can't return map as a return value, so I can just call saveSettingsMap in this function
     * */
    std::map<std::string, int>params;
    std::ifstream paramFile;
    paramFile.open(filePath);
    std::string key;
    int value;
    while ( paramFile >> key >> value ) {
        params[key] = value; // input them into the map
    }
    this->saveSettingsToMap(params);


}

void engine::base::engineBase::initFile(std::string filePath){
    this->loadFromFile(filePath);
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
