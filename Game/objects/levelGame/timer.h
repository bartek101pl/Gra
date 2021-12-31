//
// Created by Bartek on 12.12.2021.
//

#ifndef GRA_TIMER_H
#define GRA_TIMER_H

#include "../../../Engine/object/GameObject.h"

class timer :public engine::object::GameObject{

public:
    timer(float time,float x, float y);
    void onUpdate() override;
    void addTime(float t);

    void onDestroyed() override;

private:
    float timeStart = 0;
    float time;
    float maxTime;

};


#endif //GRA_TIMER_H
