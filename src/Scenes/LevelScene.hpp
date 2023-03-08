/*
** EPITECH PROJECT, 2021
** project
** File description:
** LevelScene.hpp
*/

#ifndef __LEVELSCENE_SCENE_HPP__
    #define __LEVELSCENE_SCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "../Objects/Buttons/NewGame.hpp"
    #include "../Objects/Buttons/Back.hpp"
    #include "../Objects/Buttons/LoadGame.hpp"
    #include "AScene.hpp"
    #include <memory>

class Indie::Scenes::LevelScene : public Indie::Scenes::AScene {
    private:
        std::unique_ptr<Indie::Lib::MyTexture> _bg;
        std::unique_ptr<Indie::Lib::MyText> _title;
        std::unique_ptr<Indie::Objects::Button::NewGame> _new_game;
        std::unique_ptr<Indie::Objects::Button::Back> _back;
        std::map<int, std::unique_ptr<Indie::Objects::Button::LoadGame>> _load_game;

    public:
    // Constructor / Destructor
        LevelScene();

    // Useful functions
        void drawUnder2D();
        void update();
        void create_load(int id, Vector2 pos, std::string txt);

};

#endif