/*
** EPITECH PROJECT, 2021
** project
** File description:
** Quit.cpp
*/

#include "Quit.hpp"

namespace  Indie::Objects::Button {
    Quit::Quit(float x, float y)
    : AButton("Quit", {x, y}, {100, 18}, {830, 84}, 30, WHITE, "assets/buttons/template.png", {0, 0, 830, 84}, 0.8, "assets/buttons/quit.png", {14, 10}, {0, 0, 72, 72}, 0.6)
    {
        this->is_move = false;
        this->scale = 0.8;
        this->setSfx("assets/audio/menu/back.wav");
    }

    Quit::~Quit()
    {}

    void Quit::update()
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
