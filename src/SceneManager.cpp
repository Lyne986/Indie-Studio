/*
** EPITECH PROJECT, 2021
** project
** File description:
** SceneManager.cpp
*/

#include "SceneManager.hpp"

namespace Indie {
    SceneManager::SceneManager()
    {
        this->scenes[Indie::Scenes::SPLASH] = Indie::Scenes::Factory::createScene<Indie::Scenes::SplashScene>();
        this->scenes[Indie::Scenes::MENU] = Indie::Scenes::Factory::createScene<Indie::Scenes::MenuScene>();
        this->scenes[Indie::Scenes::GAME] = Indie::Scenes::Factory::createScene<Indie::Scenes::GameScene>();
        this->scenes[Indie::Scenes::LOBBY] = Indie::Scenes::Factory::createScene<Indie::Scenes::LobbyScene>();
        this->scenes[Indie::Scenes::LEVEL] = Indie::Scenes::Factory::createScene<Indie::Scenes::LevelScene>();
        this->scenes[Indie::Scenes::SETTING] = Indie::Scenes::Factory::createScene<Indie::Scenes::SettingScene>();
        this->scenes[Indie::Scenes::PAUSE] = Indie::Scenes::Factory::createScene<Indie::Scenes::PauseScene>();
        this->isRunning = true;
    }

    void SceneManager::init()
    {
        this->scenes[this->currScene]->init();
    }

    void SceneManager::update()
    {
        enum Indie::Scenes::Scenes scene = this->scenes[this->currScene]->getChangingScene();
        if (scene != Indie::Scenes::UKNOWN) {
            if (scene == Indie::Scenes::QUIT)
                this->isRunning = false;
            else {
                this->scenes[scene]->setLoadSave(this->scenes[this->currScene]->getLoadSave());
                if (this->currScene == Indie::Scenes::PAUSE && scene == Indie::Scenes::SETTING) {
                    this->scenes[Indie::Scenes::SETTING]->changeBackScene(Indie::Scenes::PAUSE);
                } else {
                    this->scenes[Indie::Scenes::SETTING]->changeBackScene(Indie::Scenes::MENU);
                }
                if (this->currScene == Indie::Scenes::PAUSE && scene == Indie::Scenes::GAME) {
                    this->currScene = scene;
                    this->scenes[this->currScene]->update();
                    return;
                }
                this->currScene = scene;
                if (scene == Indie::Scenes::GAME)
                    this->scenes[scene]->setPlayerInfo(this->scenes[Indie::Scenes::LOBBY]->getPlayerInfo());
                this->init();
            }
        }
        this->scenes[this->currScene]->update();
    }

    void SceneManager::drawUnder2D()
    {
        this->scenes[this->currScene]->drawUnder2D();
    }

    void SceneManager::draw3D()
    {
        this->scenes[this->currScene]->draw3D();
    }

    void SceneManager::drawOver2D()
    {
        this->scenes[this->currScene]->drawOver2D();
    }

    bool SceneManager::getisRunning()
    {
        return this->isRunning;
    }
};
