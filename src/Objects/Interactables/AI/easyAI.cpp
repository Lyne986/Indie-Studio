/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** easyAI
*/

#include <cmath>
#include "AI.hpp"
#include <tuple>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace Indie::Objects::Interactables {
    Indie::Objects::Interactables::AI::MoveDir AI::basicMove(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, MoveDir dir, std::vector<Vector3> possiblePositions) {
        std::vector<MoveDir> possibleDirs;
        if (!this->checkCollisions(possiblePositions[0], colliders))
            possibleDirs.push_back(UP);
        if (!this->checkCollisions(possiblePositions[1], colliders))
            possibleDirs.push_back(DOWN);
        if (!this->checkCollisions(possiblePositions[3], colliders))
            possibleDirs.push_back(RIGHT);
        if (!this->checkCollisions(possiblePositions[2], colliders))
            possibleDirs.push_back(LEFT);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(possibleDirs.begin(), possibleDirs.end(), g);
        dir = possibleDirs[0];
        return dir;
    }

    void AI::bombeAndEscape(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs) {
        this->placeBomb(colliders, mapBombs);
        if (this->ancienMovement.back() == UP) {
            this->oneBlockMove(DOWN);
        } else if (this->ancienMovement.back() == DOWN) {
            this->oneBlockMove(UP);
        } else if (this->ancienMovement.back() == LEFT) {
            this->oneBlockMove(RIGHT);
        } else if (this->ancienMovement.back() == RIGHT) {
            this->oneBlockMove(LEFT);
        }
        this->hide = true;
    }

    void AI::touchDestructibleCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions) {
        if (this->checkCollisionsBreakable(possiblePositions[0], colliders)) {
            this->bombeAndEscape(colliders, mapBombs);
        } else if (this->checkCollisionsBreakable(possiblePositions[1], colliders)) {
            this->bombeAndEscape(colliders, mapBombs);
        } else if (this->checkCollisionsBreakable(possiblePositions[2], colliders)) {
            this->bombeAndEscape(colliders, mapBombs);
        } else if (this->checkCollisionsBreakable(possiblePositions[3], colliders)) {
            this->bombeAndEscape(colliders, mapBombs);
        }
    }

    void AI::easyAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions) {
        MoveDir dir = NULL_DIR;

        if (this->bombs.size() == 0) {
            this->hide = false;
            this->wait = false;
        }
        if (this->wait) return;

        this->touchDestructibleCollider(colliders, mapBombs, possiblePositions);
        if (!this->hide) {
            dir = this->basicMove(colliders, dir, possiblePositions);
        } else {
            if (!this->checkCollisions(possiblePositions[3], colliders) && (this->ancienMovement.back() == UP || this->ancienMovement.back() == DOWN)) {
                dir = RIGHT;
            } else if (!this->checkCollisions(possiblePositions[2], colliders) && (this->ancienMovement.back() == UP || this->ancienMovement.back() == DOWN)) {
                dir = LEFT;
            } else if (!this->checkCollisions(possiblePositions[0], colliders) && (this->ancienMovement.back() == RIGHT || this->ancienMovement.back() == LEFT)) {
                dir = UP;
            } else if (!this->checkCollisions(possiblePositions[1], colliders) && (this->ancienMovement.back() == RIGHT || this->ancienMovement.back() == LEFT)) {
                dir = DOWN;
            } else {
                this->oneBlockMove(this->ancienMovement.back());
                return;
            }
            if (dir != NULL_DIR)
                this->wait = true;
        }
        if (dir == NULL_DIR) return;
        this->oneBlockMove(dir);
    }
}
