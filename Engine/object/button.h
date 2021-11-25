//
// Created by Bartek on 28.10.2021.
//

#ifndef GRA_BUTTON_H
#define GRA_BUTTON_H
#include "GameObject.h"
namespace engine::object {
    class button: public GameObject{
    public:
        button(std::string textureURL,sf::Color textColor,std::string context ,int fSize, float x, float y , float w, float h,float tx,float ty);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void onMousePressEvent(engine::event::MouseEvent e, sf::Vector2i pos);
    private:
        float x,y,w,h;
        sf::Color textColor;
        sf::Texture buttonTexture;
        sf::Font font;
        sf::Text content;
    protected:
        virtual void onclick()=0;

    };
}

#endif //GRA_BUTTON_H
