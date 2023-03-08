/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Model3D.cpp
*/

#include "Model3D.hpp"

namespace Indie::ECS::Components {
    Model3D::Model3D(std::string modelPath, Vector3 pos, float scale, Vector3 rotation) :
    Object3D(pos, scale, rotation)
    {
        this->model = std::make_shared<Lib::MyModel>(modelPath, scale);
        this->currentAnimFrame = 0;
    }

    Model3D::Model3D(Lib::MyMesh mesh, Vector3 pos, float scale, Vector3 rotation) :
    Object3D(pos, scale, rotation)
    {
        this->loadModelFromMesh(mesh, *this->scale);
    }

    void Model3D::loadModelFromMesh(Lib::MyMesh mesh, float scale)
    {
        *this->scale = scale;
        this->model = std::make_shared<Lib::MyModel>(mesh.getMesh(), *this->scale);
    }

    Model3D::Model3D(Vector3 pos, float scale, Vector3 rotation) :
    Object3D(pos, scale, rotation)
    {
        this->model = nullptr;
    }

    void Model3D::draw() const
    {
        if (this->model) {
            this->transform.pushMatrix();
            this->AdjustRotation();
            this->model->draw(*this->pos);
            this->transform.popMatrix();
        }
    }

    void Model3D::setTextureFromFile(const std::string& filePath, int material, int materialId)
    {
        this->texture = std::make_unique<Lib::MyTexture>(filePath);
        this->setTexture(this->texture->getTexture(), material, materialId);
    }

    void Model3D::setTextureFromImage(Image image, int material, int materialId)
    {
        this->texture = std::make_unique<Lib::MyTexture>(image);
        this->setTexture(this->texture->getTexture(), material, materialId);
    }

    void Model3D::setTexture(Texture2D texture, int material, int materialId)
    {
        if (this->model) {
            this->model->setTexture(texture, material, materialId);
        }
    }
}
