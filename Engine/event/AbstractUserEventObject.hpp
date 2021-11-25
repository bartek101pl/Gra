//
// Created by Bartosz Śnieg on 10.08.2021.
//

#ifndef GRA_ABSTRACTUSEREVENTOBJECT_HPP
#define GRA_ABSTRACTUSEREVENTOBJECT_HPP
#include "vector"
#include "staticEvent.h"
#include <SFML/System/Vector2.hpp>
namespace engine::event{
    class AbstractUserEventObject {
    public:
//        AbstractUserEventObject() = default;
        virtual void onKeyPressEvent(std::vector<event::Key> * keyList);
        virtual void onKeyReleaseEvent(std::vector<event::Key> * keyList);
        virtual void onMousePressEvent(engine::event::MouseEvent e, sf::Vector2i pos);
        virtual void onMouseReleaseEvent(engine::event::MouseEvent e, sf::Vector2i pos);
        virtual void onDestroyed();
        virtual void onInit();
        virtual void onUpdate();
        virtual bool isKeyPress(std::vector<sf::Keyboard::Key> l, sf::Keyboard::Key k) final;
    };
}

#endif //GRA_ABSTRACTUSEREVENTOBJECT_HPP
