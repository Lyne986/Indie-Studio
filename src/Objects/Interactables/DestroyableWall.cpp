/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** DestroyableWall.cpp
*/

#include "DestroyableWall.hpp"

namespace Indie::Objects::Interactables {
    DestroyableWall::DestroyableWall(std::string texturePath, Vector3 pos) :
    ADestroyable(texturePath, 0, pos, 1.0f, {0.0f, 0.0f, 0.0f})
    {
        int random = rand() % 2;
        if (random == 0) {
            this->powerUp = std::make_unique<PowerUp>(pos);
        } else {
            this->powerUp = nullptr;
        }
    }

    void DestroyableWall::pickUpPowerUp(APlayer& player)
    {
        if (this->powerUp) {
            this->powerUp->pickUpPowerUp(player);
        }
    }

    bool DestroyableWall::getHasPowerUp() const
    {
        if (this->powerUp) {
            return this->powerUp->getIsActive();
        }
        return false;
    }

    void DestroyableWall::draw() const
    {
        if (this->isActive) {
            Model3D::draw();
        } else if (this->powerUp && this->powerUp->getIsActive()) {
            this->powerUp->draw();
        }
    }

    int DestroyableWall::getPowerUp()
    {
        if (this->powerUp) {
            return (this->powerUp->getPowerUpType());
        }
        return -1;
    }

    void DestroyableWall::setPowerUp(int powerUp)
    {
        if (this->powerUp == nullptr) {
            // // // // std::cout << "no power up" << std::endl;
            this->powerUp = std::make_unique<PowerUp>(this->getPosition());
        }
        if (powerUp == -1) {
            this->powerUp = nullptr;
        } else {
            // // // // std::cout << "set power up" << std::endl;
            this->powerUp->setPowerUpType(powerUp);
        }
    }


    DestroyableWall::~DestroyableWall() {}

}
