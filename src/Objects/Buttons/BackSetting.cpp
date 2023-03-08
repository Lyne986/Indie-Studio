/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** BackSetting
*/

#include "BackSetting.hpp"

namespace  Indie::Objects::Button {
    BackSetting::BackSetting()
    : AButton("Back to menu", {616, 750}, {100, 18}, {830, 84}, 30, WHITE, "assets/buttons/template.png", {0, 0, 830, 84}, 0.8, "assets/buttons/local.png", {12, 10}, {0, 0, 72, 72}, 0.6)
    {
        this->is_move = false;
        this->scale = 0.8;
        this->setSfx("assets/audio/menu/back.wav");
    }

    BackSetting::~BackSetting()
    {}

    void BackSetting::update()
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
