//
// Created by Bartek on 28.10.2021.
//

#ifndef GRA_MENU_H
#define GRA_MENU_H

#include "../../Engine/view/scene.hpp"

class menu: public engine::view::scene{
public:
    menu(std::string name): engine::view::scene(name){};
    void onInit() final;
    void onclic1();
    void onclic2();
    void onclic3();
    void onclic4();

private:
    bool isok = false;

};


#endif //GRA_MENU_H
