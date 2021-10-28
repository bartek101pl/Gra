//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_SCENE_HPP
#define GRA_SCENE_HPP


#include <vector>
#include "../event/staticEvent.h"
#include "../event/EventObject.hpp"
#include "../object/GameObject.h"
#include "../event/AbstractUserEventObject.hpp"
#include "../object/AbstractGameObject.hpp"

namespace engine::view {

    class scene : public engine::object::AbstractGameObject, public sf::Drawable{
    public:
        scene(std::string name);
        virtual std::string getName() final;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        std::string name;

    };
}

#endif //GRA_SCENE_HPP
