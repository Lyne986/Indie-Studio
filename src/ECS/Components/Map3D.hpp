/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Map3D.hpp
*/

#ifndef __ECS_MAP_3D_HPP__
    #define __ECS_MAP_3D_HPP__

    #include "../ECS_namespace.hpp"
    #include "Model3D.hpp"

class Indie::ECS::Components::Map3D :
public Components::Model3D {
    protected:
        std::unique_ptr<Indie::Lib::MyMesh> mesh;

    public:
    // Constructor / Destructor
        Map3D(std::string mapPath, Vector3 pos, float scale, Vector3 rotation);

    // Useful functions
        virtual void init() = 0;
        virtual void update() = 0;
};

#endif