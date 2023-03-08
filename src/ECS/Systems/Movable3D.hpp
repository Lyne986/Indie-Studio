/*
** EPITECH PROJECT, 2021
** project
** File description:
** Movable3D.hpp
*/

#ifndef __ECS_MOVEABEL_HPP__
    #define __ECS_MOVEABEL_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Movable3D {
    protected:
        std::shared_ptr<Vector3> movPos;

    public:
    // Constructor / Destructor

        Movable3D(std::shared_ptr<Vector3> pos);

    // Useful function

        void move(Vector3 direction);

};

#endif