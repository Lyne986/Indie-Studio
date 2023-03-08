/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PauseScene
*/

#include "PauseScene.hpp"

namespace Indie::Scenes {
    PauseScene::PauseScene()
    {
        Vector2 pos = {25, 820};
        _parallax = std::make_unique<Indie::Lib::MyTexture>("assets/parallax.png");
        _tittlePause = std::make_unique<Indie::Objects::Button::Title>("Pause");
        _quit = std::make_unique<Indie::Objects::Button::Quit>(616, 820);
        _back = std::make_unique<Indie::Objects::Button::Back>(pos, Indie::Scenes::GAME);
        _backMenu = std::make_unique<Indie::Objects::Button::BackSetting>();
        _sound = std::make_unique<Indie::Objects::Cursor::SoundBarre>();
        _fps = std::make_unique<Indie::Objects::Cursor::fpsBarre>();
        this->music = std::make_unique<Lib::Audio::MyMusic>("assets/audio/menu/settingsTheme.mp3");
        this->music->setVolume(0.5f);
    }

    void PauseScene::init()
    {
        this->music->restart();
        this->music->play();
    }

    void PauseScene::drawOver2D()
    {
        _parallax->draw({0, 0});
        _tittlePause->draw();
        _quit->draw();
        _back->draw();
        _backMenu->draw();
        _sound->draw();
        _fps->draw();
    }

    void PauseScene::update()
    {
        this->music->update();
        _quit->update();
        if (_quit->isClick()) {
            this->changingScene = Indie::Scenes::QUIT;
        }
        _back->update();
        if (_back->isClick()) {
            this->changingScene = this->_back->getScene();
        }
        _backMenu->update();
        if (_backMenu->isClick()) {
            this->changingScene = Indie::Scenes::MENU;
        }
        _sound->update();
        _fps->update();
    }
}
