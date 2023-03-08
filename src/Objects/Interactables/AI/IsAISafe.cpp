/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** IsAISafe
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {

    std::vector<std::tuple<int, ECS::Systems::Collider>> AI::IsAISafe(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        std::vector<std::tuple<int, ECS::Systems::Collider>> dangerousDir; // Etablish vector of dangerous directions
        std::vector<bool> uselessdangerousDir = {false, false, false, false}; // Etablish vector containing status of the useless dirs
        std::vector<std::tuple<int, Vector3>> possiblePositions; // Vector of tuples containing all possibles blocks that might contain bombs
        float offset = this->colliderOffset; // Offset of one collider
        Lib::Shapes::MyRectangle currentCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2); // Builds current collider from where we start
        int dir = 0; // Int representing the direction we are going to check
        Vector3 pos = {}; // Vector3 representing the position going to be created

        // Fill possiblePositions vector with 4 directions possible positions !
        for (int i = 0; i < 20; i++) {
            pos = {this->pos->x, this->pos->y, this->pos->z + i};
            possiblePositions.push_back(std::make_tuple(DOWN, pos));
            pos = {this->pos->x, this->pos->y, this->pos->z - i};
            possiblePositions.push_back(std::make_tuple(UP, pos));
            pos = {this->pos->x - i, this->pos->y, this->pos->z};
            possiblePositions.push_back(std::make_tuple(LEFT, pos));
            pos = {this->pos->x + i, this->pos->y, this->pos->z};
            possiblePositions.push_back(std::make_tuple(RIGHT, pos));
        }

        // For each positions check if there is Bomb or a wall (undestructible one)
        // if it is bomb add RIGHT LEFT UP DOWN direction to the dangerousDir vector
        // if it isn't already inside the vector
        // if it is a wall break and go check the next positions !
        // then returns the vector of directions
        for (int i = 0; i < possiblePositions.size(); i++) {

            dir = std::get<0>(possiblePositions[i]);
            if (uselessdangerousDir[dir] == true)
                continue;

            for (int j = 0; j < colliders.size(); j++) {

                pos = std::get<1>(possiblePositions[i]);
                Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

                if (!this->checkCollision(currentCollider, nextCollider, colliders[j]))
                    continue;

                if (colliders[j]->getIsBomb() == true) {

                    std::vector<std::tuple<int, ECS::Systems::Collider>>::iterator it = std::find_if(dangerousDir.begin(), dangerousDir.end(), [&](const std::tuple<int, ECS::Systems::Collider> &tuple) {
                        return (std::get<0>(tuple) == dir);
                    });

                    if (it == dangerousDir.end()) {
                        dangerousDir.push_back(std::tuple<int, ECS::Systems::Collider>(dir, *colliders[j]));
                    }
                    uselessdangerousDir[dir] = false;

                } else if (colliders[j]->getTag() == "wall" || (colliders[j]->getTag() == "destroyable" && !colliders[j]->getIsBomb())) {
                    uselessdangerousDir[dir] = true;
                    break;
                }
            }
        }
        return (dangerousDir);
    }
}
