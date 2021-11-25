//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "EventController.hpp"

namespace engine::event {

    EventController* EventController::_singleton;

    EventController::~EventController() {
        delete this->sceneC;
    }

    void EventController::event(sf::Event e) {

        switch (e.type) {
            case sf::Event::MouseButtonReleased:
                this->mouseKeyRelease();

                break;
            case sf::Event::MouseButtonPressed:
                this->mouseKeyPress();

                break;
//            case sf::Event::KeyReleased:
//                this->keyRelease();
//                break;
//            case sf::Event::KeyPressed:
//                this->keyPress();
//                break;
        }

    }


    void EventController::GetPressKey(std::vector<Key> *list) {
        list->clear();
        for (int i = -1; i < sf::Keyboard::KeyCount; ++i) {
            if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) i))
                list->push_back((sf::Keyboard::Key) i);
        }
    }


    void EventController::mouseKeyRelease() {
        bool lButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool rButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Right);

        if (!lButtonStatus && lastLButtonStatus)
            this->sceneC->getCurrentScene()->MouseKeyReleaseEvent(LButton,mousePos);
        if (!rButtonStatus && lastRButtonStatus)
            this->sceneC->getCurrentScene()->MouseKeyReleaseEvent(RButton,mousePos);
        this->lastLButtonStatus = lButtonStatus;
        this->lastRButtonStatus = rButtonStatus;
    }

    void EventController::mouseKeyPress() {
        bool lButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool rButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Right);

        if (lButtonStatus)
            this->sceneC->getCurrentScene()->MouseKeyPressEvent(LButton,this->mousePos);
        if (rButtonStatus)
            this->sceneC->getCurrentScene()->MouseKeyPressEvent(RButton,this->mousePos);

        this->lastLButtonStatus = lButtonStatus;
        this->lastRButtonStatus = rButtonStatus;
    }

    void EventController::keyRelease() {
        this->releaseKeys.clear();
        this->GetPressKey(&this->pressKeys);


        //create vector with release key
        for (auto i : lastPressKeys) {
            this->flag = true;
            for (int j = 0; j < pressKeys.size(); ++j) {
                if (i == j) {
                    this->flag = false;
                    break;
                }
            }
            if (this->flag)
                this->releaseKeys.push_back(i);
        }

        if (!this->releaseKeys.empty())
            this->sceneC->getCurrentScene()->KeyboardKeyReleaseEvent(&this->releaseKeys);
        this->lastPressKeys = pressKeys;
    }

    void EventController::keyPress() {
        this->GetPressKey(&this->pressKeys);
        if (!pressKeys.empty())
            this->sceneC->getCurrentScene()->KeyboardKeyPressEvent(&this->pressKeys);
        this->lastPressKeys = pressKeys;
    }

    void EventController::init() {
        this->sceneC = engine::base::SceneController::getInstance();
    }

    EventController *EventController::getInstance() {
        if(_singleton == nullptr)
            _singleton = new EventController();
        return _singleton;
    }

    void EventController::setMousePos(sf::Vector2i pos) {
        this->mousePos = pos;
    }

}