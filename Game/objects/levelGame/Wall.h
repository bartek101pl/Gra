//
// Created by Bartek on 31.10.2021.
//

#ifndef GRA_WALL_H
#define GRA_WALL_H

#include "../../../Engine/object/GameObject.h"

class Wall: public engine::object::GameObject{
public:
    Wall(std::string file,int x,int y,int w, int h);
    void onInit() override;

protected:
    sf::Texture tx;
    std::string file;
};


#endif //GRA_WALL_H
