/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** ADestroyable.cpp
*/

#include "ADestroyable.hpp"

namespace Indie::ECS::Components {
    ADestroyable::ADestroyable(std::string texturePath, int materialId, Vector3 pos, float scale, Vector3 rotation) :
    Model3D(pos, scale, rotation),
    Collider(pos.x, pos.z, 1.0f, 1.0f, "destroyable")
    {
        Vector3 cubeSize = {1.0f, 1.0f, 1.0f};
        Lib::MyMesh mesh(cubeSize);

        this->loadModelFromMesh(mesh, *this->scale);
        this->setTextureFromFile(texturePath, MATERIAL_MAP_DIFFUSE, materialId);
    }

    ADestroyable::ADestroyable(std::string modelPath, std::string texturePath, int materialId, Vector3 pos, float scale, Vector3 rotation) :
    Model3D(modelPath, pos, scale, rotation),
    Collider(pos.x, pos.z, 1.0f, 1.0f, "destroyable")
    {
        this->setTextureFromFile(texturePath, MATERIAL_MAP_DIFFUSE, materialId);
    }

    ADestroyable::ADestroyable(Vector3 pos, float scale, Vector3 rotation) :
    Model3D(pos, scale, rotation),
    Collider(pos.x, pos.z, 1.0f, 1.0f, "destroyable") {}

    void ADestroyable::destroy()
    {
        this->isActive = false;
    }

    void ADestroyable::init()
    {
    }

    void ADestroyable::update() {}
}