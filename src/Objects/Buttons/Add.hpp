/*
** EPITECH PROJECT, 2021
** project
** File description:
** Add.hpp
*/

#ifndef __ADD_BUTTON_HPP__
    #define __ADD_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Add : public ECS::Components::AButton {
    public:
        Add(std::string text, Vector2 pos, Vector2 text_pos);
        ~Add();
        void update();
    private:
        float scale;
};

#endif