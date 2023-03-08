/*
** EPITECH PROJECT, 2021
** project
** File description:
** Online.hpp
*/

#ifndef __ONLINE_BUTTON_HPP__
    #define __ONLINE_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Online : public ECS::Components::AButton {
    public:
        Online();
        ~Online();
        void update();
    private:
        bool is_move;
        float scale;
};

#endif