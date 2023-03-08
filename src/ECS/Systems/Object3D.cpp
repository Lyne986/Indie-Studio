/*
** EPITECH PROJECT, 2021
** project
** File description:
** Object3D.cpp
*/

#include "Object3D.hpp"

namespace Indie::ECS::Systems {
    Object3D::Object3D(Vector3 pos, float scale, Vector3 rotation)
    {
        this->pos = std::make_shared<Vector3>(pos);
        this->scale = std::make_shared<float>(scale);
        this->rot = std::make_shared<Vector3>(rotation);
    }

    float Object3D::getClampedValue(float value) const
    {
        if (value < 0) {
            return (-1);
        }
        if (value > 0) {
            return (1);
        }
        return (0);
    }

    void Object3D::AdjustRotation() const
    {
        this->transform.translate(*this->pos, {0, 0, 0});
        this->transform.rotate(abs(this->rot->x), this->getClampedValue(this->rot->x), 0, 0);
        this->transform.rotate(abs(this->rot->y), 0, this->getClampedValue(this->rot->y), 0);
        this->transform.rotate(abs(this->rot->z), 0, 0, this->getClampedValue(this->rot->z));
        this->transform.translate({0, 0, 0}, *this->pos);
    }

    Vector3 Object3D::getPosition() const
    {
        return *this->pos;
    }

    void Object3D::setPosition(Vector3 pos)
    {
        *this->pos = pos;
    }
}