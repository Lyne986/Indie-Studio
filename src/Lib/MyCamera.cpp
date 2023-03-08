/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyCamera.cpp
*/


#include "MyCamera.hpp"

namespace Indie::Lib {
    std::shared_ptr<MyCamera> MyCamera::instance = nullptr;

    MyCamera::MyCamera() {}

    void MyCamera::setCamera(Vector3 position, Vector3 target, Vector3 rotation, float fovy, int projection)
    {
        this->camera.position = position;
        this->camera.target = target;
        this->camera.up = rotation;
        this->camera.fovy = fovy;
        this->camera.projection = projection;
    }

    void MyCamera::update()
    {
        UpdateCamera(&this->camera);
    }

    void MyCamera::begin3DMode() const
    {
        BeginMode3D(this->camera);
    }

    void MyCamera::end3DMode() const
    {
        EndMode3D();
    }

    Vector3 MyCamera::getTarget() const
    {
        return (this->camera.target);
    }

    void MyCamera::setTarget(Vector3 target)
    {
        this->camera.target = target;
    }

    Vector3 MyCamera::getPosition() const
    {
        return this->camera.position;
    }

    void MyCamera::setPosition(Vector3 position)
    {
        this->camera.position = position;
    }

    void MyCamera::setFov(float fov)
    {
        this->camera.fovy = fov;
    }

    float MyCamera::getFov() const
    {
        return this->camera.fovy;
    }

    void MyCamera::setCameraMode(CameraMode mode)
    {
        SetCameraMode(this->camera, mode);
    }

    Vector2 MyCamera::getWorldToScreen(Vector3 position)
    {
        return GetWorldToScreen(position, instance->camera);
    }

    std::shared_ptr<Indie::Lib::MyCamera> MyCamera::getInstance()
    {
        if (!instance) {
            instance = std::make_shared<Indie::Lib::MyCamera>();
        }
        return instance;
    }
}