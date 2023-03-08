/*
** EPITECH PROJECT, 2021
** project
** File description:
** GameButton.cpp
*/

#include "GameButton.hpp"

#include <iostream>
namespace Indie::Objects::Button {
    GameButton::GameButton()
    : AButton("GameButton", {0, 0}, {100, 100}, {100, 100}, 42, BLACK, "assets/green.png")
    {}

    GameButton::~GameButton()
    {}

    void GameButton::update() {
        this->AButton::update();
    }
}