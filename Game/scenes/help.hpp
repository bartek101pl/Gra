//
// Created by Bartosz Śnieg on 01.01.2022.
//

#ifndef GRA_HELP_HPP
#define GRA_HELP_HPP
#include "../../Engine/view/scene.hpp"

class help: public engine::view::scene{
public:
    help(std::string name);

    void onInit() override;
};


#endif //GRA_HELP_HPP
