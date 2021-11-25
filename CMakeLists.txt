cmake_minimum_required(VERSION 3.17)
project(Gra)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML/lib/cmake/SFML")
include_directories(headers D:/SFML/include)
find_package(SFML 2.5 COMPONENTS system window graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
add_executable(Gra main.cpp Engine/event/EventController.cpp Engine/event/EventController.hpp Engine/event/staticEvent.h Engine/view/scene.cpp Engine/view/scene.hpp Engine/event/EventObject.cpp Engine/event/EventObject.hpp Engine/base/engineBase.cpp Engine/base/engineBase.hpp Engine/base/settings.hpp  Engine/object/GameObject.cpp Engine/object/GameObject.cpp Engine/physics/GamePhysics.cpp Engine/physics/GamePhysics.h Engine/physics/PhysicsObject.cpp Engine/physics/PhysicsObject.h Engine/base/SceneController/SceneController.cpp Engine/base/SceneController/SceneController.hpp Engine/exception/OutOfRangeException.cpp Engine/exception/OutOfRangeException.hpp Engine/exception/ItemExistException.cpp Engine/exception/ItemExistException.hpp Engine/exception/EngineException.cpp Engine/exception/EngineException.hpp Engine/event/AbstractUserEventObject.cpp Engine/event/AbstractUserEventObject.hpp Engine/object/AbstractGameObject.cpp Engine/object/AbstractGameObject.hpp Engine/exception/NullObjectException.cpp Engine/exception/NullObjectException.hpp Engine/Animation/Animation.cpp Engine/Animation/Animation.hpp Game/scenes/menu.cpp Game/scenes/menu.h Game/scenes/levelGame.cpp Game/scenes/levelGame.h Game/objects/menu/bg.cpp Game/objects/menu/bg.h Engine/object/button.cpp Engine/object/button.h Game/objects/menu/button1.cpp Game/objects/menu/button1.h Game/objects/levelGame/player.cpp Game/objects/levelGame/player.h Game/objects/levelGame/Wall.cpp Game/objects/levelGame/Wall.h Game/objects/levelGame/ObjectD.cpp Game/objects/levelGame/ObjectD.h Game/objects/levelGame/pointArea.cpp Game/objects/levelGame/pointArea.h)
#add_library(Gra SHARED Engine/event/EventController.cpp Engine/event/EventController.hpp Engine/event/staticEvent.h Engine/view/scene.cpp Engine/view/scene.hpp Engine/event/EventObject.cpp Engine/event/EventObject.hpp Engine/base/engineBase.cpp Engine/base/engineBase.hpp Engine/base/settings.hpp  Engine/object/GameObject.cpp Engine/object/GameObject.cpp)
target_link_libraries(Gra sfml-system sfml-window sfml-graphics)