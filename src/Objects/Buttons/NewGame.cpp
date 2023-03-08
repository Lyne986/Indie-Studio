/*
** EPITECH PROJECT, 2021
** project
** File description:
** NewGame.cpp
*/

#include "NewGame.hpp"

namespace  Indie::Objects::Button {
    NewGame::NewGame(Vector2 pos)
    : AButton("Start a new game", pos, {80, 18}, {340, 60}, 40, WHITE, "assets/buttons/new_game.png", {0, 0, 340, 60}, 1.5)
    {
        this->scale = 1.5;
    }

    NewGame::~NewGame()
    {}

    void NewGame::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({340 * scale, 0, 340 * scale, 60 * scale});
            this->setTextColor(BLACK);
        } else {
            this->setRect({0, 0, 340 * scale, 60 * scale});
            this->setTextColor(WHITE);
        }
    }
}