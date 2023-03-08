/*
** EPITECH PROJECT, 2021
** project
** File description:
** LobbyScene.hpp
*/

#ifndef __LOBBY_SCENE_HPP__
    #define __LOBBY_SCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "../Objects/Buttons/Add.hpp"
    #include "../Objects/Buttons/Delete.hpp"
    #include "../Objects/Buttons/Back.hpp"
    #include "../Objects/Buttons/Battle.hpp"
    #include "../Objects/Buttons/Change.hpp"
    #include "AScene.hpp"
    #include <memory>
    #include "../ECS/Components/Model3D.hpp"
    #include "../Menu/Character.hpp"   

class Indie::Scenes::LobbyScene : public Indie::Scenes::AScene {
    private:
        typedef struct charact_s {
            TYPE type;
            std::string sprite;
            std::unique_ptr<Indie::Character> character;
            Vector3 pos;
            Vector3 rotation;
            float scale;
        } charact_t;

        enum SKINS {
            P_BLUE,
            P_CYAN,
            P_YELLOW,
            P_RED,
            P_ORANGE,
            P_GREEN,
            P_RAINBOW,
            P_PURPLE
        };

        std::unique_ptr<Indie::Lib::MyTexture> _bg;
        std::map<int, charact_t> _model;
        std::map<int, std::unique_ptr<Indie::Objects::Button::Add>> _add;
        std::map<int, std::unique_ptr<Indie::Objects::Button::Delete>> _delete;
        std::map<int, std::unique_ptr<Indie::Objects::Button::Change>> _change_skin;
        std::map<int, std::unique_ptr<Indie::Objects::Button::Change>> _change_ia;
        std::map<IA_TYPE, std::string> _ia_type;
        std::map<SKINS, std::string> _skins;
        std::unique_ptr<Indie::Objects::Button::Back> _back;
        std::unique_ptr<Indie::Objects::Button::Battle> _battle;
        Lib::MyEvent event;

    public:
    // Constructor / Destructor
        LobbyScene();

    // Usefull functions
        void init();
        void update();
        void drawUnder2D();
        void draw3D();
        void drawOver2D();
        void create_model(int id, TYPE type, std::string model, Vector3 pos, Vector3 rotation, float scale);
        void update_model(int id, TYPE type, std::string model);
        void create_add(int id, Vector2 pos, Vector2 text_pos);
        void create_delete(int id, Vector2 pos);
        void reset();
        void create_player(int id, TYPE type, std::string model);
        void create_change_skin(int id, Vector2 pos, int pos_x);
        void create_change_ia(int id, Vector2 pos, Vector2 text_pos);
        void updateControllerNbr();
        int connectController(int id);
        void update_ia(int id, int chosen_ia);
        void update_skin(int id, int chosen_skin);

    // Getters
        int getNbrController();
        int getNbrPlayer();


};

#endif