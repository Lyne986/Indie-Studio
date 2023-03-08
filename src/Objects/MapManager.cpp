/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MapManager.cpp
*/

#include "MapManager.hpp"

namespace Indie::Objects {
    MapManager::MapManager(std::string mapPath, std::map<int, Indie::player_t> player_info) :
    Map3D(mapPath, {0, 0, 0}, 1, {0, 0, 0}) {
        this->background = std::make_unique<Lib::MyTexture>(mapPath + "_background.png");
        *this->pos = {-9.0f, 0.0f, -6.0f};
        this->_players_info = player_info;
        this->loadMap(mapPath);

        std::map<int, Indie::player_t>::iterator it;
        this->_players_info = player_info;
        for (it = this->_players_info.begin(); it != this->_players_info.end(); it++) {
            if (it->second.type == PLAYER) {
                players.push_back((std::make_shared<Interactables::Player>(it->first, this->playerPositions[it->first], it->second.controller_id, it->second.model)));
                this->playersInfo[it->first] = std::make_shared<PlayerInfo>(it->first, false);
            } else if (it->second.type == AI) {
                players.push_back((std::make_shared<Interactables::AI>(it->first, this->playerPositions[it->first], it->second.ia_type, it->second.model)));
                this->playersInfo[it->first] = std::make_shared<PlayerInfo>(it->first, true);
            }
        }
        for (int i = 0; i != players.size(); i++) {
            if (players[i]->getIsAI())
                players[i]->init(this->getAllPlayersPositions(), players);
            this->players[i]->setPlayerInfo(this->playersInfo[this->players[i]->getPlayerId()]);
        }
    }

    void MapManager::loadMap(std::string mapPath)
    {
        Utils::FileManager fileManager(mapPath + ".txt");

        this->mapContent = fileManager.splitByDelim(fileManager.getContent(), '\n');
        this->width = this->mapContent[0].size();
        this->height = this->mapContent.size();

        for (float y = this->pos->z, i = 0; i < this->height; y++, i++) {
            for (float x = this->pos->x, j = 0; j < this->width; x++, j++) {
                char c = this->mapContent[i][j];
                if (c == 'x') {
                    auto wall = std::make_shared<ECS::Systems::Collider>(x, y, 1.0f, 1.0f, "wall");
                    this->colliders.push_back(wall);
                } else if (c == 'd') {
                    Vector3 pos = {x, 0.5f, y};
                    auto destroyableWall = std::make_shared<Interactables::DestroyableWall>(mapPath + "_d_texture.png", pos);
                    this->colliders.push_back(destroyableWall);
                    this->destroyableWalls.push_back(destroyableWall);
                } else if (c == 'P') {
                    Vector3 pos = {x, 0.5f, y};
                    auto destroyableWall = std::make_shared<Interactables::DestroyableWall>(mapPath + "_d_texture.png", pos);
                    this->colliders.push_back(destroyableWall);
                    this->colliders[this->colliders.size() - 1]->setIsActive(false);
                    this->destroyableWalls.push_back(destroyableWall);
                } else if (std::isdigit(c)) {
                    Vector3 pos = {x, 0.0f, y};
                    this->playerPositions[c - '0'] = pos;
                }
            }
        }
    }

    void MapManager::drawUnder()
    {
        Vector2 pos = {0, 0};
        this->background->draw(pos);
    }

    void MapManager::drawAll() {
        this->draw();
        for (auto destroyableWall : destroyableWalls) {
            destroyableWall->draw();
        }
        for (int i = 0; i != players.size(); i++) {
            if (players[i]) {
                players[i]->draw();
            }
        }
        for (int i = 0; i < this->bombs.size(); i++) {
            if (this->bombs[i]->getIsActive()) {
                this->bombs[i]->draw();
            }
        }
    }

    std::shared_ptr<Interactables::APlayer> MapManager::getPlayer(std::size_t pid)
    {
        if (pid < this->players.size()) {
            return (this->players[pid]);
        }
        return (nullptr);
    }

    void MapManager::drawOver()
    {
        for (int i = 0; i < this->bombs.size(); i++) {
            this->bombs[i]->drawEffects();
        }
        for (auto it = this->playersInfo.begin(); it != this->playersInfo.end(); it++) {
            this->playersInfo[it->first]->draw();
        }
    }

    Vector3 MapManager::getStartingPosition(int playerId)
    {
        return this->playerPositions[playerId];
    }

    Vector3 MapManager::getPlayerPosition(int playerId)
    {
        Vector3 defaultPos = {0, 0, 0};

        for (int i = 0; i < this->players.size(); i++) {
            if (this->players[i] && this->players[i]->getPlayerId()) {
                return this->players[i]->getPosition();
            }
        }
        return defaultPos;
    }

    MapManager::~MapManager() {}

    std::vector<std::tuple<int, std::shared_ptr<Vector3>>> MapManager::getAllPlayersPositions() {
        std::vector<std::tuple<int, std::shared_ptr<Vector3>>> allPlayersPositions;
        for (int i = 0; i < players.size(); i++) {
            if (players[i]) {
                allPlayersPositions.push_back(std::tuple<int, std::shared_ptr<Vector3>>(players[i]->getPlayerId(), players[i]->getmovPos()));
            }
        }
        return allPlayersPositions;
    }

    std::vector<std::shared_ptr<ECS::Systems::Collider>> MapManager::getColliders()
    {
        return (this->colliders);
    }

    void MapManager::init() {}

    std::vector<std::shared_ptr<Interactables::DestroyableWall>> MapManager::getDestroyableWalls()
    {
        return (this->destroyableWalls);
    }

    std::vector<std::shared_ptr<ECS::Systems::Collider>> &MapManager::getCollidersRef()
    {
        return (this->colliders);
    }

    std::shared_ptr<Interactables::DestroyableWall> MapManager::getDestroyableWall(std::size_t id)
    {
        if (id < this->destroyableWalls.size())
            return (this->destroyableWalls[id]);
        return (nullptr);
    }

    std::vector<std::shared_ptr<Interactables::Bomb>> &MapManager::getBombsRef()
    {
        return (this->bombs);
    } 

    void MapManager::update()
    {
        for (int i = 0; i < players.size(); i++) {
            if (players[i] && players[i]->getIsDead()) {
                players[i] = nullptr;
            }
            if (players[i]) {
                players[i]->update(this->colliders, this->bombs);
                players[i]->checkPowerUps(this->destroyableWalls);
            }
        }

        for (int i = 0; i < this->bombs.size(); i++) {
            this->bombs[i]->update(this->colliders, this->players);
        }
    }

    void MapManager::updatePlayerAnimations()
    {
        for (int i = 0; i < players.size(); i++) {
            if (players[i]) {
                players[i]->updateAnimation();
            }
        }
    }

    int MapManager::checkStatus()
    {
        int id = -1;
        int winIndex = 0;
        int deadPlayers = 0;

        for (int i = 0; i < this->players.size(); i++) {
            if (this->players[i]) {
                if (id != -1) {
                    return -1;
                }
                winIndex = i;
                id = this->players[i]->getPlayerId();
            } else {
                deadPlayers++;
            }
        }
        if (deadPlayers == this->players.size()) {
            return 0;
        }
        if (id > 0) {
            this->players[winIndex]->setWinner();
        }
        return id;
    }

    std::vector<std::shared_ptr<Interactables::Bomb>> MapManager::getBombs() {
        return this->bombs;
    }
}
