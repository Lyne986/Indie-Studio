/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyMesh.cpp
*/

#include "MyMesh.hpp"

namespace Indie::Lib {
    MyMesh::MyMesh(Image image, Vector3 cubeSize)
    {
        this->cubeSize = cubeSize;
        this->mesh = GenMeshCubicmap(image, this->cubeSize);
    }

    MyMesh::MyMesh(Vector3 cubeSize)
    {
        this->cubeSize = cubeSize;
        this->mesh = GenMeshCube(this->cubeSize.x, this->cubeSize.y, this->cubeSize.z);
    }

    Mesh MyMesh::getMesh() const
    {
        return this->mesh;
    }
}