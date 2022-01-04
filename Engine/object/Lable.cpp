//
// Created by Bartosz Śnieg on 31.12.2021.
//

#include "Lable.hpp"

Lable::Lable(std::string content, int x, int y, int sizeF) {
    if(!this->font.loadFromFile("../assets/arial.ttf"))
    {
        throw "Font not found";
    }
    this->text.setString(content);
    this->text.setFont(this->font);
    this->text.setCharacterSize(sizeF);
    this->text.setPosition(x,y);
}

void Lable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    GameObject::draw(target, states);

    target.draw(this->text,states);
}

void Lable::setContent(std::string c) {
this->text.setString(c);
}
