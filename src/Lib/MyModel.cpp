/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyModel.cpp
*/

#include "MyModel.hpp"

namespace Indie::Lib {
    MyModel::MyModel(std::string modelPath, float scale)
    {
        this->scale = scale;
        this->model = LoadModel(modelPath.c_str());
        this->animations = nullptr;
    }

    MyModel::MyModel(Mesh mesh, float scale)
    {
        this->scale = scale;
        this->model = LoadModelFromMesh(mesh);
    }

    MyModel::~MyModel()
    {
        // Free of animations, at the moment it crashes
        // if (this->animations) {
            // for (unsigned int i = 0; i < this->animCount; i++) {
            //     UnloadModelAnimation(this->animations[i]);
            // }
            // RL_FREE(this->animations);
        // }
        UnloadModel(this->model);
    }

    void MyModel::loadModelAnimations(std::string modelPath, unsigned int nbAnims)
    {
        this->animCount = nbAnims;
        this->animations = LoadModelAnimations(modelPath.c_str(), &this->animCount);
    }

    void MyModel::updateModelAnimations(int currentAnim, int currentFrame)
    {
        if (this->animations) {
            UpdateModelAnimation(this->model, this->animations[currentAnim], currentFrame);
        }
    }

    int MyModel::getNbFrames(int currentAnim) const
    {
        if (this->animations) {
            return this->animations[currentAnim].frameCount;
        }
        return -1;
    }

    void MyModel::draw(Vector3 position) const
    {
        DrawModel(this->model, position, this->scale, WHITE);
    }

    void MyModel::setTexture(Texture2D texture, int material, int materialId)
    {
        SetMaterialTexture(&this->model.materials[materialId], material, texture);
    }
}