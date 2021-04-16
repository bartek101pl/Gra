//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_SCENE_HPP
#define GRA_SCENE_HPP

#include <iostream> //todo remove after test
#include <vector>
#include "../event/staticEvent.h"
#include "../event/EventObject.hpp"

namespace engine::view {

    class scene : public event::EventObject {
    public:
         void MouseKeyPressEvent(engine::event::MouseEvent e) final;
         void MouseKeyReleaseEvent(engine::event::MouseEvent e) final;
         void KeyboardKeyPressEvent(std::vector<event::Key> * keyList) final;
         void KeyboardKeyReleaseEvent(std::vector<event::Key> * keyList) final;

    };
}

#endif //GRA_SCENE_HPP
