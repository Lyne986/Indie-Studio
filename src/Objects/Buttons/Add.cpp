/*
** EPITECH PROJECT, 2021
** project
** File description:
** Add.cpp
*/

#include "Add.hpp"

namespace  Indie::Objects::Button {
    Add::Add(std::string text, Vector2 pos, Vector2 text_pos)
    : AButton(text, pos, text_pos, {36, 36}, 20, WHITE, "assets/buttons/add.png", {0, 0, 36, 36}, 1)
    {
        this->scale = 1;
        this->setSfx("assets/audio/menu/add.wav");
    }

    Add::~Add()
    {}

    void Add::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({36 * scale, 0, 36 * scale, 36 * scale});
            this->setTextColor(BLACK);
        } else {
            this->setRect({0, 0, 36 * scale, 36 * scale});
            this->setTextColor(WHITE);
        }
    }
}