/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MapManager.hpp
*/

#ifndef __MAP_MANAGER_HPP__
    #define __MAP_MANAGER_HPP__

    #include "Objects_namespace.hpp"
    #include "Interactables/DestroyableWall.hpp"
    #include "Interactables/Player.hpp"
    #include "Interactables/AI/AI.hpp"
    #include "UI/PlayerInfo.hpp"
    #include <iostream>

class Indie::Objects::MapManager : public ECS::Components::Map3D {
    private:
        std::unique_ptr<Indie::Lib::MyTexture> background;
        Lib::MyEvent event;
        std::vector<std::string> mapContent;
        std::vector<std::shared_ptr<Interactables::DestroyableWall>> destroyableWalls;
        std::vector<std::shared_ptr<ECS::Systems::Collider>> colliders;
        std::vector<std::shared_ptr<Interactables::Bomb>> bombs;
        std::map<int, Vector3> playerPositions;
        int width, height;
        std::vector<std::shared_ptr<Interactables::APlayer>> players;
        std::map<int, std::shared_ptr<PlayerInfo>> playersInfo;
        void loadMap(std::string mapPath);
        std::map<int, Indie::player_t> _players_info;

    public:
    // Constructor / Destructor
        MapManager(std::string mapPath, std::map<int, Indie::player_t> player_info);
        ~MapManager();

    // Useful functions
        void init();
        void update();
        void drawUnder();
        void drawAll();
        void drawOver();
        int checkStatus();
        void updatePlayerAnimations();

    // Function to fill a vector of all the players positions for the AI
        std::vector<std::tuple<int, std::shared_ptr<Vector3>>> getAllPlayersPositions();

    // Getter / Setter
        Vector3 getStartingPosition(int playerId);
        Vector3 getPlayerPosition(int playerId);
        std::shared_ptr<Interactables::APlayer> getPlayer(std::size_t pid);
        std::vector<std::shared_ptr<ECS::Systems::Collider>> getColliders();
        std::vector<std::shared_ptr<ECS::Systems::Collider>> &getCollidersRef();
        std::shared_ptr<Interactables::DestroyableWall> getDestroyableWall(std::size_t id);
        std::vector<std::shared_ptr<Interactables::DestroyableWall>> getDestroyableWalls();
        std::vector<std::shared_ptr<Interactables::Bomb>> &getBombsRef();
        std::vector<std::shared_ptr<Interactables::Bomb>> getBombs();
};

#endif
