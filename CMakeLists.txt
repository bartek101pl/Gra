cmake_minimum_required(VERSION 3.17)
project(Gra)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "F:/lib/SFML/lib/cmake/SFML")
include_directories(headers F:/lib/SFML/include)
find_package(SFML 2.5 COMPONENTS system window graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
add_executable(Gra main.cpp Engine/event/EventController.cpp Engine/event/EventController.hpp Engine/event/staticEvent.h Engine/view/scene.cpp Engine/view/scene.hpp Engine/event/EventObject.cpp Engine/event/EventObject.hpp Engine/base/engineBase.cpp Engine/base/engineBase.hpp Engine/base/settings.hpp  Engine/object/GameObject.cpp Engine/object/GameObject.cpp Engine/physics/GamePhysics.cpp Engine/physics/GamePhysics.h Engine/physics/PhysicsObject.cpp Engine/physics/PhysicsObject.h Engine/base/SceneController/SceneController.cpp Engine/base/SceneController/SceneController.hpp Engine/exception/OutOfRangeException.cpp Engine/exception/OutOfRangeException.hpp Engine/exception/ItemExistException.cpp Engine/exception/ItemExistException.hpp Engine/exception/EngineException.cpp Engine/exception/EngineException.hpp Engine/event/AbstractUserEventObject.cpp Engine/event/AbstractUserEventObject.hpp Engine/object/AbstractGameObject.cpp Engine/object/AbstractGameObject.hpp Engine/exception/NullObjectException.cpp Engine/exception/NullObjectException.hpp Game_old/MainScene.cpp Game_old/MainScene.hpp Game_old/Objects/Player.cpp Game_old/Objects/Player.hpp Game_old/Objects/Wall.cpp Game_old/Objects/Wall.hpp Engine/Animation/Animation.cpp Engine/Animation/Animation.hpp)
#add_library(Gra SHARED Engine/event/EventController.cpp Engine/event/EventController.hpp Engine/event/staticEvent.h Engine/view/scene.cpp Engine/view/scene.hpp Engine/event/EventObject.cpp Engine/event/EventObject.hpp Engine/base/engineBase.cpp Engine/base/engineBase.hpp Engine/base/settings.hpp  Engine/object/GameObject.cpp Engine/object/GameObject.cpp)
target_link_libraries(Gra sfml-system sfml-window sfml-graphics)