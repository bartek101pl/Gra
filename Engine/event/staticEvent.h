//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_STATICEVENT_H
#define GRA_STATICEVENT_H

#include <SFML/Window/Keyboard.hpp>

namespace engine { namespace event {
    typedef sf::Keyboard::Key Key;

//    /**
//     * Type of events
//     */
//    enum EVENTTYPE {
//        MouseLClick = 0,
//        MouseRClick,
//        ScrollUp,
//        ScrollDown,
//        Move,
//        KeyDown,
//        KeyUp
//    };

enum MouseEvent{
    LButton,
    RButton,
    ScrollUP,
    ScrollDow
};

} }
#endif //GRA_STATICEVENT_H
