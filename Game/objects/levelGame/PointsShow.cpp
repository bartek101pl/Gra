//
// Created by Bartek on 19.12.2021.
//

#include "PointsShow.h"


void PointsShow::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    GameObject::draw(target, states);
    target.draw(this->lable,states);
}

void PointsShow::addPoint(int p) {
    this->points+=p;
    this->lable.setString("Points: "+ std::to_string(this->points));
}

void PointsShow::onInit() {
this->font.loadFromFile("../assets/arial.ttf");
this->lable.setFont(font);
this->lable.setFillColor(sf::Color::Black);
this->lable.setString("Points: 0");
this->lable.setCharacterSize(20);
}

PointsShow::PointsShow(int x, int y) {
    this->lable.setPosition(x,y);
}

int PointsShow::getPoints() {
    return this->points;
}
