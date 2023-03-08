/*
** EPITECH PROJECT, 2021
** project
** File description:
** Delete.cpp
*/

#include "Delete.hpp"

namespace  Indie::Objects::Button {
    Delete::Delete(Vector2 pos)
    : AButton("", pos, {0, 0}, {36, 36}, 20, WHITE, "assets/buttons/delete.png", {0, 0, 36, 36}, 1)
    {
        this->scale = 1;
        this->setSfx("assets/audio/menu/remove.wav");
    }

    Delete::~Delete()
    {}

    void Delete::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({36 * scale, 0, 36 * scale, 36 * scale});
        } else {
            this->setRect({0, 0, 36 * scale, 36 * scale});
        }
    }
}