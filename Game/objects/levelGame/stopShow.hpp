//
// Created by Bartosz Śnieg on 31.12.2021.
//

#ifndef GRA_STOPSHOW_HPP
#define GRA_STOPSHOW_HPP
#include "../../../Engine/object/GameObject.h"

class stopShow: public engine::object::GameObject{
public:
    void onInit() override;

    void onKeyPressEvent(std::vector<engine::event::Key> *keyList) override;
};


#endif //GRA_STOPSHOW_HPP
