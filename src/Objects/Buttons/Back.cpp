/*
** EPITECH PROJECT, 2021
** project
** File description:
** Back.cpp
*/

#include "Back.hpp"

namespace  Indie::Objects::Button {
    Back::Back(Vector2 pos, Indie::Scenes::Scenes scene)
    : AButton("", pos, {0, 0}, {80, 65}, 20, WHITE, "assets/buttons/back.png", {0, 0, 80, 65}, 1)
    {
        this->scale = 1;
        this->changingScene = scene;
        this->setSfx("assets/audio/menu/back.wav");
    }

    Back::~Back()
    {}

    void Back::update()
    {
        this->AButton::update();
        if (this->isOver()) {
            this->setRect({80 * scale, 0, 80 * scale, 65 * scale});
        } else {
            this->setRect({0, 0, 80 * scale, 65 * scale});
        }
    }

    Indie::Scenes::Scenes Back::getScene() const
    {
        return this->changingScene;
    }

    void Back::setScene(Indie::Scenes::Scenes scene)
    {
        this->changingScene = scene;
    }
}
