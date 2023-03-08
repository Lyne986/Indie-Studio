/*
** EPITECH PROJECT, 2021
** project
** File description:
** Local.hpp
*/

#ifndef __LOCAL_BUTTON_HPP__
    #define __LOCAL_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Local : public ECS::Components::AButton {
    public:
        Local();
        ~Local();
        void update();
    private:
        bool is_move;
        float scale;
};

#endif