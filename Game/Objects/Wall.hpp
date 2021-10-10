//
// Created by Bartosz Śnieg on 09.10.2021.
//

#ifndef GRA_WALL_HPP
#define GRA_WALL_HPP
#include "../../Engine/object/GameObject.h"

class Wall: public engine::object::GameObject{
public:
    Wall(float x,float y,float w,float h);

};


#endif //GRA_WALL_HPP
