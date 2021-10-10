//
// Created by Bartosz Śnieg on 20.07.2021.
//

#include "OutOfRangeException.hpp"

engine::exception::OutOfRangeException::OutOfRangeException(std::string msg) {
    this->msg = msg;
}

std::string engine::exception::OutOfRangeException::getMsg() {
    return this->msg;
}
