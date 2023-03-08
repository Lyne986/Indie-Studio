/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** APlayer
*/

#include "APlayer.hpp"

namespace Indie::Objects::Interactables {
    APlayer::APlayer(int playerId, Vector3 pos, std::string texturePath) :
    Model3D("assets/objects/player.iqm", pos, 0.004f, {-90, 0, 0}),
    Movable3D(this->pos)
    {
        this->model->loadModelAnimations("assets/objects/playerAnimation.iqm", 3);
        this->setTextureFromFile(texturePath, MATERIAL_MAP_DIFFUSE, 0);
        this->model->updateModelAnimations(0, this->currentAnimFrame);

        this->speed = 2.5f;
        this->colliderOffset = 0.2f;
        this->playerId = playerId;
        this->isDead = false;
        this->bombRange = 1;
        this->maxNbBombs = 1;
        this->isMoving = false;
        this->isWinner = false;
        this->deadAnim = false;
        this->lastAnim = 0;
        this->deathSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/death.wav");
        this->deathSfx->setVolume(0.2f);
    }

    APlayer::~APlayer()
    {

    }

    void APlayer::init()
    {

    }
    void APlayer::init(std::vector<std::tuple<int, std::shared_ptr<Vector3>>> PlayersPositions, std::vector<std::shared_ptr<Interactables::APlayer>> Players)
    {

    }

    void APlayer::kill()
    {
        this->deadAnim = true;
        this->playerInfo->killPlayer();
        this->deathSfx->play();
    }

    void APlayer::update() {}

    void APlayer::update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& bombs) {}

    void APlayer::updateAnimation()
    {
        int currentAnim = -1;

        if (this->deadAnim) {
            currentAnim = 2;
        } else if (this->isWinner) {
            currentAnim = 3;
        } else if (this->isMoving) {
            currentAnim = 1;
        } else {
            currentAnim = 0;
        }
        if (this->lastAnim != currentAnim) {
            this->currentAnimFrame = 0;
            this->lastAnim = currentAnim;
        }
        if (currentAnim != -1) {
            int maxNbFrames = this->model->getNbFrames(currentAnim);
            if (maxNbFrames != -1) {
                this->model->updateModelAnimations(currentAnim, this->currentAnimFrame);
                this->currentAnimFrame++;
                if (this->currentAnimFrame >= maxNbFrames) {
                    if (this->deadAnim) {
                        this->isDead = true;
                    }
                    this->currentAnimFrame = 0;
                }
            }
        }
    }

    void APlayer::placeBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs)
    {
        if (this->bombs.size() < this->maxNbBombs) {
            Vector3 bombPos = {static_cast<float>(round(this->pos->x)), static_cast<float>(round(this->pos->y)), static_cast<float>(round(this->pos->z))};
            std::shared_ptr<Bomb> newBomb = std::make_shared<Bomb>(bombPos, this->bombRange);
            this->bombs.push_back(newBomb);
            colliders.push_back(newBomb);
            mapBombs.push_back(newBomb);
        }
    }

    void APlayer::placeBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, Vector3 bombPos)
    {
        if (this->bombs.size() < this->maxNbBombs) {
            std::shared_ptr<Bomb> newBomb = std::make_shared<Bomb>(bombPos, this->bombRange);
            this->bombs.push_back(newBomb);
            colliders.push_back(newBomb);
            mapBombs.push_back(newBomb);
        }
    }

    void APlayer::updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders)
    {
    }

    // bool APlayer::checkCollisionsBreakable(Vector3 pos, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
    //     float offset = this->colliderOffset;
    //     Lib::Shapes::MyRectangle currentCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2);
    //     Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

    //     for (auto collider : colliders) {
    //         if (this->checkCollision(currentCollider, nextCollider, collider) && collider->getTag() == "destroyable" && collider->getIsBomb() == false) {
    //             return true;
    //         }
    //     }
    //     return (false);
    // }
    
    bool APlayer::checkCollisionsBreakable(Vector3 pos, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        float offset = this->colliderOffset;
        Lib::Shapes::MyRectangle currentCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2);
        Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

        for (auto collider : colliders) {
            if (this->checkCollision(currentCollider, nextCollider, collider) && collider->getTag() == "destroyable" && collider->getIsBomb() == false) {
                return true;
            }
        }
        return (false);
    }

    bool APlayer::checkCollisions(Vector3 pos, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders)
    {
        float offset = this->colliderOffset;
        Lib::Shapes::MyRectangle currentCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2);
        Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

        for (auto collider : colliders) {
            if (this->checkCollision(currentCollider, nextCollider, collider)) {
                return true;
            }
        }
        return (false);
    }

    bool APlayer::checkCollision(Lib::Shapes::MyRectangle currentCollider, Lib::Shapes::MyRectangle nextCollider, std::shared_ptr<ECS::Systems::Collider>& collider)
    {
        if (!collider->getIsActive()) {
            return false;
        }
        if (collider->getCollider().checkCollisionRecs(currentCollider.getRectangle())) {
            return false;
        }
        if (collider->getCollider().checkCollisionRecs(nextCollider.getRectangle())) {
            return true;
        }
        return false;
    }

    void APlayer::checkPowerUps(std::vector<std::shared_ptr<DestroyableWall>>& destroyableWalls)
    {
        float offset = this->colliderOffset;
        Lib::Shapes::MyRectangle AplayerCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2);

        for (int i = 0; i < destroyableWalls.size(); i++) {
            if (destroyableWalls[i]->getCollider().checkCollisionRecs(AplayerCollider.getRectangle())) {
                if (!destroyableWalls[i]->getIsActive() && destroyableWalls[i]->getHasPowerUp()) {
                    destroyableWalls[i]->pickUpPowerUp(*this);
                }
            }
        }
    }

    void APlayer::setPlayerInfo(std::shared_ptr<PlayerInfo> info)
    {
        this->playerInfo = info;
    }

    bool APlayer::getIsDead() const
    {
        return this->isDead;
    }

    void APlayer::setBombRange(int newRange)
    {
        this->bombRange = newRange;
        this->playerInfo->increaseRange(this->bombRange);
    }

    int APlayer::getBombRange(void) const
    {
        return this->bombRange;
    }

    void APlayer::setSpeed(float newSpeed)
    {
        this->speed = newSpeed;
        this->playerInfo->increaseSpeed();
    }

    float APlayer::getSpeed(void) const
    {
        return this->speed;
    }

    void APlayer::setMaxNbBombs(int newMaxNbBombs)
    {
        this->maxNbBombs = newMaxNbBombs;
        this->playerInfo->increaseBombs(this->maxNbBombs);
    }

    int APlayer::getMaxNbBombs(void) const
    {
        return this->maxNbBombs;
    }

    std::shared_ptr<Vector3> APlayer::getmovPos() {
        return this->movPos;
    }

    int APlayer::getPlayerId() {
        return this->playerId;
    }

    bool APlayer::getIsAI() {
        return this->_isAI;
    }

    Lib::Shapes::MyRectangle APlayer::getRectangle(void) const
    {
        float offset = this->colliderOffset;
        Lib::Shapes::MyRectangle playerCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2);
        return playerCollider;
    }

    void APlayer::setWinner()
    {
        this->isWinner = true;
        this->rot->z = 0;
    }

    Vector3 APlayer::getRot() const
    {
        return (*this->rot);
    }

    void APlayer::setRot(Vector3 rot)
    {
        *this->rot = rot;
    }

    std::shared_ptr<Vector3> APlayer::getPos() {
        return (this->pos);
    }
}
