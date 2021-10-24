//
// Created by Bartosz Śnieg on 09.10.2021.
//

#ifndef GRA_PLAYER_HPP
#define GRA_PLAYER_HPP
#include "../../Engine/object/GameObject.h"
#include "../../Engine/Animation/Animation.hpp"

class Player: public engine::object::GameObject {
public:
   void onUpdate() final;
   void onKeyPressEvent(std::vector<engine::event::Key> * keyList) final;
   void onInit() final;
    void leftCollision(GameObject *obj) final;
    void rightCollision(GameObject *obj) final;
    void upCollision(GameObject *obj) final;
    void downCollision(GameObject *obj) final;
    void downExitCollision(GameObject *obj) final;

private:
    sf::Texture texture;
    double V1 = 0;
    double V2 = 0;
    double G = 25.78;
    double T = 50;
    bool flag = true;
    bool flag2 = false;
    char status = 'n';
    Animation *idle;
    Animation *LRun;
    Animation *RRun;
    Animation *Ljump;
    Animation *Rjump;
};


#endif //GRA_PLAYER_HPP
