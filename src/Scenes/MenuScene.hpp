/*
** EPITECH PROJECT, 2021
** project
** File description:
** MenuScene.hpp
*/

#ifndef __MENU_SCENE_HPP__
    #define __MENU_SCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "../Objects/Buttons/GameButton.hpp"
    #include "../Objects/Buttons/Quit.hpp"
    #include "../Objects/Buttons/Setting.hpp"
    #include "../Objects/Buttons/Local.hpp"
    #include "../Objects/Buttons/Online.hpp"
    #include "AScene.hpp"
    #include <memory>

class Indie::Scenes::MenuScene : public Indie::Scenes::AScene {
    private:
        std::unique_ptr<Indie::Lib::MyTexture> _parallax;
        std::unique_ptr<Indie::Lib::MyTexture> _bombeMenu;
        std::unique_ptr<Indie::Lib::MyTexture> _title;
        std::unique_ptr<Indie::Objects::Button::Local> _local;
        std::unique_ptr<Indie::Objects::Button::Online> _online;
        std::unique_ptr<Indie::Objects::Button::Setting> _settings;
        std::unique_ptr<Indie::Objects::Button::Quit> _quit;

    public:
    // Constructor / Destructor
        MenuScene();

    // Useful functions
        void init();
        void update();
        void drawOver2D();

};

#endif