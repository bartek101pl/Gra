//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "scene.hpp"

void engine::view::scene::KeyboardKeyPressEvent(std::vector<event::Key> *keyList) {
    std::cout<<"KeyboardKeyPress: "<<keyList->size()<<std::endl;
}

void engine::view::scene::KeyboardKeyReleaseEvent(std::vector<event::Key> *keyList) {
    std::cout<<"KeyboardKeyRelease: "<<keyList->size()<<std::endl;
}

void engine::view::scene::MouseKeyReleaseEvent(engine::event::MouseEvent e) {
    std::cout<<"MouseEventRelease: "<<e<<std::endl;

}

void engine::view::scene::MouseKeyPressEvent(engine::event::MouseEvent e) {
    std::cout<<"MouseEventPress: "<<e<<std::endl;
}

void engine::view::scene::update() {

}

void engine::view::scene::addChildren(engine::object::GameObject obj) {
    if(this->children == nullptr)
        this->children = new std::vector<engine::object::GameObject>();
    this->children->push_back(obj);
}


