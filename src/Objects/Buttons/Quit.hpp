/*
** EPITECH PROJECT, 2021
** project
** File description:
** Quit.hpp
*/

#ifndef __QUIT_BUTTON_HPP__
    #define __QUIT_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Quit : public ECS::Components::AButton {
    public:
        Quit(float x, float y);
        ~Quit();
        void update();
    private:
        bool is_move;
        float scale;
};

#endif
