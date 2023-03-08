/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** SettingScene
*/

#ifndef SETTINGSCENE_HPP_
    #define SETTINGSCENE_HPP_

    #include "SceneNamespace.hpp"
    #include "../Objects/Buttons/GameButton.hpp"
    #include "../Objects/Buttons/Back.hpp"
    #include "../Objects/Buttons/Title.hpp"
    #include "../Objects/Buttons/Quit.hpp"
    #include "../Objects/Cursor/SoundSetting.hpp"
    #include "../Objects/Cursor/fpsSetting.hpp"
    #include "../Objects/Buttons/Fps.hpp"
    #include "../Lib/MyText.hpp"
    #include "AScene.hpp"
    #include <memory>

class Indie::Scenes::SettingScene : public Indie::Scenes::AScene {
    private:
        std::unique_ptr<Indie::Lib::MyTexture> _parallax;
        std::unique_ptr<Indie::Objects::Button::Back> _back;
        std::unique_ptr<Indie::Objects::Button::Quit> _quit;
        std::unique_ptr<Indie::Objects::Button::Title> _title;
        std::unique_ptr<Indie::Objects::Cursor::SoundBarre> _sound;
        std::unique_ptr<Indie::Objects::Cursor::fpsBarre> _fps;

    public:
        SettingScene();

    // Useful functions
        void init();
        void update();
        void drawOver2D();
        void changeBackScene(Indie::Scenes::Scenes scene);
        void drawFps();

};

#endif /* !SETTINGSCENE_HPP_ */
