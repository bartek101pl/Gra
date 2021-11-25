//
// Created by Bartek on 03.11.2021.
//

#ifndef GRA_OBJECTD_H
#define GRA_OBJECTD_H

#include "Wall.h"

class ObjectD: public Wall{
public:
    ObjectD(std::string file,int x,int y,int w, int h,bool hit);
    void enterCollision(GameObject* obj);

private:
    bool hit;
};


#endif //GRA_OBJECTD_H
