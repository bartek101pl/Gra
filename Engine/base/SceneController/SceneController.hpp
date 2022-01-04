//
// Created by Bartosz Śnieg on 20.07.2021.
//

#ifndef GRA_SCENECONTROLLER_HPP
#define GRA_SCENECONTROLLER_HPP

#include <vector>
#include "../../view/scene.hpp"
#include "../../exception/OutOfRangeException.hpp"
#include "../../exception//ItemExistException.hpp"

#include <string>

namespace engine::base {

    class SceneController {

    private:
        std::vector<engine::view::scene*> sceneList;
        bool isRegister(std::string name);
        int getID(std::string name);
        int currentScene = 0;
        static SceneController* _singleton;
        bool isChange = true;
        int newScene;
        bool end = false;
    public:
        void addScene(engine::view::scene *scene);
        engine::view::scene* getScene(int id);
        engine::view::scene* getScene(std::string name);
        void setCurrentScene(int id);
        void setCurrentScene(std::string name);
        engine::view::scene* getCurrentScene();
        static SceneController* getInstance();
        int getId();
        bool update();
        void End();
    };
}

#endif //GRA_SCENECONTROLLER_HPP
