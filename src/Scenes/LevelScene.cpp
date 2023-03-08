/*
** EPITECH PROJECT, 2021
** project
** File description:
** LevelScene.cpp
*/

#include "LevelScene.hpp"

namespace Indie::Scenes {
    LevelScene::LevelScene()
    {
        Vector2 pos = {345, 300};
        _bg = std::make_unique<Indie::Lib::MyTexture>("assets/parallax.png");
        _title = std::make_unique<Indie::Lib::MyText>("Select a game", 100, WHITE);
        _new_game = std::make_unique<Indie::Objects::Button::NewGame>(pos);
        pos = {25, 820};
        _back = std::make_unique<Indie::Objects::Button::Back>(pos, Indie::Scenes::LOBBY);

        create_load(1, {130, 500}, "Game 1");
        create_load(2, {480, 500}, "Game 2");
        create_load(3, {830, 500}, "Game 3");
    }

    void LevelScene::create_load(int id, Vector2 pos, std::string txt)
    {
        _load_game[id] = std::make_unique<Indie::Objects::Button::LoadGame>(pos, txt);
    }

    void LevelScene::drawUnder2D()
    {
        std::map<int, std::unique_ptr<Indie::Objects::Button::LoadGame>>::iterator it;

        _bg->draw({0, 0});
        _title->draw({250, 60});
        _new_game.get()->draw();
        _back.get()->draw();
        for (it = _load_game.begin(); it != _load_game.end(); it++) {
            it->second.get()->draw();
        }
    }

    void LevelScene::update()
    {
        std::map<int, std::unique_ptr<Indie::Objects::Button::LoadGame>>::iterator it;

        _new_game.get()->update();
        _back.get()->update();
        _back.get()->update();
        if (_new_game.get()->isClick()) {
            this->changingScene = Indie::Scenes::GAME;
        }
        if (_back->isClick())
            this->changingScene = this->_back->getScene();
        std::size_t index = 1;
        for (it = _load_game.begin(); it != _load_game.end(); it++) {
            it->second.get()->update();
            if (it->second->isClick()) {
                this->changingScene = Indie::Scenes::GAME;
                this->saveIndex = index;
            }
            index++;
        }
    }
}
