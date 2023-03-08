/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** FindNearetPlayerCollider
*/

#include "AI.hpp"

namespace Indie::Objects::Interactables {

    std::shared_ptr<Interactables::APlayer> AI::FindNearetPlayerCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        int NearestPlayer = 0;
        std::shared_ptr<Vector3> CurrentPlayer = {};
        std::shared_ptr<Vector3> NextPlayer = {};

        for (int i = 0; i < _Players.size() - 1; i++) {
            if (i + 1 ==  _Players.size())
                break;
            if (_Players[i]->getPlayerId() == this->getPlayerId() || _Players[i + 1]->getPlayerId() == this->getPlayerId())
                continue;
            // x1 = 10;
            // x2 = 1;
            // x3 = 4;
            // 10 - 4 = 6
            // 10 - 1 = 9
            // 10 - - 4 = 14
            // -4 - 10 = -14
            // 10 - - 1 =  11
            // -1 - 10  =  -11
            CurrentPlayer = _Players[i]->getPos();
            NextPlayer = _Players[i + 1]->getPos();
            int calc_current = CurrentPlayer->x - this->pos->x - CurrentPlayer->y - this->pos->y - CurrentPlayer->z - this->pos->z;
            int calc_next = NextPlayer->x - this->pos->x - NextPlayer->y - this->pos->y - NextPlayer->z - this->pos->z;
            if (calc_current > calc_next)
                NearestPlayer = _Players[i]->getPlayerId();
            else
                NearestPlayer = _Players[i + 1]->getPlayerId();
        }
        std::string str = "\n\n\nAS AI :" + std::to_string(this->getPlayerId()) + "NEAREST PLAYER IS :" + std::to_string(NearestPlayer) + "\n\n\n";

        std::cout << str << std::endl;
        WriteLogFile(str.c_str());
        return _Players[NearestPlayer];
    }

}