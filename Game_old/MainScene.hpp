//
// Created by Bartosz Śnieg on 09.10.2021.
//

#ifndef GRA_MAINSCENE_HPP
#define GRA_MAINSCENE_HPP

#include "../Engine/view/scene.hpp"
#include "Objects/Player.hpp"
class MainScene : public engine::view::scene {
public:
    MainScene(std::string name): engine::view::scene(name){};
    virtual void onInit();
    virtual void onUpdate();
};


#endif //GRA_MAINSCENE_HPP
