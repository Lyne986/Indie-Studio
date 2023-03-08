/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** AI_pathFinding
*/

#include <cmath>
#include "AI.hpp"
#include <tuple>
#include <fstream>

namespace Indie::Objects::Interactables {

    bool AI::CheckIfAvalaibleBlock(map_data curr, map_data next, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {

        float offset = this->colliderOffset;
        float currx = curr.x;
        float curry = curr.y;
        Lib::Shapes::MyRectangle currentCollider(currx + offset, curry + offset, 1 - offset * 2, 1 - offset * 2);
        float posx = next.x;
        float posz = next.y;
        Vector3 pos = {posx, this->pos->y, posz};

        for (int j = 0; j < colliders.size(); j++) {

            Lib::Shapes::MyRectangle nextCollider(pos.x + offset, pos.z + offset, 1 - offset * 2, 1 - offset * 2);

            if (this->checkCollision(currentCollider, nextCollider, colliders[j]))
                return false;
        }
        return (true);
    }

    int AI::GetNeighP(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y) {

        int path = 0;

        if (x != 0 && array[y][x - 1].chr == 'P')
            path += 1;
        if (y != 0 && array[y - 1][x].chr == 'P')
            path += 1;
        if (x != mapw - 1 && array[y][x + 1].chr == 'P')
            path += 1;
        if (y != maph - 1 && array[y + 1][x].chr == 'P')
            path += 1;

        // std::cout << "path nb : " << std::to_string(path) << std::endl;
        // exit(1);
        return (path);
    }

    int AI::GetNeighNbr(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y) {

        int neighbours = 0;
        map_data curr = array[y][x];

        if (y != maph -1 && array[y + 1][x].chr != 'P' && array[y + 1][x].chr != 'K' && CheckIfAvalaibleBlock(curr, array[y + 1][x], colliders)) {
            neighbours += 1;
            if (array[y + 1][x].chr == 'G')
                array[y + 1][x].chr = '*';
            else
                array[y + 1][x].chr = array[y + 1][x].chr == 'X' ? '*' : array[y + 1][x].chr;
        }
        if (x != mapw - 1 && array[y][x + 1].chr != 'P' && array[y][x + 1].chr != 'K' && CheckIfAvalaibleBlock(curr, array[y][x + 1], colliders)) {
            neighbours += 1;
            if (array[y][x + 1].chr == 'G')
                array[y][x + 1].chr = '*';
            else
                array[y][x + 1].chr = array[y][x + 1].chr == 'X' ? '*' : array[y][x + 1].chr;
        }
        if (y != 0 && array[y - 1][x].chr != 'P' && array[y - 1][x].chr != 'K' && CheckIfAvalaibleBlock(curr, array[y - 1][x], colliders)) {
            neighbours += 1;
            if (array[y - 1][x].chr == 'G')
                array[y - 1][x].chr = '*';
            else
                array[y - 1][x].chr = array[y - 1][x].chr == 'X' ? '*' : array[y - 1][x].chr;
        }
        if (x != 0 && array[y][x - 1].chr != 'P' && array[y][x - 1].chr != 'K' && CheckIfAvalaibleBlock(curr, array[y][x - 1], colliders)) {
            neighbours += 1;
            if (array[y][x - 1].chr == 'G')
                array[y][x - 1].chr = '*';
            else
                array[y][x - 1].chr = array[y][x - 1].chr == 'X' ? '*' : array[y][x - 1].chr;
        }
        // std::cout << "neighbours nb : " << std::to_string(neighbours) << std::endl;

        return (neighbours);
    }

    void AI::SetAvalaiblePaths(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {

        if (this->_y < maph - 1 && array[this->_y + 1][this->_x].chr == '*') {
            this->_y++;
            array[this->_y][this->_x].chr = 'P';
            return;
        }
        if (this->_x < mapw - 1 && array[this->_y][this->_x + 1].chr == '*') {
            this->_x++;
            array[this->_y][this->_x].chr = 'P';
            return;
        }
        if (this->_x != 0 && array[this->_y][this->_x - 1].chr == '*') {
            this->_x--;
            array[this->_y][this->_x].chr = 'P';
            return;
        }
        if (this->_y != 0 && array[this->_y - 1][this->_x].chr == '*') {
            this->_y--;
            array[this->_y][this->_x].chr = 'P';
            return;
        }
    }

    void AI::ReplaceKOnMap(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y) {

        if (x > 1 && array[y][x - 1].chr == 'K' && array[y][x - 2].chr == '*') {
            array[y][x - 1].chr = 'P';
            this->_x--;
            return;
        }
        if (y > 1 && array[y - 1][x].chr == 'K' && array[y - 2][x].chr == '*') {
            array[y - 1][x].chr = 'P';
            this->_y--;
            return;
        }
        if (x < mapw - 2 && array[y][x + 1].chr == 'K' && array[y][x + 2].chr == '*') {
            array[y][x + 1].chr = 'P';
            this->_x++;
            return;
        }
        if (y < maph - 2 && array[y + 1][x].chr == 'K' && array[y + 2][x].chr == '*') {
            array[y + 1][x].chr = 'P';
            this->_y++;
        }
    }

    int AI::GoBack2FillUselessPaths(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) {
        std::list<std::tuple<int, int>>::iterator it;

        for (it = stack.begin(); it != stack.end() && (GetNeighNbr(colliders, this->_x, this->_y) == 0 || GetNeighP(colliders, this->_x, this->_y) >= 2);it = stack.erase(it)) {
            ReplaceKOnMap(colliders, this->_x, this->_y);
            if (array[std::get<1>(*it)][std::get<0>(*it)].chr != 'X') {
                array[std::get<1>(*it)][std::get<0>(*it)].chr = 'K';
            }
            this->_x = std::get<0>(*it);
            this->_y = std::get<1>(*it);
        };
        return (0);
    }

    int AI::FindPath(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, ECS::Systems::Collider collider) {
        int i = 0;

        if (this->array[this->_y][this->_x].chr == 'X')
            return (0);
        stack.push_front(std::make_tuple(this->_x, this->_y));

        while (true) {

            if (this->_y == _targety && this->_x == _targetx) // Found Target
                return (1);

            if (GetNeighNbr(colliders, this->_x, this->_y) > 0 && GetNeighP(colliders, this->_x, this->_y) < 2) {

                SetAvalaiblePaths(colliders);
                // PrintMap();
                // std::string coordstr = "\nADDING PART THIS X [" + std::to_string(this->_x) +  ", " +  std::to_string(this->_y) +  "]";
                // WriteLogFile(coordstr.c_str());

                stack.push_front(std::make_tuple(this->_x, this->_y));

                if (this->_y == _targety && this->_x == _targetx) // Found Target
                    return (1);

                if (i == 500) // Avoid Infinite Loops
                    return (0);
            } else { // In case of dead end

                if (GoBack2FillUselessPaths(colliders) == -1)
                    return (-1);
            }
            i++; // Variable For Infinite Loops
        }
        return (0);
    }
}