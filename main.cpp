#include "Engine/base/engineBase.hpp"
#include "Game/MainScene.hpp"

int main() {
    // simple implement
    engine::base::SceneController::getInstance()->addScene(new MainScene("main"));
    engine::base::engineBase engine{};
    engine.init({false, true,800,600,60});
    engine.start(0);
    return 0;
}



