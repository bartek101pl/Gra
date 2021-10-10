//
// Created by Bartosz Śnieg on 16.04.2021.
//

#ifndef GRA_SETTINGS_HPP
#define GRA_SETTINGS_HPP

namespace engine::base{

    struct InitSetting{
        bool fullScreen; //if is true width and height will set auto in init
        bool lockFPS; // if is set FPS value is required
        int width = 0;
        int height = 0;
        int FPS = 0;
    };
}
#endif //GRA_SETTINGS_HPP
