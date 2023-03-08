/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MainCamera.cpp
*/

#include "MainCamera.hpp"

namespace Indie::Objects {
    MainCamera::MainCamera() :
    Object3D({0.0f, 30.0f, 10.0f}, 1, {0, 1, 0})
    {
        Vector3 target = {0, 0, 0};
        this->camera = Lib::MyCamera::getInstance();
        this->camera->setCamera(*this->pos, target, *this->rot, 45.0f, CAMERA_PERSPECTIVE);
    }

    MainCamera::~MainCamera() {}

    void MainCamera::init() {}

    void MainCamera::update() {}

    void MainCamera::begin3DMode()
    {
        this->camera->begin3DMode();
    }

    void MainCamera::end3DMode()
    {
        this->camera->end3DMode();
    }
}
