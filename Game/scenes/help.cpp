//
// Created by Bartosz Śnieg on 01.01.2022.
//

#include "help.hpp"
#include "../../Engine/object/Img.hpp"
#include "../../Engine/object/Lable.hpp"
#include "../objects/global/button3.hpp"
help::help(std::string name) : scene(name) {

}

void help::onInit() {
    addChildren(new Lable("Move by means of arrows or keys WASD",10,100,50));
    addChildren(new Lable("You need to collect:",10,200,50));
    addChildren(new Img("../assets/platform/desert/Objects/Crate.png",500,210,50));
    addChildren(new Lable("You can't touch:",10,300,50));
    addChildren(new Img("../assets/platform/desert/Objects/Cactus (1).png",400,300,70));
    addChildren(new Lable("To pause the game, press the ESC button",10,400,50));
    addChildren(new button3("../assets/buttonBG.png", sf::Color::Black, "Exit", 30, 500, 600, 300, 100, 120, 25, 1));
}
