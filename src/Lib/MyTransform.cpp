/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyTransform.cpp
*/

#include "MyTransform.hpp"

namespace Indie::Lib {
    MyTransform::MyTransform() {}

    MyTransform::~MyTransform() {}

    void MyTransform::rotate(float angle, float x, float y, float z) const
    {
        if (angle != 0) {
            rlRotatef(angle, x, y, z);
        }
    }

    void MyTransform::translate(Vector3 currentPos, Vector3 targetPos) const
    {
        rlTranslatef(currentPos.x - targetPos.x, currentPos.y - targetPos.y, currentPos.z - targetPos.z);
    }

    void MyTransform::pushMatrix() const
    {
        rlPushMatrix();
    }

    void MyTransform::popMatrix() const
    {
        rlPopMatrix();
    }
}