/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** AI
*/

#ifndef AI_HPP_
    #define AI_HPP_

    #include "../APlayer.hpp"
    #include "../../Objects_namespace.hpp"
    #include "../DestroyableWall.hpp"
    #include "../Bomb.hpp"
    #include <list>
    #include <algorithm>
    #include <tuple>
    #include <fstream>
    #include <cmath>
    #include <memory>

class Indie::Objects::Interactables::AI :
public Indie::Objects::Interactables::APlayer {
    private:
        enum MoveDir {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            NULL_DIR
        };
    // PATH FINDING VARIABLES
        struct map_data {
            int status;
            int x;
            int y;
            char chr;
        };
        enum PATHS {BLOCKED, ACCESSIBLE, PREV, UNKNOWN};
        int _x;
        int _y;
        int _targetx;
        int _targety;
        int maph;
        int mapw;
        std::list<std::tuple<int, int>> stack;
        std::vector<std::vector<map_data>> array;
    // END PATH FINDING VARIABLES //
        IA_TYPE iaType;
        bool wait;
        bool hide;
        std::vector<MoveDir> _movement;
        std::vector<std::tuple<int, std::shared_ptr<Vector3>>> _PlayersPositions;
        std::vector<MoveDir> ancienMovement;
    public:
        AI(int playerId, Vector3 pos, IA_TYPE iaType, std::string modelPath);
        ~AI();
        void init(std::vector<std::tuple<int, std::shared_ptr<Vector3>>> PlayersPositions, std::vector<std::shared_ptr<Interactables::APlayer>> players);
        void updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        void update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& bombs);
        void oneBlockMove(MoveDir dir);
        void updateIaMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, MoveDir coordinate);
        void touchDestructibleCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions);
        void goPlaceBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions);
        void bombeAndEscape(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs);
        MoveDir basicMove(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, MoveDir dir, std::vector<Vector3> possiblePositions);
        void moveEscape(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<Vector3> possiblePositions, MoveDir dir);
        void tryEscapeFromBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<Vector3> possiblePositions, std::vector<MoveDir> dangerDir);
        void easyAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions);
        void intermediateAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions);
        void mediumAI(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, std::vector<Vector3> possiblePositions);
        void WalkToCollider(ECS::Systems::Collider collider);
        std::vector<std::tuple<int, ECS::Systems::Collider>> IsAISafe(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        void AvoidDanger(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::tuple<int, ECS::Systems::Collider>> ways);
        void printAllColliders(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        int WalkToCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, ECS::Systems::Collider collider);

        int FindPath(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, ECS::Systems::Collider collider);
        int GetNeighNbr(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y);
        int GetNeighP(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y);
        void SetAvalaiblePaths(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        void ReplaceKOnMap(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, int x, int y);
        int GoBack2FillUselessPaths(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        bool CheckIfAvalaibleBlock(map_data curr, map_data array, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        void PrintMap();
        void WriteLogFile(const char* szString);
        std::vector<ECS::Systems::Collider> IsColliderSafe(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, Vector3 PosToCheck);
        std::shared_ptr<ECS::Systems::Collider> GetPosCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, Vector3 pos, Lib::Shapes::MyRectangle currentCollider);
        std::shared_ptr<Interactables::APlayer> FindNearetPlayerCollider(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
};

#endif /* !AI_HPP_ */
