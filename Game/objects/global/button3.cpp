//
// Created by Bartosz Śnieg on 02.01.2022.
//

#include "button3.hpp"
#include "../../../Engine/base/SceneController/SceneController.hpp"
void button3::onclick() {
    switch (this->type) {
        case 1:
            engine::base::SceneController::getInstance()->setCurrentScene(0);
            break;
        case 2:
            engine::base::SceneController::getInstance()->setCurrentScene(1);
            break;

    }

}
