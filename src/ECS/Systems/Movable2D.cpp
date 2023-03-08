/*
** EPITECH PROJECT, 2021
** project
** File description:
** Movable2D.cpp
*/

#include "Movable2D.hpp"

namespace Indie::ECS::Systems {
    Movable2D::Movable2D(std::shared_ptr<Vector2> pos)
    {
        this->movPos = pos;
    }

    void Movable2D::moveX(float x)
    {
        this->movPos->x += x;
    }

    void Movable2D::moveY(float y)
    {
        this->movPos->y += y;
    }

    void Movable2D::move(Vector2 dir)
    {
        this->movPos->x += dir.x;
        this->movPos->y += dir.y;
    }
}