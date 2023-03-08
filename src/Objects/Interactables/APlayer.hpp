/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** APlayer
*/

#ifndef APLAYER_HPP_
    #define APLAYER_HPP_
    #include "../Objects_namespace.hpp"
    #include "DestroyableWall.hpp"
    #include "../UI/PlayerInfo.hpp"
    #include "Bomb.hpp"

class Indie::Objects::Interactables::APlayer :
public Indie::ECS::Components::Model3D,
public Indie::ECS::Systems::Movable3D {
    private:
        std::shared_ptr<PlayerInfo> playerInfo = nullptr;
        std::unique_ptr<Lib::Audio::MySound> deathSfx;

    public:
    // Constructor / Destructor
        APlayer(int playerId, Vector3 pos, std::string modelPath);
        ~APlayer();

    // Useful functions
        void init();
        virtual void init(std::vector<std::tuple<int, std::shared_ptr<Vector3>>> PlayersPositions, std::vector<std::shared_ptr<Interactables::APlayer>> players);
        void update();
        void updateAnimation();
        void placeBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& bombs);
        void placeBomb(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& mapBombs, Vector3 bombPos);
        virtual void update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::Bomb>>& bombs) = 0;
        virtual void updateMovement(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders) = 0;
        bool checkCollision(Lib::Shapes::MyRectangle currentCollider, Lib::Shapes::MyRectangle nextCollider, std::shared_ptr<ECS::Systems::Collider>& collider);
        bool checkCollisions(Vector3 pos, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        bool checkCollisionsBreakable(Vector3 pos, std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders);
        void kill();
        void checkPowerUps(std::vector<std::shared_ptr<DestroyableWall>>& destroyableWalls);

    // Getter / Setter
        void setPlayerInfo(std::shared_ptr<PlayerInfo> info);
        bool getIsDead() const;
        void setBombRange(int newRange);
        int getBombRange(void) const;
        void setSpeed(float newSpeed);
        float getSpeed(void) const;
        void setMaxNbBombs(int newMaxNbBombs);
        int getMaxNbBombs(void) const;
        Lib::Shapes::MyRectangle getRectangle(void) const;
        std::shared_ptr<Vector3> getmovPos();
        int getPlayerId();
        void setRot(Vector3 newRot);
        Vector3 getRot() const;
        bool getIsAI();
        bool checkBombCollision(Vector3 bombPos, int range);
        void setWinner();
        std::shared_ptr<Vector3> getPos();

    protected:
        int playerId;
        Lib::MyEvent event;
        std::vector<std::shared_ptr<Bomb>> bombs;
        float speed;
        float colliderOffset;
        bool isDead;
        bool deadAnim;
        int bombRange;
        int maxNbBombs;
        bool _isAI;
        bool isMoving;
        bool isWinner;
        int lastAnim;
        std::vector<std::shared_ptr<Interactables::APlayer>> _Players;

};

#endif /* !APLAYER_HPP_ */
