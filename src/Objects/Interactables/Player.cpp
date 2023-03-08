/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Player.cpp
*/

#include "Player.hpp"

namespace Indie::Objects::Interactables {
    Player::Player(int playerId, Vector3 pos, int controllerId, std::string modelPath) :
    APlayer(playerId, pos, modelPath)
    {
        this->_isAI = false;
        this->controllerId = controllerId;
    }

    Player::~Player()
    {

    }

    void Player::update() {}

    void Player::update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs)
    {
        this->updateMovement(colliders);
        int explodedBomb = -1;

        if (this->bombs.size() > 0) {
            for (int i = 0; i < this->bombs.size(); i++) {
                if (this->bombs[i]->getHasExploded()) {
                    explodedBomb = i;
                }
            }
            if (explodedBomb != -1) {
                this->bombs.erase(this->bombs.begin() + explodedBomb);
            }
        }
        if (this->controllerId == -1 && event.isKey(Lib::MyEvent::MyEvent::RELEASED, KEY_SPACE)) {
            this->placeBomb(colliders, mapBombs);
        } else if (this->controllerId >= 0 && event.isGamepadButton(Lib::MyEvent::MyEvent::RELEASED, this->controllerId, 6)) {
            this->placeBomb(colliders, mapBombs);
        }
    }

    void Player::updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders)
    {
        Vector3 moveDir = {0, 0, 0};

        if (this->controllerId == -1) {
            moveDir = this->getKeyboardMovement();
        } else {
            moveDir = this->getGamepadMovement();
        }

        Vector3 nextPos = {this->pos->x + moveDir.x, this->pos->y + moveDir.y, this->pos->z + moveDir.z};
        if (!this->checkCollisions(nextPos, colliders)) {
            this->move(moveDir);
        }
    }

    Vector3 Player::getKeyboardMovement()
    {
        Vector3 moveDir = {0, 0, 0};

        this->isMoving = true;
        if (event.isKey(Lib::MyEvent::MyEvent::DOWN, KEY_RIGHT)) {
            moveDir.x += speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 90;
        } else if (event.isKey(Lib::MyEvent::MyEvent::DOWN, KEY_LEFT)) {
            moveDir.x -= speed * Lib::MyWindow::getFrameTime();
            this->rot->z = -90;
        } else if (event.isKey(Lib::MyEvent::MyEvent::DOWN, KEY_DOWN)) {
            moveDir.z += speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 0;
        } else if (event.isKey(Lib::MyEvent::MyEvent::DOWN, KEY_UP)) {
            moveDir.z -= speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 180;
        } else {
            this->isMoving = false;
        }
        return moveDir;
    }

    Vector3 Player::getGamepadMovement()
    {
        Vector3 moveDir = {0, 0, 0};
        Vector2 input = event.getGamepadAxisMovement(this->controllerId, 0);

        this->isMoving = true;
        if (abs(input.x) > abs(input.y)) {
            moveDir.x += speed * input.x * Lib::MyWindow::getFrameTime();
            if (input.x > 0) {
                this->rot->z = 90;
            } else {
                this->rot->z = -90;
            }
        } else if (abs(input.x) < abs(input.y)) {
            moveDir.z += speed * input.y * Lib::MyWindow::getFrameTime();
            if (input.y > 0) {
                this->rot->z = 0;
            } else {
                this->rot->z = 180;
            }
        } else {
            this->isMoving = false;
        }
        return moveDir;
    }
}
