//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_ENGINEBASE_HPP
#define GRA_ENGINEBASE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "settings.hpp"
#include <string>
#include <SFML/Window.hpp>
#include <map>


#include "../event/EventController.hpp"
#include "../event/staticEvent.h"
#include "../view/scene.hpp"

namespace engine::base {

    class engineBase {
    public:
        engineBase()=default;

        ~engineBase()=default;

        void init(InitSetting setting);
        void loadFromFile(std::string filePath);
        void initFile(std::string filePath);
        void start();

    private:
        sf::Window window;
        event::EventController eventController{};
        view::scene testowa{};
        std::map<std::string, int> m;
                                       /* Uses map to store values of type std::string and int. as example FPS = 30;
                                        * FPS will be stored as "FPS" and 30 will be stored as 30.
                                        * */

    };
}

#endif //GRA_ENGINEBASE_HPP
