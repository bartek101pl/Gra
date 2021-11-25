//
// Created by Bartosz Śnieg on 10.08.2021.
//

#include "AbstractUserEventObject.hpp"

void engine::event::AbstractUserEventObject::onKeyPressEvent(std::vector<event::Key> *keyList) {

}

void engine::event::AbstractUserEventObject::onKeyReleaseEvent(std::vector<event::Key> *keyList) {

}

void engine::event::AbstractUserEventObject::onMousePressEvent(engine::event::MouseEvent e, sf::Vector2i pos) {

}

void engine::event::AbstractUserEventObject::onMouseReleaseEvent(engine::event::MouseEvent e, sf::Vector2i pos) {

}

void engine::event::AbstractUserEventObject::onDestroyed() {

}

void engine::event::AbstractUserEventObject::onInit() {

}

void engine::event::AbstractUserEventObject::onUpdate() {

}

bool engine::event::AbstractUserEventObject::isKeyPress(std::vector<sf::Keyboard::Key> l, sf::Keyboard::Key k) {
    int i = -1;

    for(int r=0;r<l.size();r++)
    {
        if(l[r] == k)
        {
            i=r;
            break;
        }
    }
    return i!=-1;
}
