/*
** EPITECH PROJECT, 2021
** project
** File description:
** Object3D.hpp
*/

#ifndef __ECS_OBJECT_3D_HPP__
    #define __ECS_OBJECT_3D_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Object3D {
    protected:
        Lib::MyTransform transform;
        std::shared_ptr<Vector3> pos;
        std::shared_ptr<float> scale;
        std::shared_ptr<Vector3> rot;
        float getClampedValue(float value) const;

    public:
    // Constructor / Destructor
        Object3D(Vector3 pos, float scale, Vector3 rotation);

    // Useful func
        virtual void init() = 0;
        virtual void update() = 0;
        void AdjustRotation() const;

    // Getter / Setter
    Vector3 getPosition() const;
    void setPosition(Vector3 pos);
};

#endif