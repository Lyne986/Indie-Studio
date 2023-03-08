/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** PauseScene
*/

#ifndef PAUSESCENE_HPP_
    #define PAUSESCENE_HPP_

    #include "../Objects/Buttons/Title.hpp"
    #include "../Objects/Buttons/Quit.hpp"
    #include "../Objects/Buttons/Back.hpp"
    #include "../Objects/Buttons/BackSetting.hpp"
    #include "SceneNamespace.hpp"
    #include "../Objects/Cursor/SoundSetting.hpp"
    #include "../Objects/Cursor/fpsSetting.hpp"
    #include "../Objects/Buttons/Fps.hpp"
    #include "AScene.hpp"
    #include <memory>

class Indie::Scenes::PauseScene : public Indie::Scenes::AScene {
    public:
        PauseScene();
        void init();
        void update();
        void drawOver2D();
    private:
        std::unique_ptr<Indie::Lib::MyTexture> _parallax;
        std::unique_ptr<Indie::Objects::Button::Title> _tittlePause;
        std::unique_ptr<Indie::Objects::Button::Quit> _quit;
        std::unique_ptr<Indie::Objects::Button::Back> _back;
        std::unique_ptr<Indie::Objects::Button::BackSetting> _backMenu;
        std::unique_ptr<Indie::Objects::Cursor::SoundBarre> _sound;
        std::unique_ptr<Indie::Objects::Cursor::fpsBarre> _fps;
        std::unique_ptr<Indie::Objects::Button::Fps> _fpsButton;
};

#endif /* !PAUSESCENE_HPP_ */
