#include "Engine/base/engineBase.hpp"
#include "Game/scenes/menu.h"
#include "Game/scenes/levelGame.h"
#include "Game/scenes/final.hpp"
#include "Game/scenes/help.hpp"
int main() {
    // simple implement
    engine::base::SceneController::getInstance()->addScene(new menu("menu"));//0
    engine::base::SceneController::getInstance()->addScene(new levelGame("level",1));//1
    engine::base::SceneController::getInstance()->addScene(new help("help"));//2
    engine::base::SceneController::getInstance()->addScene(new final("final"));//3
    engine::base::engineBase engine{};
    engine.init({false, true,1000,800,60});

    engine.start(0);
    return 0;
}



