/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Map3D.cpp
*/

#include "Map3D.hpp"

namespace Indie::ECS::Components {
    Map3D::Map3D(std::string mapPath, Vector3 pos, float scale, Vector3 rotation) :
    Model3D(pos, scale, rotation)
    {
        Lib::MyImage image(mapPath + ".png");
        Vector3 cubeSize = {1, 1, 1};

        this->mesh = std::make_unique<Lib::MyMesh>(image.getImage(), cubeSize);
        this->model = std::make_unique<Lib::MyModel>(this->mesh->getMesh(), scale);
        this->setTextureFromFile(mapPath + "_texture.png", MATERIAL_MAP_DIFFUSE, 0);
    }
}
