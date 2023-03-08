/*
** EPITECH PROJECT, 2021
** project
** File description:
** Online.cpp
*/

#include "Online.hpp"

namespace  Indie::Objects::Button {
    Online::Online()
    : AButton("Multiplayer", {616, 380}, {100, 18}, {830, 84}, 30, WHITE, "assets/buttons/template.png", {0, 0, 830, 84}, 0.8, "assets/buttons/online.png", {10, 12}, {0, 0, 76, 76}, 0.6)
    {
        this->is_move = false;
        this->scale = 0.8;
        this->setSfx("assets/audio/menu/next.wav");
    }

    Online::~Online()
    {}

    void Online::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({830 * scale, 0, 860 * scale, 84 * scale});
            if (!this->is_move)
                this->moveX(-30 * scale);
            this->is_move = true;
        } else {
            this->setRect({0, 0, 830 * scale, 84 * scale});
            if (this->is_move)
                this->moveX(30 * scale);
            this->is_move = false;
        }
    }
}