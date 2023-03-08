/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Bomb.hpp
*/

#ifndef __BOMB_HPP__
    #define __BOMB_HPP__

    #include "../Objects_namespace.hpp"
    #include "DestroyableWall.hpp"
    #include <chrono>
    #include <cmath>

class Indie::Objects::Interactables::Bomb : public ECS::Components::ADestroyable {
    private:
        std::chrono::steady_clock::time_point timer;
        bool hasExploded;
        int range;
        int secondsLeft;

        typedef enum {
            NONE,
            LEFT,
            RIGHT,
            UP,
            DOWN
        } Dir;

        std::unique_ptr<Lib::Audio::MySound> placeSfx;
        std::unique_ptr<Lib::Audio::MySound> explodeSfx;
        std::vector<std::unique_ptr<ECS::Components::Effect>> bombEffects;
        void createEffects(std::map<Dir, std::vector<std::shared_ptr<ECS::Systems::Collider>>>& bombColliders);
        void createEffect(Dir dir, int r, std::map<Dir, std::vector<std::shared_ptr<ECS::Systems::Collider>>>& bombColliders);

    public:
    // Constructor / Destructor
        Bomb(Vector3 pos, int range);
        ~Bomb();

    // Useful functions
        void drawEffects() const;
        void update(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::APlayer>>& players);
        void explode(std::vector<std::shared_ptr<ECS::Systems::Collider>>& colliders, std::vector<std::shared_ptr<Interactables::APlayer>>& players);
        static Dir checkCollision(Vector3 bombPos, float x, float y, int range);
        bool checkCollisionPriority(Rectangle firstCollider, Rectangle collider, Dir collisionDir);
        bool checkEqualCollision(Rectangle firstCollider, Rectangle collider, Dir collisionDir);

    // Getter / Setter
        bool getHasExploded();
        void pauseBomb();
        void resumeBomb();
        int getRange() const;
};

#endif
