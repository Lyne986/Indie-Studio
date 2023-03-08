/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Model3D.hpp
*/

#ifndef __ECS_MODEL_3D_HPP__
    #define __ECS_MODEL_3D_HPP__

    #include "../ECS_namespace.hpp"
    #include "../Systems/Object3D.hpp"
    #include "../Systems/Drawable.hpp"

class Indie::ECS::Components::Model3D :
public Systems::Object3D,
public Systems::Drawable {
    protected:
        std::shared_ptr<Indie::Lib::MyTexture> texture;
        std::shared_ptr<Indie::Lib::MyModel> model;
        int currentAnimFrame;

    public:
    // Constructor / Destructor
        Model3D(std::string modelPath, Vector3 pos, float scale, Vector3 rotation);
        Model3D(Lib::MyMesh mesh, Vector3 pos, float scale, Vector3 rotation);
        Model3D(Vector3 pos, float scale, Vector3 rotation);

    // Useful functions
        virtual void init() = 0;
        virtual void update() = 0;
        void draw() const;
        void loadModelFromMesh(Lib::MyMesh mesh, float scale);

    // Getter / Setter
        void setTextureFromFile(const std::string& filename, int material, int materialId);
        void setTextureFromImage(Image image, int material, int materialId);
        void setTexture(Texture2D texture, int material, int materialId);
};

#endif