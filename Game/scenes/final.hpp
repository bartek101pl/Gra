//
// Created by Bartosz Śnieg on 01.01.2022.
//

#ifndef GRA_FINAL_HPP
#define GRA_FINAL_HPP
#include "../../Engine/view/scene.hpp"
#include "../../Engine/object/Lable.hpp"
class final: public engine::view::scene{
public:
    final(std::string name);

    void onInit() override;
    void setData(int p, float t);

private:
    Lable* points;
    Lable* time;
    std::string sPoints;
    std::string sTime;

};


#endif //GRA_FINAL_HPP
