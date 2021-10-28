//
// Created by Bartosz Śnieg on 20.07.2021.
//

#ifndef GRA_ITEMEXISTEXCEPTION_HPP
#define GRA_ITEMEXISTEXCEPTION_HPP

#include "EngineException.hpp"

namespace engine::exception {
    class ItemExistException: public engine::exception::EngineException{
    public:
        ItemExistException(std::string msg);
    };
}

#endif //GRA_ITEMEXISTEXCEPTION_HPP
