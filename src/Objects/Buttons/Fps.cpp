/*
** EPITECH PROJECT, 2021
** project
** File description:
** Fps.cpp
*/

#include "Fps.hpp"

namespace  Indie::Objects::Button {
    Fps::Fps()
    : AButton("Show fps",  {250, 500}, {30, 30}, {10, 10}, 30, BLACK, "assets/setting/fpsButton.png", {0, 0, 328, 84} , 1, "assets/setting/toggle.png", {200, 15}, {786, 0, 393, 295}, 0.2)
    {
        this->is_move = false;
        this->scale = 1;
        this->setSfx("assets/audio/menu/remove.wav");
    }

    Fps::~Fps()
    {}

    bool Fps::buttonState()
    {
        return (this->is_move);
    }

    void Fps::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({330 * scale, 0, 330 * scale, 84 * scale});
            if (this->isClick() && this->is_move == false) {
                this->setLogoRect({ 0, 0, 393, 295 });
                this->is_move = true;
            } else if (this->isClick() && this->is_move == true) {
                this->setLogoRect({786, 0, 393, 295});
                this->is_move = false;
            }
        } else {
            this->setRect({0, 0, 330 * scale, 84 * scale});
        }
    }
}