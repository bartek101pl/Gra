//
// Created by Bartek on 29.10.2021.
//

#include "button2.h"
#include "../../../Engine/base/SceneController/SceneController.hpp"
#include "../../scenes/levelGame.h"
void button2::onclick() {
    switch (this->type) {
        case 0:
            ((levelGame*)engine::base::SceneController::getInstance()->getCurrentScene())->resume();
            break;
        case 1:
            ((levelGame*)engine::base::SceneController::getInstance()->getCurrentScene())->endGame();
            break;


    }

}
