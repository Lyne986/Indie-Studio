/*
** EPITECH PROJECT, 2021
** project
** File description:
** Object2D.hpp
*/

#ifndef __ECS_OBJECT_HPP__
    #define __ECS_OBJECT_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Object2D {
    protected:
        std::shared_ptr<Vector2> pos;
        std::shared_ptr<Vector2> dim;

    public:
    // Constructor / Destructor

        Object2D(Vector2 pos, Vector2 dim);

    // Useful func

        virtual void init() = 0;
        virtual void update() = 0;
};

#endif