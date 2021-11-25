//
// Created by Bartek on 03.11.2021.
//

#include "ObjectD.h"

#include "../../../Engine/base/SceneController/SceneController.hpp"
#include "../../scenes/levelGame.h"
ObjectD::ObjectD(std::string file, int x, int y, int w, int h,bool hit) : Wall(file, x, y, w, h) {
    this->isBlock = false;
    this->hit =hit;
}

void ObjectD::enterCollision(GameObject* obj) {
  engine::object::AbstractGameObject *r = engine::base::SceneController::getInstance()->getCurrentScene()->getChildren(1);
  if(r == obj)
      if(hit)
      ((levelGame*)engine::base::SceneController::getInstance()->getCurrentScene())->hit();
      else
          ((levelGame*)engine::base::SceneController::getInstance()->getCurrentScene())->point(this);
}
