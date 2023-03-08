/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Player.hpp
*/

#ifndef __PLAYER_HPP__
    #define __PLAYER_HPP__

    #include "../Objects_namespace.hpp"
    #include "DestroyableWall.hpp"
    #include "Bomb.hpp"
    #include "APlayer.hpp"

class Indie::Objects::Interactables::Player :
public Indie::Objects::Interactables::APlayer {
    private:
        std::unique_ptr<Bomb> bomb;
        Lib::MyEvent event;
        int controllerId;
        Vector3 getKeyboardMovement();
        Vector3 getGamepadMovement();

    public:
    // Constructor / Destructor
        Player(int playerId, Vector3 pos, int controllerId, std::string modelPath);
        ~Player();

        void update();
        void update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& bombs);
        void updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
};

#endif
