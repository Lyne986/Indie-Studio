/*
** EPITECH PROJECT, 2021
** project
** File description:
** LoadGame.hpp
*/

#ifndef __LOADGAME_BUTTON_HPP__
    #define __LOADGAME_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::LoadGame : public ECS::Components::AButton {
    public:
        LoadGame(Vector2 pos, std::string txt);
        ~LoadGame();
        void update();
    private:
        float scale;
};

#endif