/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Collider.hpp
*/

#ifndef __COLLIDER_HPP__
    #define __COLLIDER_HPP__

    #include "../ECS_namespace.hpp"

class Indie::ECS::Systems::Collider {
    protected:
        std::shared_ptr<Lib::Shapes::MyRectangle> collider;
        bool isActive;
        bool isBomb;
        std::string tag;

    public:
    // Constructor / Destructor
        Collider(float x, float y, int width, int height, std::string tag);

    // Useful functions
    // Getter / Setter
        Lib::Shapes::MyRectangle getCollider() const;
        bool getIsActive() const;
        bool getIsBomb() const;
        void setIsActive(bool value);
        void setIsBomb(bool value);
        std::string getTag() const;
        Rectangle getRect() const;
};

#endif
