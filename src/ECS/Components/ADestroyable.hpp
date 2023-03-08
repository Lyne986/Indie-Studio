/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** ADestroyable.hpp
*/

#ifndef __A_DESTROYABLE_HPP__
    #define __A_DESTROYABLE_HPP__

    #include "../ECS_namespace.hpp"
    #include "Model3D.hpp"
    #include "../Systems/Collider.hpp"

class Indie::ECS::Components::ADestroyable :
public Model3D,
public Systems::Collider {
    public:
    // Constructor / Destructor
        ADestroyable(std::string texturePath="assets/maps/map1_d_texture.png", int materialId=0, Vector3 pos={0, 0, 0}, float scale=1.0f, Vector3 rotation={0, 0, 0});
        ADestroyable(std::string modelPath="assets/objects/bomb.gltf", std::string texturePath="assets/objects/textures/Bomb_diffuse.png", int materialId=0, Vector3 pos={0, 0, 0}, float scale=1.0f, Vector3 rotation={0, 0, 0});
        ADestroyable(Vector3 pos, float scale, Vector3 rotation);
        virtual ~ADestroyable() = default;

    // Useful functions
        void init();
        void update();
        void destroy();
};

#endif