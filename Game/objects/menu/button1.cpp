//
// Created by Bartek on 29.10.2021.
//

#include "button1.h"
#include "../../../Engine/base/SceneController/SceneController.hpp"
#include "../../scenes/menu.h"
void button1::onclick() {
    switch (this->type) {
        case 1:
            ((menu*)engine::base::SceneController::getInstance()->getCurrentScene())->onclic1();
            break;
        case 2:
            ((menu*)engine::base::SceneController::getInstance()->getCurrentScene())->onclic2();
            break;
        case 3:
            ((menu*)engine::base::SceneController::getInstance()->getCurrentScene())->onclic3();
            break;
        case 4:
            ((menu*)engine::base::SceneController::getInstance()->getCurrentScene())->onclic4();
            break;

    }

}
