/*
** EPITECH PROJECT, 2021
** project
** File description:
** Setting.hpp
*/

#ifndef __SETTING_BUTTON_HPP__
    #define __SETTING_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Setting : public ECS::Components::AButton {
    public:
        Setting();
        ~Setting();
        void update();
    private:
        bool is_move;
        float scale;
};

#endif