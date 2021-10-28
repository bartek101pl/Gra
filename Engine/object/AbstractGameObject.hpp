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
namespace engine::object {
    class AbstractGameObject: public event::EventObject, public event::AbstractUserEventObject{
    public:
        ~AbstractGameObject();
        //function to implement event system
        void MouseKeyPressEvent(engine::event::MouseEvent e) final;
        void MouseKeyReleaseEvent(engine::event::MouseEvent e) final;
        void KeyboardKeyPressEvent(std::vector<event::Key> * keyList) final;
        void KeyboardKeyReleaseEvent(std::vector<event::Key> * keyList) final;
        void initEvet();
        void destroyed();
        void updateEvent();
        virtual void addChildren(AbstractGameObject *obj) final;
        virtual void deleteChildren(int id) final;
        virtual int getId(AbstractGameObject *obj) final;

    protected:
        std::vector<AbstractGameObject*> *children = nullptr;

    };
}

#endif //GRA_ABSTRACTGAMEOBJECT_HPP
