//
// Created by Bartosz Śnieg on 10.08.2021.
//

#ifndef GRA_NULLOBJECTEXCEPTION_HPP
#define GRA_NULLOBJECTEXCEPTION_HPP

#include "EngineException.hpp"

namespace engine::exception {
    class NullObjectException : public engine::exception::EngineException{
        public:
            NullObjectException(std::string msg);
    };
}


#endif //GRA_NULLOBJECTEXCEPTION_HPP
