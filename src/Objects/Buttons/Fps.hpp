/*
** EPITECH PROJECT, 2021
** project
** File description:
** fps.hpp
*/

#ifndef __FPS_BUTTON_HPP__
    #define __FPS_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Fps : public ECS::Components::AButton {
    public:
        Fps();
        ~Fps();
        void update();
        bool buttonState();
    private:
        bool is_move;
        float scale;
};

#endif