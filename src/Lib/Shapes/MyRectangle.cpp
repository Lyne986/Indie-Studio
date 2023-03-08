/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyRectangle.cpp
*/

#include "MyRectangle.hpp"

namespace Indie::Lib::Shapes {
    MyRectangle::MyRectangle(float x, float y, float width, float height)
    {
        this->updateRec(x, y, width, height);
    }

    void MyRectangle::updateRec(float x, float y, float width, float height)
    {
        this->rectangle = {x, y, width, height};
    }

    bool MyRectangle::checkCollisionRecs(Rectangle rec) const
    {
        return (CheckCollisionRecs(this->rectangle, rec));
    }

    Rectangle MyRectangle::getRectangle() const
    {
        return (this->rectangle);
    }
};