//
// Created by Bartek on 28.10.2021.
//

#ifndef GRA_LEVELGAME_H
#define GRA_LEVELGAME_H

#include "../../Engine/view/scene.hpp"
#include "../objects/levelGame/pointArea.h"
#include "../objects/levelGame/ObjectD.h"
#include <random>
#include "../objects/levelGame/timer.h"
#include "../objects/levelGame/PointsShow.h"

class levelGame: public engine::view::scene{
public:
    levelGame(std::string name, int levelType);
    void onInit() override;
    void onUpdate() override;
    void onDestroyed() override;
    void hit();
    void point(ObjectD* obj);
    void resume();
    void onKeyPressEvent(std::vector<engine::event::Key> *keyList) override;
    void endGame();
private:
    std::random_device rd;
    int levelType;
    std::vector<pointArea> pointsArea;
    void loadGameFromFile(std::string url);
    std::mt19937 gen;
    timer *t;
    PointsShow *pointsShow;
    bool status = false;
    float tim = 0;
};


#endif //GRA_LEVELGAME_H
