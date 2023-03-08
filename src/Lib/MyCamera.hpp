/*
** EPITECH PROJECT, 2021
** project
** File description:
** Camera.hpp
*/

#ifndef __LIB_MY_CAMERA_HPP__
    #define __LIB_MY_CAMERA_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyCamera {
    private:
        Camera camera;
        static std::shared_ptr<Indie::Lib::MyCamera> instance;

    public:
    // Constructor / Destructor
        MyCamera();

    // Useful functions
        void update();
        void begin3DMode() const;
        void end3DMode() const;

    // Getter / Setter
        Vector3 getPosition() const;
        void setPosition(Vector3 position);
        Vector3 getTarget() const;
        void setTarget(Vector3 target);
        void setFov(float fov);
        float getFov() const;
        void setCameraMode(CameraMode mode);
        void setCamera(Vector3 position, Vector3 target, Vector3 rotation, float fovy, int projection);

        static Vector2 getWorldToScreen(Vector3 position);
        static std::shared_ptr<Indie::Lib::MyCamera> getInstance();
};

#endif