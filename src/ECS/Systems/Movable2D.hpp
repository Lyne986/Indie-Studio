/*
** EPITECH PROJECT, 2021
** project
** File description:
** Movable2D.hpp
*/

#ifndef __MOVEABLE2_HPP__
    #define __MOVEABLE2_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Movable2D {
    private:
        std::shared_ptr<Vector2> movPos;

    public:
    // Constructor / Destructor

        Movable2D(std::shared_ptr<Vector2> pos);

    // Useful methods

        void moveX(float x);
        void moveY(float y);
        void move(Vector2 dir);
};

#endif