/*
** EPITECH PROJECT, 2021
** project
** File description:
** Scene.hpp
*/

#ifndef __ASCENE_HPP__
    #define __ASCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "IScene.hpp"
    #include "Scenes.hpp"

class Indie::Scenes::AScene : public Indie::Scenes::IScene {
    protected:
        enum Indie::Scenes::Scenes changingScene = Indie::Scenes::UKNOWN;
        std::unique_ptr<Lib::Audio::MyMusic> music;
        std::map<int, Indie::player_t> _players_info;
        std::size_t saveIndex = 0;

    public:
    // Constructor / Destructor
        ~AScene();

    // Useful methods
        void init();
        void update();
        void drawUnder2D();
        void draw3D();
        void drawOver2D();
        void destroy();

    // Getter / Setter
        enum Indie::Scenes::Scenes getChangingScene();
        void setPlayerInfo(std::map<int, Indie::player_t> players_info);
        std::map<int, Indie::player_t> getPlayerInfo();
        void changeBackScene(Indie::Scenes::Scenes scene);
        void setLoadSave(std::size_t saveIndex);
        std::size_t getLoadSave();
};

#endif
