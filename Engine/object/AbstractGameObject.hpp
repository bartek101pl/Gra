//
// Created by Bartosz Śnieg on 10.08.2021.
//

#ifndef GRA_ABSTRACTGAMEOBJECT_HPP
#define GRA_ABSTRACTGAMEOBJECT_HPP

#include "../event/EventObject.hpp"
#include "../event/AbstractUserEventObject.hpp"
#include "../exception/OutOfRangeException.hpp"
#include "../exception/NullObjectException.hpp"
#include "string"
#include "SFML/Graphics.hpp"
namespace engine::object {
    class AbstractGameObject: public event::EventObject, public event::AbstractUserEventObject{
    public:
        ~AbstractGameObject();
        //function to implement event system
        void MouseKeyPressEvent(engine::event::MouseEvent e, sf::Vector2i pos) final;
        void MouseKeyReleaseEvent(engine::event::MouseEvent e, sf::Vector2i pos) final;
        void KeyboardKeyPressEvent(std::vector<event::Key> * keyList) final;
        void KeyboardKeyReleaseEvent(std::vector<event::Key> * keyList) final;
        void initEvet();
        void destroyed();
        void updateEvent();
        virtual void addChildren(AbstractGameObject *obj) final;
        virtual void deleteChildren(int id) final;
        virtual int getId(AbstractGameObject *obj) final;
        virtual AbstractGameObject* getChildren(int id) final;
    protected:
        void setParent(AbstractGameObject * parent);
        std::vector<AbstractGameObject*> *children = nullptr;
        AbstractGameObject *parent = nullptr;
    };
}

#endif //GRA_ABSTRACTGAMEOBJECT_HPP
