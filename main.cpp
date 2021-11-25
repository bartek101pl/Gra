#include "Engine/base/engineBase.hpp"
#include "Game/scenes/menu.h"
#include "Game/scenes/levelGame.h"

int main() {
    // simple implement
    engine::base::SceneController::getInstance()->addScene(new menu("menu"));
    engine::base::SceneController::getInstance()->addScene(new levelGame("level",1));
    engine::base::engineBase engine{};
    engine.init({false, true,1000,800,60});
    engine.start(0);
    return 0;
}



