//
// Created by Bartek on 19.12.2021.
//

#ifndef GRA_POINTSSHOW_H
#define GRA_POINTSSHOW_H


#include "../../../Engine/object/GameObject.h"

class PointsShow: public engine::object::GameObject{
public:
    PointsShow(int x, int y);
    void addPoint(int p);
    void onInit() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    int getPoints();
private:
    int points = 0;
    sf::Text lable;
    sf::Font font;
};


#endif //GRA_POINTSSHOW_H
