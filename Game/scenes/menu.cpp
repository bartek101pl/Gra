//
// Created by Bartek on 28.10.2021.
//

#include "menu.h"
#include "../objects/menu/bg.h"
#include "../objects/menu/button1.h"
#include "../../Engine/base/SceneController/SceneController.hpp"
#include "levelGame.h"
#include <iostream>
void menu::onInit() {
        this->addChildren(new bg("../assets/bg.jpg"));
        int x = (1000 - 300) / 2;
        int y = 100;
        this->addChildren(
                new button1("../assets/buttonBG.png", sf::Color::Black, "Poziom 1", 30, x, y, 300, 100, 80, 25, 1));
        this->addChildren(
                new button1("../assets/buttonBG.png", sf::Color::Black, "Poziom 2", 30, x, y + 120, 300, 100, 80, 25,
                            2));
        this->addChildren(
                new button1("../assets/buttonBG.png", sf::Color::Black, "Poziom 3", 30, x, y + (2 * 120), 300, 100, 80,
                            25, 3));
        std::cout << this->children->size() << std::endl;

}

void menu::onclic1() {
engine::base::SceneController::getInstance()->setCurrentScene(1);
}
void menu::onclic2() {
    std::cout<<"Dziala 2"<<std::endl;
}
void menu::onclic3() {
    std::cout<<"Dziala 3"<<std::endl;
}
