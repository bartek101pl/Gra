//
// Created by Bartosz Śnieg on 10.08.2021.
//

#include "NullObjectException.hpp"

engine::exception::NullObjectException::NullObjectException(std::string msg) : EngineException(msg) {

}
