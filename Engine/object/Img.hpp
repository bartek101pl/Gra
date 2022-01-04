//
// Created by Bartosz Śnieg on 04.01.2022.
//

#ifndef GRA_IMG_HPP
#define GRA_IMG_HPP

#include "GameObject.h"

class Img: public engine::object::GameObject{
public:
    Img(std::string url,int x , int y , int w);

    void onInit() override;

    void onDestroyed() override;

protected:
    int x;
    int y;
    int w;
    int h;
    std::string url;
    sf::Texture* image;
};


#endif //GRA_IMG_HPP
