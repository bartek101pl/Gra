//
// Created by Bartosz Śnieg on 20.07.2021.
//

#ifndef GRA_ENGINEEXCEPTION_HPP
#define GRA_ENGINEEXCEPTION_HPP

#include <string>
namespace engine::exception {
    class EngineException {
    public:
         EngineException(std::string msg);

        EngineException();

        ~EngineException() = default;
        std::string getMsg();

    protected:
        std::string msg;
    };
}

#endif //GRA_ENGINEEXCEPTION_HPP
