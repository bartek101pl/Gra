//
// Created by Bartek on 28.10.2021.
//

#include "levelGame.h"
#include "../objects/levelGame/player.h"
#include "../objects/menu/bg.h"
#include "../objects/levelGame/Wall.h"
#include "../objects/levelGame/ObjectD.h"
#include <cstdlib>
#include <ctime>
#include "../../Engine/base/SceneController/SceneController.hpp"

levelGame::levelGame(std::string name, int levelType): engine::view::scene(name){
    this->levelType = levelType;
}

void levelGame::onInit() {
    this->gen = std::mt19937(this->rd());
    //TODO improve level loading
    switch (this->levelType) {
        case 1:
            this->addChildren(new bg("../assets/platform/desert/BG.png"));
            this->addChildren(new player("redhat"));
            this->addChildren(new Wall("../assets/platform/desert/Objects/StoneBlock.png",0,-40,30,840));
            this->addChildren(new Wall("../assets/platform/desert/Objects/StoneBlock.png",970,-40,30,840));
            this->addChildren(new Wall("../assets/platform/desert/Tile/2.png",-20,770,1020,30));
            this->addChildren(new Wall("../assets/platform/desert/Tile/2.png",-20,-20,1020,30));
            for (int i = 660; i >80 ; i-=130) {
                int s = 160;
                std::uniform_int_distribution<> distC(10,(940/2)-s);
                int c = distC(this->gen);

                this->addChildren(new Wall("../assets/platform/desert/Tile/2.png",30,i,c,30));
                this->addChildren(new Wall("../assets/platform/desert/Tile/2.png",970-c,i,c,30));
                this->addChildren(new Wall("../assets/platform/desert/Tile/2.png",30+c+s,i,(((940/2)-c-s)*2),30));

                std::uniform_int_distribution<> distD(0,((((940/2)-c-s)*2)-50));
                int d = distD(this->gen);
                if(((((940/2)-c-s)*2)-50)>50) {
                    this->addChildren(
                            new ObjectD("../assets/platform/desert/Objects/Cactus (1).png", d + 30 + c + s, i - 90, 50,
                                        90, true));
                    this->pointsArea.push_back(pointArea(0, i, d + 30 + c + s));
                    this->pointsArea.push_back(pointArea(d + 30 + c + s + 50, i, 940 - (d + 30 + c + s + 50)));
                }else{
                    this->pointsArea.push_back(pointArea(0, i, 940));
                }
            }
            int c = rand()%this->pointsArea.size();
            this->addChildren(
                    new ObjectD("../assets/platform/desert/Objects/Crate.png", this->pointsArea.at(c).getX()+this->pointsArea.at(c).getRandomPos(50),
                                this->pointsArea.at(c).getY()-50, 50,50, false));
        break;
    }
}

void levelGame::onUpdate() {
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

void levelGame::hit() {
    this->onDestroyed();
    engine::base::SceneController::getInstance()->setCurrentScene(0);
}

void levelGame::point(ObjectD* obj) {
    std::cout<<"POINT"<<std::endl;
    for (int i = 0; i < this->children->size(); ++i) {
        if(obj == (ObjectD*) this->children->at(i))
        {
            this->children->erase(std::next(children->begin(), i));
            break;
        }
    }
    int c = rand()%this->pointsArea.size();
    this->addChildren(
            new ObjectD("../assets/platform/desert/Objects/Crate.png", this->pointsArea.at(c).getX()+this->pointsArea.at(c).getRandomPos(50),
                        this->pointsArea.at(c).getY()-50, 50,50, false));
}

void levelGame::onDestroyed() {
std::cout<<"dell"<<std::endl;
    for(auto a : *this->children)
    {
        delete a;
    }
    this->children->clear();
}

void levelGame::loadGameFromFile(std::string url) {
    //read form file all files;
}
