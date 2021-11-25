//
// Created by Bartek on 13.11.2021.
//

#ifndef GRA_POINTAREA_H
#define GRA_POINTAREA_H


class pointArea {
public:
    pointArea(int x,int y, int w);
    int getRandomPos();
    int getRandomPos(int objW);
    int getX();
    int getY();
private:
    int x,y,w;
};


#endif //GRA_POINTAREA_H
