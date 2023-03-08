/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PowerUp.cpp
*/

#include "PowerUp.hpp"

namespace Indie::Objects::Interactables {
    PowerUp::PowerUp(Vector3 pos) :
    ADestroyable(pos, 1.0f, {0.0f, 0.0f, 0.0f})
    {
        int powerType = rand() % this->nbPowerUps;
        this->powerUpType = static_cast<enum powerUpType>(powerType);

        Vector3 cubeSize = {1.0f, 0.2f, 1.0f};
        Lib::MyMesh mesh(cubeSize);

        this->loadModelFromMesh(mesh, *this->scale);
        this->setTextureFromFile(this->powerUpAssets[this->powerUpType], MATERIAL_MAP_DIFFUSE, 0);

        this->powerUpSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/powerUp.mp3");
        this->powerUpSfx->setVolume(2);
    }

    void PowerUp::pickUpPowerUp(APlayer& player)
    {
        this->powerUpSfx->play();
        if (this->powerUpType == BOMB_RANGE_UP) {
            player.setBombRange(player.getBombRange() + 1);
        } else if (this->powerUpType == PLAYER_SPEED_UP) {
            player.setSpeed(player.getSpeed() + 0.5f);
        } else if (this->powerUpType == PLAYER_NB_BOMB_UP) {
            player.setMaxNbBombs(player.getMaxNbBombs() + 1);
        }
        this->isActive = false;
    }

    void PowerUp::setPowerUpType(int powerUpType)
    {
        this->powerUpType = static_cast<enum powerUpType>(powerUpType);
    }

    int PowerUp::getPowerUpType() const
    {
        return (this->powerUpType);
    }

    PowerUp::~PowerUp() {}

}
