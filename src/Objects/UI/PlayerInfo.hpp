/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PlayerInfo.hpp
*/


#ifndef __PLAYER_INFO_HPP__
    #define __PLAYER_INFO_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::PlayerInfo :
public Indie::ECS::Systems::Object2D,
public Indie::ECS::Systems::Drawable {
    private:
        std::unique_ptr<Indie::Lib::MyTexture> playerPortrait = nullptr;
        std::unique_ptr<Indie::Lib::MyTexture> boxContainer = nullptr;
        std::unique_ptr<Indie::Lib::MyText> idText = nullptr;
        std::vector<std::unique_ptr<Indie::Lib::MyTexture>> icons;
        std::vector<std::unique_ptr<Indie::Lib::MyText>> iconsText;
        Vector2 idTextPos;
        Vector2 infoPos;
        int speedIncrease;

    public:
        PlayerInfo(int playerId, bool isAI);
        ~PlayerInfo();
        void init();
        void update();
        void draw() const;
        void killPlayer();
        void increaseSpeed();
        void increaseRange(int newRange);
        void increaseBombs(int newMaxNb);
};

#endif
