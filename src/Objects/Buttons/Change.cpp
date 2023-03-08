/*
** EPITECH PROJECT, 2021
** project
** File description:
** Change.cpp
*/

#include "Change.hpp"

namespace Indie::Objects::Button {
    Change::Change(Vector2 pos, std::string assets, std::string text, Vector2 text_pos)
    : AButton(text, pos, text_pos, {75, 132}, 20, WHITE, assets, {0, 0, 75, 132}, 0.3)
    {
        this->scale = 0.3;
        this->setSfx("assets/audio/menu/change.wav");
    }

    Change::~Change()
    {}

    void Change::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({75 * scale, 0, 75 * scale, 132 * scale});
        } else {
            this->setRect({0, 0, 75 * scale, 137 * scale});
        }
    }
}