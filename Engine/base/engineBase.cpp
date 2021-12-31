//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "engineBase.hpp"

//#include <utility>
sf::Time engine::base::engineBase::deltaTime;
void engine::base::engineBase::init(engine::base::InitSetting setting) {

    this->sceneC = SceneController::getInstance();

    this->eventController = event::EventController::getInstance();
    this->eventController->init();

    //todo make all logic this i only for test;
    if(setting.fullScreen) {
        this->window.create(sf::VideoMode::getFullscreenModes()[0],
                            "test",
                            sf::Style::Fullscreen);
    }
     else if(!setting.fullScreen)
    this->window.create(sf::VideoMode(setting.width,setting.height),"test");


    if(setting.lockFPS)                                                              //  If setting.lockFPS is  true - sets FPS lock.
        this->window.setFramerateLimit(setting.FPS);




}


void engine::base::engineBase::loadFromFile(const std::string& filePath){
    /* @return void
     * This function takes path to file as a parameter, then stores
     * std::string files to key and int to value, as example: FPS = 30,
     * FPS will be stored as key and 30 will be stored as value
     * */
    this->m.clear();
    std::ifstream paramFile;
    paramFile.open(filePath);
    std::string key;
    int value;
    while ( paramFile >> key >> value ) {
       this->m[key] = value; // input them into the map
    }


}

void engine::base::engineBase::initFile(std::string filePath){
    this->loadFromFile(std::move(filePath));
}

void engine::base::engineBase::start(int idScean) {
    this->sceneC->setCurrentScene(idScean);
    while (this->window.isOpen())//todo main game loop with all nessery logig to show img, events, e.t.c.
    {
        //todo you mast add event for freeze game and resume (ALT+TAB e.t.c.)
        //https://www.sfml-dev.org/tutorials/2.5/window-events.php <-helps
        sf::Event e{};
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                this->window.close(); // is necessary
            else
                this->eventController->event(e); //all events from Keyboard and Mouse are handled by the event controller
        }
        this->sceneC->update();
        this->eventController->keyRelease();
        this->eventController->keyPress();
        this->eventController->setMousePos(sf::Mouse::getPosition(this->window));
        this->sceneC->getCurrentScene()->updateEvent();
        this->window.clear(sf::Color::Black);
        this->window.draw(*this->sceneC->getCurrentScene());
        this->window.display();
        deltaTime = this->timer.restart();
    }

}
