/*
** EPITECH PROJECT, 2021
** project
** File description:
** GameScene.hpp
*/

#ifndef __GAME_SCENE_HPP__
    #define __GAME_SCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "../Objects/Objects_namespace.hpp"
    #include "../Objects/Buttons/GameButton.hpp"
    #include "../Objects/Interactables/Player.hpp"
    #include "../Objects/Interactables/Bomb.hpp"
    #include "../Objects/Animations/GameIntro.hpp"
    #include "../Objects/Animations/GameOutro.hpp"
    #include "../Objects/MapManager.hpp"
    #include "../Lib/Lib_namespace.hpp"
    #include "AScene.hpp"
    #include <memory>
    #include <algorithm>
    #include <regex>
    #include <unordered_map>
    #define REQUEST_REGEX "phase=([a-z0-9-]*);event=([a-z ]*);id=([0-9]*);message=([a-zA-Z0-9-.,\\/_:]*)"
    #define PLAYER_REGEX "([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*):([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*):([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*):([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*)"
    #define WALL_REGEX "([0-9-.]*),([0-9-.]*),([0-9-.]*):"
    #define WALL_COLLIDER_REGEX "([0-9-.]*),([0-9-.]*):"
    #define POWER_UP_REGEX "([0-9-.]*),"
    #define BOMB_REGEX "([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9-.]*),([0-9]*):"
    #define SAVE_REGEX "([a-zA-Z=0-9;,.:\\ -]*)\\n([a-zA-Z=0-9;,.:\\ -]*)\\n([a-zA-Z=0-9;,.:\\ -]*)\\n([a-zA-Z=0-9;,.:\\ -]*)\\n([a-zA-Z=0-9;,.:\\ -]*)"

class Indie::Scenes::GameScene : public Indie::Scenes::AScene {
    private:
        void loadSave(std::string content);
        void sendPowerUp();
        void updateFromServer();
        void sendUpdateToServer();
        void parsePlayer(std::smatch match, bool isSave = false);
        void parseWallCollider(std::smatch match, bool isSave=false);
        void parseWallDrawable(std::smatch match, bool isSave=false);
        void parsePowerUp(std::smatch match, bool isSave=false);
        void parseBomb(std::smatch match, bool isSave=false);
        std::string getPowerUpRequest();
        std::string getWallColliderRequest();
        std::string getPlayerRequest();
        std::string getWallDrawableRequest();
        std::string getBombRequest();
        std::unique_ptr<Objects::Button::GameButton> gameButton;
        std::unique_ptr<Objects::Interactables::Player> player;
        std::unique_ptr<Objects::MapManager> mapManager;
        std::size_t packageId = 0;
        std::size_t receivedPackageId = 0;
        std::unique_ptr<ECS::Components::Timer> timer;
        Objects::Animations::GameIntro gameIntro;
        Objects::Animations::GameOutro gameOutro;
        std::unordered_map<std::string, void (GameScene::*)(std::smatch, bool)> eventMap = {
            {"player", &GameScene::parsePlayer},
            {"wall collider", &GameScene::parseWallCollider},
            {"wall drawable", &GameScene::parseWallDrawable},
            {"bomb", &GameScene::parseBomb},
            {"powerup", &GameScene::parsePowerUp}
        };
        Lib::MyEvent event;
        std::size_t gid = 0;
        std::size_t pid = 0;

        typedef enum {
            START_INTRO,
            GAME,
            END_INTRO,
            END,
            PAUSEGAME
        } GamePhase;

        GamePhase currentGamePhase;

    public:
    // Constructor / Destructor
        GameScene();

    // Useful functions
        void init();
        void update();
        void drawUnder2D();
        void draw3D();
        void drawOver2D();
        void writeSaveInFile(std::string filename);
};

#endif
