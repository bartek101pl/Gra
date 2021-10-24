//
// Created by Bartosz Śnieg on 23.10.2021.
//

#ifndef GRA_ANIMATION_HPP
#define GRA_ANIMATION_HPP

#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>

class Animation {
public:

    Animation(sf::Shape *object, std::string filepath , std::string configfilename ,uint8_t fps, bool rep);
    void update();
    void update(float s);

private:
    sf::Shape * object; // pointer to animate object shape
    std::string filepath; // path to config file
    std::vector<sf::Texture> files; // table file
    float dt;
    float dtL = 0;
    int i;
    bool rep;
    int fps;
};


#endif //GRA_ANIMATION_HPP
