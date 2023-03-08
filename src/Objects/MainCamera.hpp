/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MainCamera.hpp
*/

#ifndef __MAIN_CAMERA_HPP__
    #define __MAIN_CAMERA_HPP__

    #include "Objects_namespace.hpp"

class Indie::Objects::MainCamera : public Indie::ECS::Systems::Object3D {
    private:
        std::shared_ptr<Lib::MyCamera> camera;

    public:
        MainCamera();
        ~MainCamera();
        void update();
        void init();
        void begin3DMode();
        void end3DMode();
};

#endif
