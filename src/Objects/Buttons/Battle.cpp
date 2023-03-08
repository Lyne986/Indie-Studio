/*
** EPITECH PROJECT, 2021
** project
** File description:
** Battle.cpp
*/

#include "Battle.hpp"

namespace  Indie::Objects::Button {
    Battle::Battle(Vector2 pos)
    : AButton("", pos, {0, 0}, {72, 72}, 20, WHITE, "assets/buttons/battle.png", {0, 0, 72, 72}, 1)
    {
        this->scale = 1;
        this->setSfx("assets/audio/menu/startGame.wav");
    }

    Battle::~Battle()
    {}

    void Battle::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({72 * scale, 0, 72 * scale, 72 * scale});
        } else {
            this->setRect({0, 0, 72 * scale, 72 * scale});
        }
    }
}