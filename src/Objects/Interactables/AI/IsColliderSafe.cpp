/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** isColliderSafe
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {

    std::vector<ECS::Systems::Collider> AI::IsColliderSafe(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, Vector3 PosToCheck) {
        std::vector<ECS::Systems::Collider> safeColliders; // Etablish vector of dangerous directions
        float offset = this->colliderOffset; // Offset of one collider
        Lib::Shapes::MyRectangle currentCollider(this->pos->x + offset, this->pos->z + offset, 1 - offset * 2, 1 - offset * 2); // Builds current collider from where we start
        Vector3 pos = PosToCheck; // Vector3 representing the position going to be created

        for (int j = 0; j < colliders.size(); j++) {

            Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

            if (!this->checkCollision(currentCollider, nextCollider, colliders[j]))
                continue;
            if (colliders[j]->getTag() == "destroyable" && !colliders[j]->getIsBomb()) {
                safeColliders.push_back(*colliders[j]);
            }
        }
        return (safeColliders);
    }
}