/*
** EPITECH PROJECT, 2021
** project
** File description:
** Setting.cpp
*/

#include "Setting.hpp"

namespace  Indie::Objects::Button {
    Setting::Setting()
    : AButton("Setting", {616, 450}, {100, 18}, {830, 84}, 30, WHITE, "assets/buttons/template.png", {0, 0, 830, 84}, 0.8, "assets/buttons/setting.png", {9, 13}, {0, 0, 82, 60}, 0.65)
    {
        this->is_move = false;
        this->scale = 0.8;
        this->setSfx("assets/audio/menu/next.wav");
    }

    Setting::~Setting()
    {}

    void Setting::update()
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