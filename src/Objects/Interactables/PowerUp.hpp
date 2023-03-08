/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PowerUp.hpp
*/

#ifndef __POWER_UP_HPP__
    #define __POWER_UP_HPP__

    #include "../Objects_namespace.hpp"
    #include "APlayer.hpp"

class Indie::Objects::Interactables::PowerUp : public ECS::Components::ADestroyable {
    private:
        enum powerUpType {
            BOMB_RANGE_UP,
            PLAYER_SPEED_UP,
            PLAYER_NB_BOMB_UP
        };

        std::map<powerUpType, std::string> powerUpAssets =
        {
            {BOMB_RANGE_UP, "assets/objects/powerUps/player_bomb_range_up.png"},
            {PLAYER_SPEED_UP, "assets/objects/powerUps/player_speed_up.png"},
            {PLAYER_NB_BOMB_UP, "assets/objects/powerUps/player_nb_bombs_up.png"}
        };

        int nbPowerUps = 3;
        powerUpType powerUpType;

        std::unique_ptr<Lib::Audio::MySound> powerUpSfx;

    public:
        PowerUp(Vector3 pos);
        ~PowerUp();
        void pickUpPowerUp(APlayer& player);
        int getPowerUpType() const;
        void setPowerUpType(int powerUpType);
};

#endif
