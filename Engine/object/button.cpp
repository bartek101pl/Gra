//
// Created by Bartek on 28.10.2021.
//

#include "button.h"
#include <iostream>

engine::object::button::button(std::string textureURL, sf::Color textColor, std::string context,int fSize, float x, float y,float w, float h,float tx,float ty) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->textColor = textColor;
    if(!this->buttonTexture.loadFromFile(textureURL))
    {
        throw "Texture not found";
    }
    this->shape.setSize(sf::Vector2f(this->w,this->h));
    this->shape.setPosition(this->x,this->y);
    this->shape.setTexture(&this->buttonTexture);
    if(!this->font.loadFromFile("../assets/arial.ttf"))
    {
        throw "Font not found";
    }
    this->content.setFont(font);
    this->content.setCharacterSize(fSize);
    this->content.setFillColor(this->textColor);
    this->content.setString(context);
    this->content.setPosition(this->x+tx,this->y+ty);

}

void engine::object::button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->shape,states);
    target.draw(this->content,states);
}

void engine::object::button::onMousePressEvent(engine::event::MouseEvent e, sf::Vector2i pos) {
    if(pos.x > shape.getPosition().x&&
    pos.y>shape.getPosition().y&&
    pos.x<shape.getPosition().x+shape.getSize().x&&
    pos.y<shape.getPosition().y+shape.getSize().y)
        this->onclick();
}
