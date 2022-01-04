//
// Created by Bartosz Śnieg on 16.04.2021.
//

#include "scene.hpp"

engine::view::scene::scene(std::string name) {
    this->name = name;
}

std::string engine::view::scene::getName() {
    return this->name;
}

void engine::view::scene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(this->children!= nullptr&&!this->freeze)
        for (auto& item : *this->children)
        {
            if(item->getVisibility())
                ((engine::object::GameObject*)item)->draw(target,states);
        }
}