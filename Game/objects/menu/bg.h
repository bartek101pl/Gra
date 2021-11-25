//
// Created by Bartek on 28.10.2021.
//

#ifndef GRA_BG_H
#define GRA_BG_H
#include "../../../Engine/object/GameObject.h"

class bg: public engine::object::GameObject {
public:
    bg(std::string file);
    void onInit() final;

private:
    sf::Texture tx;
    std::string file;
};


#endif //GRA_BG_H
