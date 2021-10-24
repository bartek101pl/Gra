//
// Created by Bartosz Śnieg on 09.10.2021.
//

#include "MainScene.hpp"
#include "Objects/Wall.hpp"
#include <iostream>
void MainScene::onInit() {
    this->addChildren(new Player());
    this->addChildren(new Wall(0,550,800,50));
    this->addChildren(new Wall(0,0,25,600));
    this->addChildren(new Wall(775,0,25,600));
}

void MainScene::onUpdate() {
        for (int i1 = 0; i1 < this->children->size(); ++i1) {
            AbstractGameObject *a1 = (this->children->at(i1));
            engine::object::GameObject* obj1 = (engine::object::GameObject*) a1;
            for (int i2 = i1+1; i2 < this->children->size(); ++i2) {
                AbstractGameObject *a2 = (this->children->at(i2));
                engine::object::GameObject* obj2 = (engine::object::GameObject*) a2;

                obj1->collisionCalc(obj2);
            }
        }

}
