/*
** EPITECH PROJECT, 2021
** project
** File description:
** MenuScene.cpp
*/

#include "MenuScene.hpp"

namespace Indie::Scenes {
    MenuScene::MenuScene()
    {
        this->music = std::make_unique<Lib::Audio::MyMusic>("assets/audio/menu/titleTheme.mp3");
        this->music->setVolume(0.5f);
        _parallax = std::make_unique<Indie::Lib::MyTexture>("assets/parallax.png");
        _bombeMenu = std::make_unique<Indie::Lib::MyTexture>("assets/buttons/bombeMenu.png");
        _bombeMenu->setScale(0.7);
        _title = std::make_unique<Indie::Lib::MyTexture>("assets/buttons/title.png");
        _title->setScale(0.65);
        _local = std::make_unique<Indie::Objects::Button::Local>();
        _online = std::make_unique<Indie::Objects::Button::Online>();
        _settings = std::make_unique<Indie::Objects::Button::Setting>();
        _quit = std::make_unique<Indie::Objects::Button::Quit>(616, 520);
    }

    void MenuScene::init()
    {
        this->music->restart();
        this->music->play();
    }

    void MenuScene::drawOver2D()
    {
        _parallax->draw({0, 0});
        _bombeMenu->draw({50, 300});
        _title->draw({200, 50});
        _local->draw();
        _online->draw();
        _settings->draw();
        _quit->draw();
    }

    void MenuScene::update()
    {
        this->music->update();
        _local->update();
        if (_local->isClick()) {
            this->changingScene = Indie::Scenes::LOBBY;
        }
        _online->update();
        if (_online->isClick()) {
            this->changingScene = Indie::Scenes::GAME;
        }
        _settings->update();
        if (_settings->isClick()) {
            this->changingScene = Indie::Scenes::SETTING;
        }
        _quit->update();
        if (_quit->isClick()) {
            this->changingScene = Indie::Scenes::QUIT;
        }
    }
}
