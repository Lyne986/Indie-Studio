/*
** EPITECH PROJECT, 2021
** project
** File description:
** SceneManager.hpp
*/

#ifndef __SCENEMANAGER_HPP__
    #define __SCENEMANAGER_HPP__

    #include "Scenes/SceneNamespace.hpp"
    #include <unordered_map>
    #include "ECS/Components/AButton.hpp"
    #include "Scenes/SplashScene.hpp"
    #include "Scenes/MenuScene.hpp"
    #include "Scenes/GameScene.hpp"
    #include "Scenes/Scenes.hpp"
    #include "Scenes/LobbyScene.hpp"
    #include "Scenes/LevelScene.hpp"
    #include "Scenes/SettingScene.hpp"
    #include "Scenes/PauseScene.hpp"
    #include "Scenes/Factory.hpp"

class Indie::SceneManager {
    private:
        enum Indie::Scenes::Scenes currScene = Indie::Scenes::SPLASH;
        std::unordered_map<enum Indie::Scenes::Scenes, std::unique_ptr<Indie::Scenes::AScene>> scenes;
        bool isRunning;

    public:
    // Constructor / Destructor

        SceneManager();

    // Useful functions

        void init();
        void update();
        void drawUnder2D();
        void draw3D();
        void drawOver2D();
        bool getisRunning();
};

#endif
