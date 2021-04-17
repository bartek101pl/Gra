cmake_minimum_required(VERSION 3.17)
project(Gra)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR "F:/lib/SFML/lib/cmake/SFML")
#include_directories(headers F:/lib/SFML/include)
find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(Gra main.cpp Engine/event/EventController.cpp Engine/event/EventController.hpp Engine/event/staticEvent.h Engine/view/scene.cpp Engine/view/scene.hpp Engine/event/EventObject.cpp Engine/event/EventObject.hpp Engine/base/engineBase.cpp Engine/base/engineBase.hpp Engine/base/settings.hpp)
target_link_libraries(Gra sfml-system sfml-window sfml-graphics)