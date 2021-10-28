#include "Engine/base/engineBase.hpp"


int main() {
    // simple implement

    engine::base::engineBase engine{};
    engine.init({false, true,800,600,60});
    engine.start(0);
    return 0;
}



