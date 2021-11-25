//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_EVENTOBJECT_HPP
#define GRA_EVENTOBJECT_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "staticEvent.h"

namespace engine { namespace event {
    class EventObject {
    public:
        //virtual function for events
        virtual void MouseKeyPressEvent(MouseEvent event , sf::Vector2i pos);
        virtual void MouseKeyReleaseEvent(MouseEvent event, sf::Vector2i pos);

        //todo make scroll event
//        virtual void MouseScrollEvent(MouseEvent event);
        virtual void KeyboardKeyPressEvent(std::vector<event::Key> * keyList);
        virtual void KeyboardKeyReleaseEvent(std::vector<event::Key> * keyList);
    };
} }

#endif //GRA_EVENTOBJECT_HPP
