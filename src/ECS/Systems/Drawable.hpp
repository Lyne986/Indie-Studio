/*
** EPITECH PROJECT, 2021
** project
** File description:
** Drawable.hpp
*/

#ifndef __DRAWABLE_HPP__
    #define __DRAWABLE_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Drawable {
    public:
        Drawable() {};

    // Useful functions
        virtual void draw() const = 0;
};

#endif