/*
** EPITECH PROJECT, 2021
** project
** File description:
** Battle.hpp
*/

#ifndef __BATTLE_BUTTON_HPP__
    #define __BATTLE_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Battle : public ECS::Components::AButton {
    public:
        Battle(Vector2 pos);
        ~Battle();
        void update();
    private:
        float scale;
};

#endif