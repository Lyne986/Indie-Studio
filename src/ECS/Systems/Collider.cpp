/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Collider.cpp
*/

#include "Collider.hpp"


namespace Indie::ECS::Systems {
    Collider::Collider(float x, float y, int width, int height, std::string tag)
    {
        this->collider = std::make_shared<Lib::Shapes::MyRectangle>(x, y, width, height);
        this->isActive = true;
        this->isBomb = false;
        this->tag = tag;
    }

    bool Collider::getIsActive() const
    {
        return this->isActive;
    }

    void Collider::setIsActive(bool value)
    {
        this->isActive = value;
    }

    Lib::Shapes::MyRectangle Collider::getCollider() const
    {
        return *this->collider;
    }

    std::string Collider::getTag() const
    {
        return this->tag;
    }
    
    bool Collider::getIsBomb() const
    {
        return this->isBomb;
    }

    void Collider::setIsBomb(bool value)
    {
        this->isBomb = value;
    }

    Rectangle Collider::getRect() const {
        return (this->collider->getRectangle());
    }

}
