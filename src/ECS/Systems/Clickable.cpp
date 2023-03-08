/*
** EPITECH PROJECT, 2021
** project
** File description:
** Clickeable.cpp
*/

#include "Clickable.hpp"

namespace Indie::ECS::Systems {
    Clickable::Clickable(std::shared_ptr<Vector2> pos, std::shared_ptr<Vector2> size)
    {
        this->clickPos = pos;
        this->clickDim = size;
    }

    bool Clickable::isClick()
    {
        Vector2 mPos = event.getMousePosition();

        if (event.isMouseButton(Lib::MyEvent::MyEvent::PRESSED, 0)) {
            if (this->isOver()) {
                return true;
            }
        }
        return (false);
    }

    bool Clickable::isOver()
    {
        Vector2 mPos = event.getMousePosition();

        if (mPos.x >= this->clickPos->x && mPos.x <= this->clickPos->x + this->clickDim->x) {
            if (mPos.y >= this->clickPos->y && mPos.y <= this->clickPos->y + this->clickDim->y) {
                return (true);
            }
        }
        return (false);
    }
};