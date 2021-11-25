//
// Created by Bartek on 31.10.2021.
//

#ifndef GRA_PLAYER_H
#define GRA_PLAYER_H

#include "../../../Engine/object/GameObject.h"
#include "../../../Engine/Animation/Animation.hpp"

class player: public engine::object::GameObject{
public:
    player(std::string file);
    void onUpdate() final;
    void onKeyPressEvent(std::vector<engine::event::Key> * keyList) final;
    void onInit() final;
    void leftCollision(engine::object::GameObject *obj) final;
    void rightCollision(engine::object::GameObject *obj) final;
    void upCollision(engine::object::GameObject *obj) final;
    void downCollision(engine::object::GameObject *obj) final;
    void downExitCollision(engine::object::GameObject *obj) final;

private:
    std::string file;
    sf::Texture texture;
    double V1 = 0;
    double V2 = 0;
    double G = 25.78;
    double T = 50;
    bool flag = true;
    bool flag2 = false;
    char status = 'n';
    engine::animation::Animation *idle;
    engine::animation::Animation *LRun;
    engine::animation::Animation *RRun;
    engine::animation::Animation *Ljump;
    engine::animation::Animation *Rjump;
};


#endif //GRA_PLAYER_H
