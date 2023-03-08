/*
** EPITECH PROJECT, 2021
** project
** File description:
** Object2D.cpp
*/

#include "Object2D.hpp"

#include <iostream>
namespace Indie::ECS::Systems {
    Object2D::Object2D(Vector2 pos, Vector2 dim)
    {
        this->pos = std::make_shared<Vector2>(pos);
        this->dim = std::make_shared<Vector2>(dim);
    }
}