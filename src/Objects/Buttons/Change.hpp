/*
** EPITECH PROJECT, 2021
** project
** File description:
** Change.hpp
*/

#ifndef __CHANGE_BUTTON_HPP__
    #define __CHANGE_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Change : public ECS::Components::AButton {
    public:
        Change(Vector2 pos, std::string assets, std::string text = "", Vector2 text_pos = {0, 0});
        ~Change();
        void update();
    private:
        float scale;

};

#endif