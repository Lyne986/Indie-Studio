/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PlayerInfo.cpp
*/

#include "PlayerInfo.hpp"

namespace Indie::Objects {
    PlayerInfo::PlayerInfo(int playerId, bool isAI) :
    Object2D({0, 0}, {1, 1})
    {
        Vector2 uiPos = {40, 100};
        if (playerId == 3 || playerId == 4) {
            uiPos.y = 600;
        }
        if (playerId == 2 || playerId == 3) {
            uiPos.x = 950;
        }
        *this->pos = uiPos;
        this->boxContainer = std::make_unique<Lib::MyTexture>("assets/UI/box.png");
        if (isAI) {
            this->playerPortrait = std::make_unique<Lib::MyTexture>("assets/UI/playerGreyPortrait.png");
        } else {
            this->playerPortrait = std::make_unique<Lib::MyTexture>("assets/UI/playerPortrait.png");
        }
        this->idText = std::make_unique<Lib::MyText>(std::to_string(playerId) + "P", 42, WHITE);
        this->idTextPos = {this->pos->x + this->playerPortrait->getTexture().width + 10, this->pos->y + 50};

        this->icons.push_back(std::make_unique<Lib::MyTexture>("assets/UI/speedIcon.png"));
        this->icons.push_back(std::make_unique<Lib::MyTexture>("assets/UI/bombIcon.png"));
        this->icons.push_back(std::make_unique<Lib::MyTexture>("assets/UI/rangeIcon.png"));
        for (int i = 0; i < this->icons.size(); i++) {
            this->iconsText.push_back(std::make_unique<Lib::MyText>("1", 36, WHITE));
        }
        this->speedIncrease = 1;
        this->infoPos = {this->pos->x, this->pos->y + 125};
    }

    PlayerInfo::~PlayerInfo()
    {

    }

    void PlayerInfo::init() {}

    void PlayerInfo::update() {}

    void PlayerInfo::draw() const
    {
        this->playerPortrait->draw(*this->pos);
        this->idText->draw(this->idTextPos);

        this->boxContainer->draw(this->infoPos);
        Vector2 newPos = {this->infoPos.x + 15, this->infoPos.y + 10};
        for (int i = 0; i < this->icons.size(); i++) {
            this->iconsText[i]->draw(newPos);
            newPos.x += 22;
            this->icons[i]->draw(newPos);
            newPos.x += 45;
        }
    }

    void PlayerInfo::killPlayer()
    {
        this->playerPortrait = std::make_unique<Lib::MyTexture>("assets/UI/deadPlayerPortrait.png");
        this->idText->setColor(GRAY);
        this->icons[0] = std::make_unique<Lib::MyTexture>("assets/UI/deadSpeedIcon.png");
        this->icons[1] = std::make_unique<Lib::MyTexture>("assets/UI/deadBombIcon.png");
        this->icons[2] = std::make_unique<Lib::MyTexture>("assets/UI/deadRangeIcon.png");
        for (int i = 0; i < this->iconsText.size(); i++) {
            this->iconsText[i]->setColor(GRAY);
        }
    }

    void PlayerInfo::increaseSpeed()
    {
        this->speedIncrease++;
        this->iconsText[0]->setContent(std::to_string(this->speedIncrease));
    }

    void PlayerInfo::increaseBombs(int newMaxNbBombs)
    {
        this->iconsText[1]->setContent(std::to_string(newMaxNbBombs));
    }

    void PlayerInfo::increaseRange(int newRange)
    {
        this->iconsText[2]->setContent(std::to_string(newRange));
    }
}