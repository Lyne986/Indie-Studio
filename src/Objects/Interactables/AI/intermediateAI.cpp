/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** intermediateAI
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {
    void AI::goPlaceBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions) {
        MoveDir dir = NULL_DIR;
        this->touchDestructibleCollider(colliders, mapBombs, possiblePositions);
        if (this->bombs.size() != 0) return;
        dir = this->basicMove(colliders, dir, possiblePositions);
        this->oneBlockMove(dir);
    }

    void AI::moveEscape(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<Vector3> possiblePositions, MoveDir dir) {
        if (dir == RIGHT) {
            if (!this->checkCollisions(possiblePositions[3], colliders)) {
                this->oneBlockMove(RIGHT);
            } else if (!this->checkCollisions(possiblePositions[2], colliders)) {
                this->oneBlockMove(LEFT);
            } else if (!this->checkCollisions(possiblePositions[0], colliders)) {
                this->oneBlockMove(UP);
            } else if (!this->checkCollisions(possiblePositions[1], colliders)) {
                this->oneBlockMove(DOWN);
            }
        } else if (dir == LEFT) {
            if (!this->checkCollisions(possiblePositions[2], colliders)) {
                this->oneBlockMove(LEFT);
            } else if (!this->checkCollisions(possiblePositions[3], colliders)) {
                this->oneBlockMove(RIGHT);
            } else if (!this->checkCollisions(possiblePositions[0], colliders)) {
                this->oneBlockMove(UP);
            } else if (!this->checkCollisions(possiblePositions[1], colliders)) {
                this->oneBlockMove(DOWN);
            }
        } else if (dir == UP) {
            if (!this->checkCollisions(possiblePositions[0], colliders)) {
                this->oneBlockMove(UP);
            } else if (!this->checkCollisions(possiblePositions[1], colliders)) {
                this->oneBlockMove(DOWN);
            } else if (!this->checkCollisions(possiblePositions[3], colliders)) {
                this->oneBlockMove(RIGHT);
            } else if (!this->checkCollisions(possiblePositions[2], colliders)) {
                this->oneBlockMove(LEFT);
            }
        } else if (dir == DOWN) {
            if (!this->checkCollisions(possiblePositions[1], colliders)) {
                this->oneBlockMove(DOWN);
            } else if (!this->checkCollisions(possiblePositions[0], colliders)) {
                this->oneBlockMove(UP);
            } else if (!this->checkCollisions(possiblePositions[3], colliders)) {
                this->oneBlockMove(RIGHT);
            } else if (!this->checkCollisions(possiblePositions[2], colliders)) {
                this->oneBlockMove(LEFT);
            }
        }
        // std::cout << "\n\n\n\n\nescape" << std::endl;
    }

    void AI::tryEscapeFromBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<Vector3> possiblePositions, std::vector<MoveDir> dangerDir) {
        MoveDir safePosition;
        // std::cout << "\n\n\n\n\n danger[0] " << dangerDir[0] << std::endl;
        if (dangerDir.size() == 1) {
            if (dangerDir[0] == UP) {
                safePosition = RIGHT;
            } else if (dangerDir[0] == DOWN) {
                safePosition = LEFT;
            } else if (dangerDir[0] == LEFT) {
                safePosition = UP;
            } else if (dangerDir[0] == RIGHT) {
                safePosition = DOWN;
            }
        } else {
            safePosition = NULL_DIR;
        }
        this->moveEscape(colliders, possiblePositions, safePosition);
    }

    void AI::intermediateAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions)
    {
        MoveDir dir = NULL_DIR;

        std::vector<std::tuple<int, ECS::Systems::Collider>> danger = this->IsAISafe(colliders);
        if (danger.size() <= 0) {
            // std::cout << "\n\n\n\n\ndanger : " << danger.size() << "bombs sizes : " << this->bombs.size() <<  std::endl;
            if (this->bombs.size() == 0) {
                this->goPlaceBomb(colliders, mapBombs, possiblePositions);
            }
        } else {
            std::vector<MoveDir> dangerDir;
            for (int i = 0; i < danger.size(); i++) {
                dangerDir.push_back(static_cast<MoveDir>(std::get<0>(danger[i])));
            }
            // std::cout << "\n\n\n\n\ntryEscapeFromBomb : " << dangerDir.size() << std::endl;
            this->tryEscapeFromBomb(colliders, possiblePositions, dangerDir);
        }
    }
}

