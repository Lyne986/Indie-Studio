/*
** EPITECH PROJECT, 2021
** project
** File description:
** GameButton.hpp
*/

#ifndef __GAME_BUTTON_HPP__
    #define __GAME_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::GameButton : public ECS::Components::AButton {
    public:
        GameButton();
        ~GameButton();
        void update();
};

#endif