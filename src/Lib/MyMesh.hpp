/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyMesh.hpp
*/

#ifndef __LIB_MY_MESH_HPP__
    #define __LIB_MY_MESH_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyMesh {
    protected:
        Mesh mesh;
        Vector3 cubeSize;

    public:
    // Constructor / Destructor
        MyMesh(Image image, Vector3 cubeSize);
        MyMesh(Vector3 cubeSize);

    // Getter / Setter
        Mesh getMesh() const;
};

#endif