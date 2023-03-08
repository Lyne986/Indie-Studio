/*
** EPITECH PROJECT, 2021
** project
** File description:
** NewGame.hpp
*/

#ifndef __NEWGAME_BUTTON_HPP__
    #define __NEWGAME_BUTTON_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::NewGame : public ECS::Components::AButton {
    public:
        NewGame(Vector2 pos);
        ~NewGame();
        void update();
    private:
        float scale;
};

#endif