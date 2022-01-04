//
// Created by Bartosz Śnieg on 04.01.2022.
//

#include "Img.hpp"

void Img::onInit() {
this->image = new sf::Texture;
this->image->loadFromFile(this->url);
this->h = (this->image->getSize().y/this->image->getSize().x)*this->w;
this->shape.setSize(sf::Vector2f(this->w,this->h));
this->shape.setPosition(this->x ,this->y);
this->shape.setTexture(this->image);
}

void Img::onDestroyed() {
delete this->image;
}

Img::Img(std::string url, int x, int y, int w) {
    this->url = url;
    this->x = x;
    this->y = y;
    this->w = w;

}
