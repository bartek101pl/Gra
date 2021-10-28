//
// Created by Bartosz Śnieg on 23.10.2021.
//

#include "Animation.hpp"
#include "../../Engine/base/engineBase.hpp"

Animation::Animation(sf::Shape *object, std::string filepath,std::string configfilename, uint8_t fps,bool rep) {

    this->dt = 1/((float) fps);
    std::ifstream configFile;
    configFile.open(filepath+"/"+configfilename,std::ios::in);
    std::string buffor;
    while (std::getline(configFile,buffor))
    {
        std::cout<<buffor<<std::endl;
        sf::Texture c;
        c.loadFromFile(filepath+"/"+buffor);
        this->files.push_back(c);
    }
    configFile.close();

    this->object = object;
    this->rep = rep;
    this->fps = fps;

}

void Animation::update() {
    this->dtL += engine::base::engineBase::deltaTime.asSeconds();
    if(this->dtL > this->dt)
    {
        i++;
        if(rep)
            i%=this->files.size();
        else
            if(i>=this->files.size())
                i = this->files.size()-1;
        this->object->setTexture(&this->files[i]);
        this->dtL = 0;
    }

}

void Animation::update(float s) {

    this->dtL += engine::base::engineBase::deltaTime.asSeconds();
    if(this->dtL > 1.f/((float)this->fps*s))
    {
        i++;
        if(rep)
            i%=this->files.size();
        else
        if(i>=this->files.size())
            i = this->files.size()-1;
        this->object->setTexture(&this->files[i]);
        this->dtL = 0;
    }
}
