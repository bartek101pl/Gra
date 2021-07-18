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

namespace engine::event {
    class EventController {
    public:
        EventController() = default;

        ~EventController();

        /**
         * Function which is call every loop
         */
        [[maybe_unused]] void event(sf::Event e);

        /**
         * Set new current use scene
         */
        void setCurrentScene(view::scene *scene);

    private:

        bool flag = true;

        /**
         * Current view scene
         */
        EventObject *object;
        /**
         * List of last press keys
         */
        std::vector<Key> lastPressKeys;
        std::vector<Key> pressKeys;
        std::vector<Key> releaseKeys;


        bool lastLButtonStatus;
        bool lastRButtonStatus;
        /**
        *
        * auxiliary function to get list of current press keys
        *
        * @return std::vector with all keys which is now press
        */
        void GetPressKey(std::vector<Key> *list);
        void keyPress();
        void keyRelease();
        void mouseKeyPress();
        void mouseKeyRelease();
    };
}

#endif //GRA_EVENTCONTROLLER_HPP
