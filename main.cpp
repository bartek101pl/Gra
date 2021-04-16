#include "Engine/base/engineBase.hpp"

int main() {
engine::base::engineBase engine{};
engine.init({true, true,800,600,60});
engine.start();
    return 0;
}



