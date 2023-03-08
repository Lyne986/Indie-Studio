/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Title
*/

#include "Title.hpp"

namespace  Indie::Objects::Button {
    Title::Title(std::string content)
    : AButton("Setting", {500, 50}, {0, 0}, {10, 10}, 70, BLACK)
    {
        this->is_move = false;
        this->scale = 0.8;
    }

    Title::~Title()
    {}

    void Title::update()
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
