//
// Created by Bartek on 28.10.2021.
//

#ifndef GRA_LEVELGAME_H
#define GRA_LEVELGAME_H

#include "../../Engine/view/scene.hpp"
#include "../objects/levelGame/pointArea.h"
#include "../objects/levelGame/ObjectD.h"
#include <random>
class levelGame: public engine::view::scene{
public:
    levelGame(std::string name, int levelType);
    void onInit() override;
    void onUpdate() override;
    void onDestroyed() override;
    void hit();
    void point(ObjectD* obj);
private:
    std::random_device rd;
    int levelType;
    std::vector<pointArea> pointsArea;
    void loadGameFromFile(std::string url);
    std::mt19937 gen;
};


#endif //GRA_LEVELGAME_H
