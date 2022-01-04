//
// Created by Bartosz Śnieg on 20.07.2021.
//

#include "SceneController.hpp"

engine::base::SceneController* engine::base::SceneController::_singleton;

engine::view::scene *engine::base::SceneController::getScene(int id) {
    if(id >=0 && id<this->sceneList.size())
        return this->sceneList[id];
    else
        throw engine::exception::OutOfRangeException("ID is out of range");
}

engine::view::scene *engine::base::SceneController::getScene(std::string name) {
    int id = this->getID(name);
    if(id>-1)
        return this->getScene(id);
    else
        return nullptr;
}

int engine::base::SceneController::getID(std::string name) {
    int r = -1;
    for(int i =0;i<this->sceneList.size();i++)
    {
        if(this->sceneList[i]->getName() == name)
        {
            r = i;
            break;
        }
    }
    return r;
}

void engine::base::SceneController::addScene(engine::view::scene *scene) {

    if(!this->isRegister(scene->getName()))
    {
        this->sceneList.push_back(scene);
    }else
    {
        throw engine::exception::ItemExistException("Scene with name: "+scene->getName()+" exist");
    }

}

bool engine::base::SceneController::isRegister(std::string name) {
    if(this->getID(name) == -1)
        return false;
    else
        return true;
}

void engine::base::SceneController::setCurrentScene(int id) {
    if(this->sceneList.size()>id && id>=0) {
        this->newScene = id;
        this->isChange = false;
    }
    else
        throw engine::exception::OutOfRangeException("Id out of scene list size!");

}

void engine::base::SceneController::setCurrentScene(std::string name) {
    int id = this->getID(name);
    if(id>-1)
        this->currentScene = id;
    else
        throw engine::exception::OutOfRangeException("Scene with name: "+name+" not exist!");
}

engine::view::scene *engine::base::SceneController::getCurrentScene() {
    return this->getScene(this->currentScene);
}


engine::base::SceneController *engine::base::SceneController::getInstance() {
    if(_singleton == nullptr)
        _singleton = new SceneController();
    return _singleton;
}

int engine::base::SceneController::getId() {
    return this->currentScene;
}

bool engine::base::SceneController::update() {
    if(!this->isChange) {
        this->sceneList.at(this->currentScene)->destroyed();
        this->currentScene = this->newScene;
        this->isChange = true;
        this->sceneList.at(this->currentScene)->initEvet();
    }
    return this->end;
}

void engine::base::SceneController::End() {
this->end = true;
}
