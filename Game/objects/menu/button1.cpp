//
// Created by Bartek on 29.10.2021.
//

#include "button1.h"
#include "../../../Engine/base/SceneController/SceneController.hpp"
#include "../../scenes/menu.h"
void button1::onclick() {
    switch (this->type) {
        case 1:
            ((menu*)engine::base::SceneController::getInstance()->getScene("menu"))->onclic1();
            break;
        case 2:
            ((menu*)engine::base::SceneController::getInstance()->getScene("menu"))->onclic2();
            break;
        case 3:
            ((menu*)engine::base::SceneController::getInstance()->getScene("menu"))->onclic3();
            break;
    }

}
