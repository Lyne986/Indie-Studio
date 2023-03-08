/*
** EPITECH PROJECT, 2021
** project
** File description:
** IScene.hpp
*/

#ifndef __ISCENE_HPP__
    #define __ISCENE_HPP__

    #include "SceneNamespace.hpp"

class Indie::Scenes::IScene {
    public:
        virtual ~IScene() = default;
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void drawUnder2D() = 0;
        virtual void draw3D() = 0;
        virtual void drawOver2D() = 0;
        virtual void destroy() = 0;
};

#endif