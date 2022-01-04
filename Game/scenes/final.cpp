//
// Created by Bartosz Śnieg on 01.01.2022.
//

#include "final.hpp"
#include "../objects/global/button3.hpp"

final::final(std::string name) : scene(name) {

}

void final::onInit() {
    addChildren(new Lable("End game",290,100,100));
    this->points = new Lable(this->sPoints,360,300,50);
    this->time = new Lable(this->sTime,360,400,50);
    addChildren(new Lable("points: ",200,300,50));
    addChildren(new Lable("time: ",200,400,50));
    addChildren(this->points);
    addChildren(this->time);
    addChildren(new button3("../assets/buttonBG.png", sf::Color::Black, "Play again", 30, 100, 600, 300, 100, 80, 25, 2));
    addChildren(new button3("../assets/buttonBG.png", sf::Color::Black, "Exit", 30, 500, 600, 300, 100, 120, 25, 1));
}

void final::setData(int p, float t) {
    this->sPoints = (std::to_string(p));
    this->sTime = (std::to_string(t)+" s");

}
