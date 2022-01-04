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
                new button1("../assets/buttonBG.png", sf::Color::Black, "Level 1", 30, x, y, 300, 100, 100, 25, 1));
        this->addChildren(
                new button1("../assets/buttonBG.png", sf::Color::Black, "Level 2", 30, x, y + 120, 300, 100, 100, 25,
                            2));
    this->addChildren(
            new button1("../assets/buttonBG.png", sf::Color::Black, "Help", 30, x, y + (2 * 120), 300, 100, 120, 25,
                        3));
        this->addChildren(
                new button1("../assets/buttonBG.png", sf::Color::Black, "Exit", 30, x, y + (3 * 120), 300, 100, 120,
                            25, 4));
        std::cout << this->children->size() << std::endl;

}

void menu::onclic1() {
engine::base::SceneController::getInstance()->setCurrentScene(1);
}
void menu::onclic2() {
    std::cout<<"Dziala 2"<<std::endl;
}
void menu::onclic3() {
    engine::base::SceneController::getInstance()->setCurrentScene(2);
}
void menu::onclic4() {
    engine::base::SceneController::getInstance()->End();
}