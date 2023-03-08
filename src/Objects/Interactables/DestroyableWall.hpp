/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** DestroyableWall.hpp
*/

#ifndef __DESTROYABLE_WALL_HPP__
    #define __DESTROYABLE_WALL_HPP__

    #include "../Objects_namespace.hpp"
    #include "APlayer.hpp"
    #include "PowerUp.hpp"

class Indie::Objects::Interactables::DestroyableWall : public ECS::Components::ADestroyable {
    private:
        std::unique_ptr<PowerUp> powerUp;


    public:
        DestroyableWall(std::string texturePath, Vector3 pos);
        ~DestroyableWall();
        void pickUpPowerUp(APlayer& player);
        bool getHasPowerUp() const;
        void draw() const;
        int getPowerUp();
        void setPowerUp(int powerUp);
};

#endif
