/*
** EPITECH PROJECT, 2021
** project
** File description:
** Scene.cpp
*/

#include "AScene.hpp"

#include <iostream>
namespace Indie::Scenes {
    AScene::~AScene()
    {}

    void AScene::init()
    {}

    void AScene::update()
    {}

    void AScene::drawUnder2D()
    {}

    void AScene::draw3D()
    {}

    void AScene::drawOver2D()
    {}

    void AScene::destroy()
    {}

    enum Indie::Scenes::Scenes AScene::getChangingScene()
    {
        enum Indie::Scenes::Scenes res = this->changingScene;
        this->changingScene = Indie::Scenes::UKNOWN;
        return (res);
    }

    void AScene::setPlayerInfo(std::map<int, Indie::player_t> players_info)
    {
        this->_players_info = players_info;
    }

    std::map<int, Indie::player_t> AScene::getPlayerInfo()
    {
        return (this->_players_info);
    }

    void AScene::changeBackScene(Indie::Scenes::Scenes scene)
    {
    }

    void AScene::setLoadSave(std::size_t saveIndex)
    {
        this->saveIndex = saveIndex;
    }

    std::size_t AScene::getLoadSave()
    {
        return (this->saveIndex);
    }
}
