/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** AIUtils
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {
    void AI::oneBlockMove(MoveDir dir) {
        int oneCube = 1 / (this->speed * Lib::MyWindow::getFrameTime());

        this->ancienMovement.push_back(dir);
        for (int i = 0; i < oneCube; i++)
            this->_movement.push_back(dir);
    }

    void AI::updateIaMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, MoveDir dir) {
        Vector3 movement = {0, 0, 0};

        if (dir == UP) {
            movement.z -= speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 180;
        } else if (dir == DOWN) {
            movement.z += speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 0;
        } else if (dir == LEFT) {
            movement.x -= speed * Lib::MyWindow::getFrameTime();
            this->rot->z = -90;
        } else if (dir == RIGHT) {
            movement.x += speed * Lib::MyWindow::getFrameTime();
            this->rot->z = 90;
        }
        Vector3 NextPos = {this->pos->x + movement.x, this->pos->y, this->pos->z + movement.z};
        if (!this->checkCollisions(NextPos, colliders))
            this->move(movement);
        if (this->_movement.size() > 0)
            this->_movement.erase(this->_movement.begin());
    }

    // useless function
    void AI::updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        std::shared_ptr<Vector3> movPos = this->getmovPos();
        Vector3 moveDir = {0, 0, 0};

        // std::cout << "\n\n" << this->getPlayerId() << std::endl;
        // moveDir.z -= speed;
        // this->rot->z = 180;

        Vector3 nextPos = {this->pos->x + moveDir.x, this->pos->y + moveDir.y, this->pos->z + moveDir.z};
        if (!this->checkCollisions(nextPos, colliders)) {
            this->move(moveDir);
        }
    }

    void AI::WriteLogFile(const char* szString) {
        static bool opened = false;
        static FILE *pFile;
        if (!opened) {
            pFile = fopen("playerposlog.txt", "a");
            opened = true;
        }
        fprintf(pFile, "%s\n",szString);
    }

    std::shared_ptr<ECS::Systems::Collider> AI::GetPosCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, Vector3 pos, Lib::Shapes::MyRectangle currentCollider) {

        for (int j = 0; j < colliders.size(); j++) {

            Lib::Shapes::MyRectangle nextCollider(pos.x + this->colliderOffset, pos.z + this->colliderOffset, 1 - this->colliderOffset * 2, 1 - this->colliderOffset * 2);

            if (!this->checkCollision(currentCollider, nextCollider, colliders[j]))
                continue;
            Rectangle rec = colliders[j]->getCollider().getRectangle();

            // std::string str = "\n-----\nCollider n[" + std::to_string(j) + "]\n BOMB= ?" + std::to_string(colliders[j]->getIsBomb()) + "\n TAG= " + colliders[j]->getTag() + "\n Active= " + std::to_string(colliders[j]->getIsActive()) + "\n x :" + std::to_string(rec.x) + "\n y :" + std::to_string(rec.y + 1) + "\n-----\n";
            // WriteLogFile(str.c_str());
            return (colliders[j]);
        }
        return (NULL);
    }
}
