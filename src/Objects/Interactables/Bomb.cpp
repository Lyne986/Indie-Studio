/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

namespace Indie::Objects::Interactables {
    Bomb::Bomb(Vector3 pos, int range) :
    ADestroyable("assets/objects/bomb.iqm", "assets/objects/textures/bomb_diffuse.png", 0, pos, 0.9f, {-90.0f, 0.0f, 0.0f})
    {
        this->model->loadModelAnimations("assets/objects/bombAnimation.iqm", 0);

        this->timer = std::chrono::steady_clock::now() + std::chrono::seconds(2);
        this->hasExploded = false;
        this->range = range;
        this->isBomb = true;

        this->placeSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/placeBomb.wav");
        this->placeSfx->setVolume(1);
        this->placeSfx->play();
        this->explodeSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/bombExplosion.wav");
        this->explodeSfx->setVolume(1);
    }

    Bomb::~Bomb() {}

    void Bomb::update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::APlayer>>& players)
    {
        int maxNbFrames = this->model->getNbFrames(0);
        if (maxNbFrames != -1) {
            this->model->updateModelAnimations(0, this->currentAnimFrame);
            this->currentAnimFrame++;
            if (this->currentAnimFrame >= maxNbFrames) {
                this->currentAnimFrame = 0;
            }
        }

        if (!this->hasExploded) {
            if (!this->isActive || std::chrono::steady_clock::now() >= this->timer) {
                this->hasExploded = true;
                this->explode(colliders, players);
            }
        }
        for (int i = 0; i < this->bombEffects.size(); i++) {
            this->bombEffects[i]->update();
        }
    }

    void Bomb::drawEffects() const
    {
        for (int i = 0; i < this->bombEffects.size(); i++) {
            this->bombEffects[i]->draw();
        }
    }

    void Bomb::createEffects(std::map<Dir, std::vector<std::shared_ptr<ECS::Systems::Collider>>>& bombColliders)
    {
        for (int r = -1 * this->range; r <= this->range; r++) {
            if (r == 0) {
                this->createEffect(RIGHT, r, bombColliders);
            } else if (r < 0) {
                this->createEffect(LEFT, r, bombColliders);
                this->createEffect(UP, r, bombColliders);
            } else {
                this->createEffect(RIGHT, r, bombColliders);
                this->createEffect(DOWN, r, bombColliders);
            }
        }
    }

    void Bomb::createEffect(Dir dir, int r, std::map<Dir, std::vector<std::shared_ptr<ECS::Systems::Collider>>>& bombColliders)
    {
        Vector3 worldPos = {this->pos->x, 0, this->pos->z};
        if (dir == LEFT || dir == RIGHT) {
            worldPos.x += r;
        } else {
            worldPos.z += r;
        }

        Vector2 screenPos = Lib::MyCamera::getWorldToScreen(worldPos);
        if (bombColliders.find(dir) == bombColliders.end()) {
            this->bombEffects.push_back(std::make_unique<ECS::Components::Effect>("assets/objects/explosionEffect.png", screenPos, 4, 5));
        } else {
            Rectangle firstCollider = bombColliders[dir][0]->getCollider().getRectangle();
            Rectangle collider = {worldPos.x, worldPos.z, 0, 0};
            if ((bombColliders[dir][0]->getTag() == "destroyable" && this->checkEqualCollision(firstCollider, collider, dir)) || this->checkCollisionPriority(firstCollider, collider, dir)) {
                this->bombEffects.push_back(std::make_unique<ECS::Components::Effect>("assets/objects/explosionEffect.png", screenPos, 4, 5));
            }
        }
    }

    void Bomb::explode(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::APlayer>>& players)
    {
        Vector2 bombPos = {static_cast<float>(round(this->pos->x)), static_cast<float>(round(this->pos->z))};
        std::map<Dir, std::vector<std::shared_ptr<ECS::Systems::Collider>>> bombColliders;

        this->isActive = false;
        this->explodeSfx->play();

        for (int i = 0; i < colliders.size(); i++) {
            if (!colliders[i]->getIsActive()) {
                continue;
            }
            Rectangle collider = colliders[i]->getCollider().getRectangle();
            Dir collisionDir = checkCollision(*this->pos, collider.x, collider.y, this->range);
            if (collisionDir != NONE) {
                if (bombColliders.find(collisionDir) == bombColliders.end()) {
                    bombColliders[collisionDir].push_back(colliders[i]);
                } else {
                    Rectangle firstCollider = bombColliders[collisionDir][0]->getCollider().getRectangle();
                    if (this->checkCollisionPriority(firstCollider, collider, collisionDir)) {
                        bombColliders[collisionDir].insert(bombColliders[collisionDir].begin(), colliders[i]);
                    }
                }
            }
        }
        for (int i = 0; i < players.size(); i++) {
            if (players[i] && !players[i]->getIsDead()) {
                Rectangle collider = players[i]->getRectangle().getRectangle();
                Dir collisionDir = checkCollision(*this->pos, round(collider.x), round(collider.y), this->range);
                if (collisionDir != NONE) {
                    if (bombColliders.find(collisionDir) == bombColliders.end()) {
                        players[i]->kill();
                    } else {
                        Rectangle firstCollider = bombColliders[collisionDir][0]->getCollider().getRectangle();
                        if (this->checkCollisionPriority(firstCollider, collider, collisionDir)) {
                            bombColliders.erase(collisionDir);
                            players[i]->kill();
                        }
                    }
                }
            }
        }
        this->createEffects(bombColliders);
        for (auto it = bombColliders.begin(); it != bombColliders.end(); ++it)
        {
            if (bombColliders[it->first][0]->getTag() == "destroyable") {
                bombColliders[it->first][0]->setIsActive(false);
            }
        }
    }

    bool Bomb::checkCollisionPriority(Rectangle firstCollider, Rectangle collider, Dir collisionDir)
    {
        if (collisionDir == LEFT && firstCollider.x < collider.x) {
            return true;
        }
        if (collisionDir == RIGHT && firstCollider.x > collider.x) {
            return true;
        }
        if (collisionDir == UP && firstCollider.y < collider.y) {
            return true;
        }
        if (collisionDir == DOWN && firstCollider.y > collider.y) {
            return true;
        }
        return false;
    }

    bool Bomb::checkEqualCollision(Rectangle firstCollider, Rectangle collider, Dir collisionDir)
    {
        if (collisionDir == LEFT && firstCollider.x == collider.x) {
            return true;
        }
        if (collisionDir == RIGHT && firstCollider.x == collider.x) {
            return true;
        }
        if (collisionDir == UP && firstCollider.y == collider.y) {
            return true;
        }
        if (collisionDir == DOWN && firstCollider.y == collider.y) {
            return true;
        }
        return false;
    }

    Bomb::Dir Bomb::checkCollision(Vector3 pos, float x, float y, int range)
    {
        Vector2 bombPos = {static_cast<float>(round(pos.x)), static_cast<float>(round(pos.z))};
        if (x >= bombPos.x - range && x <= bombPos.x + range && y == bombPos.y) {
            if (x < bombPos.x) {
                return LEFT;
            } else {
                return RIGHT;
            }
        }
        if (y >= bombPos.y - range && y <= bombPos.y + range && x == bombPos.x) {
            if (y < bombPos.y) {
                return UP;
            } else {
                return DOWN;
            }
        }
        return NONE;
    }

    bool Bomb::getHasExploded()
    {
        return this->hasExploded;
    }

    int Bomb::getRange() const
    {
        return this->range;
    }

    void Bomb::pauseBomb()
    {
        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
        this->secondsLeft = std::chrono::duration_cast<std::chrono::seconds>(this->timer - currentTime).count();
    }

    void Bomb::resumeBomb()
    {
        this->timer = std::chrono::steady_clock::now() + std::chrono::seconds(this->secondsLeft);
    }
}
