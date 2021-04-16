//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_ENGINEBASE_HPP
#define GRA_ENGINEBASE_HPP

#include "settings.hpp"
#include <string>
#include <SFML/Window.hpp>

#include "../event/EventController.hpp"
#include "../event/staticEvent.h"
#include "../view/scene.hpp"

namespace engine::base {

    class engineBase {
    public:
        engineBase()=default;

        ~engineBase()=default;

        void init(InitSetting setting); //todo load setting from struct

        void initFile(std::string filePath); //todo load setting from file and you mast ad function to save
        void start();

    private:
        sf::Window window;
        event::EventController eventController{};
        view::scene testowa{};
    };
}

#endif //GRA_ENGINEBASE_HPP
