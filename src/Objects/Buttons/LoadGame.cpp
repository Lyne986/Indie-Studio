/*
** EPITECH PROJECT, 2021
** project
** File description:
** LoadGame.cpp
*/

#include "LoadGame.hpp"

namespace  Indie::Objects::Button {
    LoadGame::LoadGame(Vector2 pos, std::string txt)
    : AButton(txt, pos, {65, 180}, {746, 480}, 40, WHITE, "assets/buttons/load_game.png", {0, 0, 746, 480}, 0.35)
    {
        this->scale = 0.35;
    }

    LoadGame::~LoadGame()
    {}

    void LoadGame::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({746 * scale, 0, 746 * scale, 480 * scale});
            this->setTextColor(BLACK);
        } else {
            this->setRect({0, 0, 746 * scale, 480 * scale});
            this->setTextColor(WHITE);
        }
    }
}