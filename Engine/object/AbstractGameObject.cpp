//
// Created by Bartosz Śnieg on 10.08.2021.
//

#include "AbstractGameObject.hpp"
#include "../base/SceneController/SceneController.hpp"

void engine::object::AbstractGameObject::KeyboardKeyPressEvent(std::vector<event::Key> *keyList) {
    this->onKeyPressEvent(keyList);
    if(this->children!= nullptr && !this->freeze)
        for (auto &i: *this->children) {
            if(i->getVisibility())
                i->KeyboardKeyPressEvent(keyList);
        }
}

void engine::object::AbstractGameObject::KeyboardKeyReleaseEvent(std::vector<event::Key> *keyList) {
    this->onKeyReleaseEvent(keyList);
    if(this->children!= nullptr && !this->freeze)
        for (auto &i: *this->children) {
            if(i->getVisibility())
                i->KeyboardKeyReleaseEvent(keyList);
        }
}

void engine::object::AbstractGameObject::MouseKeyReleaseEvent(engine::event::MouseEvent e, sf::Vector2i pos) {
    this->onMouseReleaseEvent(e,pos);
    if(this->children!= nullptr && !this->freeze)
        for (auto &i: *this->children) {
            if(i->getVisibility())
                i->MouseKeyReleaseEvent(e,pos);
        }
}

void engine::object::AbstractGameObject::MouseKeyPressEvent(engine::event::MouseEvent e, sf::Vector2i pos) {
    this->onMousePressEvent(e,pos);
    if(this->children!= nullptr && !this->freeze)
        for (auto &i: *this->children) {
            if(i->getVisibility())
                i->MouseKeyPressEvent(e,pos);
        }
}

void engine::object::AbstractGameObject::destroyed() {
    this->onDestroyed();
    if(this->children!= nullptr)
        for(auto a : *this->children)
        {
            a->destroyed();
            delete a;
        }

//    this->children->clear();
    delete this->children;
    this->children = nullptr;
}

void engine::object::AbstractGameObject::updateEvent() {
    int a =  engine::base::SceneController::getInstance()->getId();
    this->onUpdate();
    if(this->children!= nullptr && !this->freeze)
        for (auto& i: *this->children) {
            if(a == engine::base::SceneController::getInstance()->getId()&& i->getVisibility())
            i->updateEvent();
        }
}

void engine::object::AbstractGameObject::initEvet() {
    this->onInit();
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->initEvet();
        }
}

void engine::object::AbstractGameObject::addChildren(engine::object::AbstractGameObject *obj) {
        if(this->children == nullptr)
            this->children = new std::vector<engine::object::AbstractGameObject*>();
        obj->setParent(this);
        this->children->push_back(obj);
        obj->onInit();

}

void engine::object::AbstractGameObject::deleteChildren(int id) {

    if(id>=0&& id<this->children->size())
    {
        this->children->erase(this->children->begin()+id);
    }else
    {
        throw engine::exception::OutOfRangeException("Index is out of range!!!!");
    }

}

engine::object::AbstractGameObject::~AbstractGameObject() {
    delete this->children;

}

int engine::object::AbstractGameObject::getId(AbstractGameObject *obj) {
    int a = -1;
    for (int i = 0; i < this->children->size(); ++i) {
        if(this->children->at(i) == obj)
        {
            a = i;
            break;
        }
    }
    return a;
}

void engine::object::AbstractGameObject::setParent(engine::object::AbstractGameObject *parent) {
this->parent = parent;
}

engine::object::AbstractGameObject *engine::object::AbstractGameObject::getChildren(int id) {
    return (this->children->at(id));
}

bool engine::object::AbstractGameObject::getVisibility() {
    return this->visibility;
}

void engine::object::AbstractGameObject::freezeScene() {
this->freeze = true;
}

void engine::object::AbstractGameObject::setAllVisibility() {
    for (auto &i: *this->children) {
        i->visibility = !i->visibility;
    }
}





