/*
** EPITECH PROJECT, 2021
** project
** File description:
** Model3D.hpp
*/

#ifndef __LIB_MY_MODEL_HPP__
    #define __LIB_MY_MODEL_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyModel {
    protected:
        Model model;
        ModelAnimation *animations;
        unsigned int animCount;
        float scale;

    public:
        // Constructor / Destructor
        MyModel(std::string modelPath, float scale);
        MyModel(Mesh mesh, float scale);
        ~MyModel();

        // Useful functions
        void loadModelAnimations(std::string modelPath, unsigned int nbAnims);
        void updateModelAnimations(int currentAnim, int currentFrame);
        void draw(Vector3 positon) const;

        // Getter / Setter
        void setTexture(Texture2D texture, int material, int materialId);
        int getNbFrames(int currentAnim) const;
};

#endif