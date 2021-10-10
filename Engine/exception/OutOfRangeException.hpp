//
// Created by Bartosz Śnieg on 20.07.2021.
//

#ifndef GRA_OUTOFRANGEEXCEPTION_HPP
#define GRA_OUTOFRANGEEXCEPTION_HPP

#include "exception"
#include <string>
namespace engine::exception {
    class OutOfRangeException : public std::exception {
    public:
        OutOfRangeException(std::string msg);
        ~OutOfRangeException() = default;
        std::string getMsg();

    private:
        std::string msg;
    };
}

#endif //GRA_OUTOFRANGEEXCEPTION_HPP
