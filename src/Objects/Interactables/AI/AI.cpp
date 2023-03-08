/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** AI
*/

#include <cmath>
#include "AI.hpp"
#include <tuple>

namespace Indie::Objects::Interactables {
    AI::AI(int playerId, Vector3 pos, IA_TYPE iaType, std::string modelPath) :
    APlayer(playerId, pos, modelPath) {
        this->_isAI = true;
        this->iaType = iaType;
        this->hide = false;
        this->wait = false;
    }

    AI::~AI() {}

    void AI::init(std::vector<std::tuple<int, std::shared_ptr<Vector3>>> PlayersPositions, std::vector<std::shared_ptr<Interactables::APlayer>> players) {
        this->_PlayersPositions = PlayersPositions;
        this->_Players = players;
    }

    // function that pass into different type of IA
    void AI::update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs) {
        std::vector<Vector3> possiblePositions;
        possiblePositions.push_back({this->pos->x, this->pos->y, this->pos->z - 0.5f});
        possiblePositions.push_back({this->pos->x, this->pos->y, this->pos->z + 0.5f});
        possiblePositions.push_back({this->pos->x - 0.5f, this->pos->y, this->pos->z});
        possiblePositions.push_back({this->pos->x + 0.5f, this->pos->y, this->pos->z});

        if (this->_movement.size() <= 0) {
            if (this->iaType == 0) {
                this->easyAI(colliders, mapBombs, possiblePositions);
            } else if (this->iaType == 1) {
                this->intermediateAI(colliders, mapBombs, possiblePositions);
            } else if (this->iaType == 2) {
                this->intermediateAI(colliders, mapBombs, possiblePositions);
            }
        }
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
        if (this->_movement.size() > 0) {
            this->updateIaMovement(colliders, this->_movement[0]);
        }
    }
}
