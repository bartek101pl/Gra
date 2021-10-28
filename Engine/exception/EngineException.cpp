//
// Created by Bartosz Śnieg on 20.07.2021.
//

#include "EngineException.hpp"

engine::exception::EngineException::EngineException(std::string msg) {
this->msg = msg;
}

std::string engine::exception::EngineException::getMsg() {
    return this->msg;
}

engine::exception::EngineException::EngineException() {}
