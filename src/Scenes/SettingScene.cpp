/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** SettingScene
*/

#include "SettingScene.hpp"

namespace Indie::Scenes {
    SettingScene::SettingScene()
    {
        Vector2 pos = {25, 820};

        _parallax = std::make_unique<Indie::Lib::MyTexture>("assets/parallax.png");
        _back = std::make_unique<Indie::Objects::Button::Back>(pos ,Indie::Scenes::MENU);
        _quit = std::make_unique<Indie::Objects::Button::Quit>(616, 820);
        _title = std::make_unique<Indie::Objects::Button::Title>("Setting");
        _sound = std::make_unique<Indie::Objects::Cursor::SoundBarre>();
        _fps = std::make_unique<Indie::Objects::Cursor::fpsBarre>();
        this->music = std::make_unique<Lib::Audio::MyMusic>("assets/audio/menu/settingsTheme.mp3");
        this->music->setVolume(0.5f);
    }

    void SettingScene::init()
    {
        this->music->restart();
        this->music->play();
    }

    void SettingScene::drawOver2D()
    {
        _parallax->draw({0, 0});
        _back->draw();
        _title->draw();
        _sound->draw();
        _fps->draw();
        _quit->draw();
    }

    void SettingScene::update()
    {
        this->music->update();
        _back->update();
        if (_back->isClick()) {
            this->changingScene = this->_back->getScene();
        }
        if (_quit->isClick()) {
            this->changingScene = Indie::Scenes::MENU;
        }
        _sound->update();
        _fps->update();
        _quit->update();
        if (_quit->isClick()) {
            exit (0);
        }
    }

    void SettingScene::changeBackScene(Indie::Scenes::Scenes scene)
    {
        this->_back->setScene(scene);
    }
}
