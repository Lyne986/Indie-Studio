/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** mediumAI
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {

    void AI::AvoidDanger(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::tuple<int, ECS::Systems::Collider>> ways) {

    }

    int AI::WalkToCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, ECS::Systems::Collider collider) {
        if (this->getPlayerId() != 4)
            return 0;
        Rectangle rec = collider.getCollider().getRectangle();
        int roundColliderposx = std::round(rec.x);
        int roundColliderposy = std::round(rec.y);
        int roundPlayerposx = std::round(this->pos->x);
        int roundPlayerposy = std::round(this->pos->z);
        int PlayerXinArray = 0;
        int PlayerYinArray = 0;
        float offset = this->colliderOffset;
        std::vector<map_data> infos;

        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 17; j++) {
                map_data data = {UNKNOWN, j - 8, i - 5, '?'};
                if (data.y == roundPlayerposy && data.x == roundPlayerposx) {
                    data.chr = 'P';
                    data.status = ACCESSIBLE;
                    this->_x = j;
                    this->_y = i;
                    PlayerXinArray = j;
                    PlayerYinArray = i;
                } else if (data.y == roundColliderposy && data.x == roundColliderposx) {
                    data.chr = 'G';
                    _targetx = j;
                    _targety = i;
                } else
                    data.chr = 'X';
                infos.push_back(data);
            }
            array.push_back(infos);
            infos.clear();
        }
        mapw = 17;
        maph = 11;
        int res = FindPath(colliders, collider);
        if (!res)
            return 0;
        std::list<std::tuple<int, int>>::iterator it;
        std::string restr = "";
        int index = 0;
        stack.reverse();
        int temp_x = this->pos->x;
        int temp_z = this->pos->z;
        for (it = stack.begin(); it != stack.end(); it++, index++) {
            int pos_x = array[std::get<1>(*it)][std::get<0>(*it)].x;
            int pos_y = array[std::get<1>(*it)][std::get<0>(*it)].y;
            if (temp_x < pos_x) {
                oneBlockMove(RIGHT);
                temp_x += 1;
            }
            if (temp_x > pos_x) {
                oneBlockMove(LEFT);
                temp_x -= 1;
            }
            if (temp_z < pos_y) {
                oneBlockMove(DOWN);
                temp_z += 1;
            }
            if (temp_z > pos_y) {
                oneBlockMove(UP);
                temp_z -= 1;
            }
            restr = "this X = " + std::to_string(this->pos->x) + " this Z = " + std::to_string(this->pos->z) + "\nINDEX [" + std::to_string(index) + "]\n coords [" + std::to_string(array[std::get<1>(*it)][std::get<0>(*it)].x) + "," + std::to_string(array[std::get<1>(*it)][std::get<0>(*it)].y) + "]\n";
            WriteLogFile(restr.c_str());
        }
        return (1);
    }

    void AI::PrintMap() {
        std::string posstr = "";
        for (int i = 0; i < array.size(); i++) {
            std::vector<map_data> infos = array[i];
            for (int j = 0; j < infos.size(); j++) {
                posstr += infos[j].chr;
                // posstr += "[" + std::to_string(array[i][j].x) + "," + std::to_string(array[i][j].y) + "]";
            }
            posstr += "\n";
        }
        posstr += "\n";
        // posstr += "x [" + std::to_string(roundPlayerposx) + "," + std::to_string(roundPlayerposy) + "]";
        WriteLogFile(posstr.c_str());
    }

    void AI::printAllColliders(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        for (int i = 0; i < colliders.size(); i++) {
            Rectangle rec = colliders[i]->getCollider().getRectangle();
                std::string str = "\n-----\nCollider n[" + std::to_string(i) + "]\n BOMB= ?" + std::to_string(colliders[i]->getIsBomb()) + "\n TAG= " + colliders[i]->getTag() + "\n Active= " + std::to_string(colliders[i]->getIsActive()) + "\n\n x -> " + std::to_string(rec.x) + "\n y -> " + std::to_string(rec.y) + "\n-----\n";
                WriteLogFile(str.c_str());
            // if (colliders[i]->getIsBomb()) {
            //     std::string str = "\n-----\nCollider n[" + std::to_string(i) + "]\n BOMB= ?" + std::to_string(colliders[i]->getIsBomb()) + "\n TAG= " + colliders[i]->getTag() + "\n Active= " + std::to_string(colliders[i]->getIsActive()) + "\n\n x -> " + std::to_string(rec.x) + "\n y -> " + std::to_string(rec.y) + "\n-----\n";
            //     WriteLogFile(str.c_str());
            // }
        }
    }

    void AI::mediumAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions) {
        bool DEBUG_WAYZZ = false;

        std::vector<std::tuple<int, ECS::Systems::Collider>> ways = IsAISafe(colliders);

        if (ways.size() > 0) {
            AvoidDanger(colliders, ways);
        } else {
            // goPlaceBomb();
        }
        // std::vector<std::shared_ptr<Interactables::APlayer>> NearestPlayer = FindNearetPlayerCollider(colliders);

        if (DEBUG_WAYZZ == true) {
            // Prints in playerlogpos.txt all the dangerous directions !
            for (int i = 0; i < ways.size(); i++) {
                std::string wayze_str = "\n-----------BEGIN IA N[" + std::to_string(this->getPlayerId()) +"]-----------\n";
                if (std::get<0>(ways[i]) == LEFT) 
                    wayze_str += "LEFT\n";
                else if (std::get<0>(ways[i]) == RIGHT)
                    wayze_str += "RIGHT\n";
                else if (std::get<0>(ways[i]) == UP)
                    wayze_str += "UP\n";
                else if (std::get<0>(ways[i]) == DOWN)
                    wayze_str += "DOWN\n";
                wayze_str += "-----------------END-----------------\n";
                WriteLogFile(wayze_str.c_str());
            }
        }
    }
}
