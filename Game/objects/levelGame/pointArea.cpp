//
// Created by Bartek on 13.11.2021.
//

#include "pointArea.h"
#include <cstdlib>

pointArea::pointArea(int x, int y, int w) {
    this->x = x;
    this->y = y;
    this->w = w;
}

int pointArea::getRandomPos() {
    return rand()%this->w;
}

int pointArea::getRandomPos(int objW) {
    return rand()%(this->w-objW);
}

int pointArea::getX() {
    return this->x;
}

int pointArea::getY() {
    return this->y;
}
