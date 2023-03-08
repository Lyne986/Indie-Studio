/*
** EPITECH PROJECT, 2021
** project
** File description:
** Movable3D.cpp
*/

#include "Movable3D.hpp"

namespace Indie::ECS::Systems {

    Movable3D::Movable3D(std::shared_ptr<Vector3> pos)
    {
        this->movPos = pos;
    }

    void Movable3D::move(Vector3 direction)
    {
        this->movPos->x += direction.x;
        this->movPos->y += direction.y;
        this->movPos->z += direction.z;
    }
}