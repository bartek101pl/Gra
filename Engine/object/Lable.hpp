//
// Created by Bartosz Śnieg on 31.12.2021.
//

#ifndef GRA_LABLE_HPP
#define GRA_LABLE_HPP

#include "GameObject.h"

class Lable: public engine::object::GameObject{
public:
Lable(std::string content, int x ,int y , int sizeF);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setContent(std::string c);
protected:
    sf::Text text;
    sf::Font font;
};


#endif //GRA_LABLE_HPP
