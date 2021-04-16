//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "EventController.hpp"

namespace engine::event {

    EventController::~EventController() {
        delete this->object;
    }

    [[maybe_unused]] void EventController::event() {

        this->GetPressKey(&this->pressKeys);
        std::vector<Key> result;
        bool lButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool rButtonStatus = sf::Mouse::isButtonPressed(sf::Mouse::Right);

        if (lButtonStatus)
            this->object->MouseKeyPressEvent(LButton);
        if (rButtonStatus)
            this->object->MouseKeyPressEvent(RButton);
        if (!lButtonStatus && lastLButtonStatus)
            this->object->MouseKeyReleaseEvent(LButton);
        if (!rButtonStatus && lastRButtonStatus)
            this->object->MouseKeyReleaseEvent(RButton);

        this->lastLButtonStatus = lButtonStatus;
        this->lastRButtonStatus = rButtonStatus;

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

        if (this->releaseKeys.size() > 0)
            this->object->KeyboardKeyReleaseEvent(&this->releaseKeys);

        if (pressKeys.size() > 0)
            this->object->KeyboardKeyPressEvent(&this->pressKeys);


        this->lastPressKeys = pressKeys;
    }


    [[maybe_unused]]  void EventController::GetPressKey(std::vector<Key> *list) {
        for (int i = -1; i < sf::Keyboard::KeyCount; ++i) {
            if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) i))
                list->push_back((sf::Keyboard::Key) i);
        }
    }

    [[maybe_unused]]  void EventController::setCurrentScene(view::scene *scene) {
        this->object = scene;
    }

}