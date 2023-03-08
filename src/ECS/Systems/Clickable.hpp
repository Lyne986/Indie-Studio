/*
** EPITECH PROJECT, 2021
** project
** File description:
** Clickeable.hpp
*/

#ifndef __ECS_CLICKEABLE_HPP__
    #define __ECS_CLICKEABLE_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Clickable {
    protected:
        std::shared_ptr<Vector2> clickPos;
        std::shared_ptr<Vector2> clickDim;
        Lib::MyEvent event;

    public:
    // Constructor / Destructor

        Clickable(std::shared_ptr<Vector2> pos, std::shared_ptr<Vector2> dim);

    // Useful functions

        bool isClick();
        bool isOver();
};

#endif