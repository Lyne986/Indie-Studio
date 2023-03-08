/*
** EPITECH PROJECT, 2021
** project
** File description:
** Delete.hpp
*/

#ifndef __DELETE_BUTTON_HPP__
    #define __DELETE_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Delete : public ECS::Components::AButton {
    public:
        Delete(Vector2 pos);
        ~Delete();
        void update();
    private:
        float scale;
};

#endif