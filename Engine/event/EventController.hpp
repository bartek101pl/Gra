//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_EVENTCONTROLLER_HPP
#define GRA_EVENTCONTROLLER_HPP

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window.hpp>
#include "staticEvent.h"
#include "../view/scene.hpp"
#include "../base/SceneController/SceneController.hpp"
#include <SFML/System/Vector2.hpp>

namespace engine::event {

    class EventController {
    public:
        EventController() = default;

        ~EventController();
        static EventController* _singleton;
        static EventController* getInstance();

        /**
         * Function which is call every loop
         */
        void event(sf::Event e);
        void keyPress();
        void keyRelease();
        void init();
        void setMousePos(sf::Vector2i pos);
    private:

        engine::base::SceneController* sceneC;

        bool flag = true;

        /**
         * Current view scene
         */
//        EventObject *object{};
        /**
         * List of last press keys
         */
        std::vector<Key> lastPressKeys;
        std::vector<Key> pressKeys;
        std::vector<Key> releaseKeys;
        sf::Vector2i mousePos;

        bool lastLButtonStatus{};
        bool lastRButtonStatus{};

        static void GetPressKey(std::vector<Key> *list);

        void mouseKeyPress();
        void mouseKeyRelease();
    };

}

#endif //GRA_EVENTCONTROLLER_HPP
