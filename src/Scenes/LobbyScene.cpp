/*
** EPITECH PROJECT, 2021
** project
** File description:
** LobbyScene.cpp
*/

#include "LobbyScene.hpp"

namespace Indie::Scenes {
    LobbyScene::LobbyScene()
    {
        this->music = std::make_unique<Lib::Audio::MyMusic>("assets/audio/menu/lobbyTheme.mp3");
        this->music->setVolume(0.5f);
        Vector2 pos = {25, 820};
        _bg = std::make_unique<Indie::Lib::MyTexture>("assets/lobby.png");

        _ia_type[IA_TYPE::EASY] = "Easy";
        _ia_type[IA_TYPE::MEDIUM] = "Medium";
        _ia_type[IA_TYPE::HARD] = "Hard";

        _skins[SKINS::P_BLUE] = "assets/objects/textures/player.png";
        _skins[SKINS::P_CYAN] = "assets/objects/textures/player_cyan.png";
        _skins[SKINS::P_YELLOW] = "assets/objects/textures/player_yellow.png";
        _skins[SKINS::P_RED] = "assets/objects/textures/player_red.png";
        _skins[SKINS::P_ORANGE] = "assets/objects/textures/player_orange.png";
        _skins[SKINS::P_GREEN] = "assets/objects/textures/player_green.png";
        _skins[SKINS::P_RAINBOW] = "assets/objects/textures/player_rainbow.png";
        _skins[SKINS::P_PURPLE] = "assets/objects/textures/player_purple.png";

        create_add(1, {450, 450}, {-30, 40});
        create_add(2, {150, 450}, {-30, 40});
        create_add(3, {750, 450}, {-30, 40});
        create_add(4, {950, 450}, {-30, 40});

        create_delete(1, {500, 300});
        create_delete(2, {200, 317});
        create_delete(3, {800, 308});
        create_delete(4, {1010, 325});

        create_model(1, PLAYER, _skins[SKINS::P_BLUE], {-3, 5, 7}, {20, 180, 185}, 0.02f);
        create_model(2, EMPTY, _skins[SKINS::P_BLUE], {-11, 2, 5.7}, {20, 180, 200}, 0.019f);
        create_model(3, EMPTY, _skins[SKINS::P_BLUE], {4.5, 2, 5.7}, {20, 180, 170}, 0.0195f);
        create_model(4, EMPTY, _skins[SKINS::P_BLUE], {10, 2, 5}, {20, 180, 160}, 0.017f);

        create_change_ia(1, {368, 705}, {55, 10});
        create_change_ia(2, {85, 660}, {55, 10});
        create_change_ia(3, {685, 665}, {55, 10});
        create_change_ia(4, {900, 630}, {55, 10});

        create_change_skin(1, {375, 500}, 150);
        create_change_skin(2, {102, 485}, 120);
        create_change_skin(3, {690, 470}, 130);
        create_change_skin(4, {913, 460}, 110);

        _back = std::make_unique<Indie::Objects::Button::Back>(pos, Indie::Scenes::MENU);
        pos = {1100, 800};
        _battle = std::make_unique<Indie::Objects::Button::Battle>(pos);
    }

    void LobbyScene::init()
    {
        this->music->restart();
        this->music->play();
    }

    void LobbyScene::create_model(int id, TYPE type, std::string model, Vector3 pos, Vector3 rotation, float scale)
    {
        _model[id].pos = pos;
        _model[id].rotation = rotation;
        _model[id].scale = scale;
        _model[id].type = type;
        _model[id].sprite = model;
        _model[id].character = std::make_unique<Indie::Character>(model, pos, scale,  rotation);

        _players_info[id].type = type;
        _players_info[id].model = model;
        _players_info[id].controller_id = -1;
        _players_info[id].ia_type = MEDIUM;
    }

    void LobbyScene::update_model(int id, TYPE type, std::string model)
    {
        _model[id].type = type;
        _players_info[id].type = type;
        if (type != PLAYER) {
            _players_info[id].controller_id = -1;
            _players_info[id].ia_type = MEDIUM;
        }
        if (type == EMPTY) {
            return;
        }
        if (_model[id].sprite.compare(model) != 0)
            _model[id].character = std::make_unique<Indie::Character>(model, _model[id].pos, _model[id].scale,  _model[id].rotation);
        _model[id].sprite = model;
        _players_info[id].model = model;

    }

    void LobbyScene::create_add(int id, Vector2 pos, Vector2 text_pos)
    {
        _add[id * 2 - 1] = std::make_unique<Indie::Objects::Button::Add>("Add Player", pos, text_pos);
        pos.y = 520;
        text_pos.x = -20;
        _add[id * 2] = std::make_unique<Indie::Objects::Button::Add>("Add Bot", pos, text_pos);
    }

    void LobbyScene::create_delete(int id, Vector2 pos)
    {
        _delete[id] = std::make_unique<Indie::Objects::Button::Delete>(pos);
    }

    void LobbyScene::create_change_skin(int id, Vector2 pos, int pos_x)
    {
        _change_skin[id * 2 - 1] = std::make_unique<Indie::Objects::Button::Change>(pos, "assets/buttons/change_left.png");
        pos.x += pos_x;
        _change_skin[id * 2] = std::make_unique<Indie::Objects::Button::Change>(pos, "assets/buttons/change_right.png");
    }

    void LobbyScene::create_change_ia(int id, Vector2 pos, Vector2 text_pos)
    {
        _change_ia[id * 2 - 1] = std::make_unique<Indie::Objects::Button::Change>(pos, "assets/buttons/change_left.png", _ia_type[_players_info[id].ia_type], text_pos);
        pos.x += 150;
        _change_ia[id * 2] = std::make_unique<Indie::Objects::Button::Change>(pos, "assets/buttons/change_right.png");
    }


    void LobbyScene::drawUnder2D()
    {
        int i = 1;
        std::map<int, Indie::Scenes::LobbyScene::charact_t>::iterator it;

        _bg->draw({0, 0});
        for (it = _model.begin(); it != _model.end(); it++) {
            if (it->second.type == EMPTY) {
                _add[i].get()->draw();
                _add[i + 1].get()->draw();
            }
            i += 2;
        }
        _back->draw();
        _battle->draw();
    }

    void LobbyScene::drawOver2D()
    {
        int i = 1;
        int j = 1;
        std::map<int, Indie::Scenes::LobbyScene::charact_t>::iterator it;

        for (it = _model.begin(); it != _model.end(); it++) {
            if (it->second.type != EMPTY) {
                _delete[i].get()->draw();
            }
            if (it->second.type == AI) {
                _change_ia[j].get()->draw();
                _change_ia[j + 1].get()->draw();
            }
            if (it->second.type == PLAYER) {
                _change_skin[j].get()->draw();
                _change_skin[j + 1].get()->draw();
            }
            i++;
            j += 2;
        }
    }

    void LobbyScene::update()
    {
        int i = 1;
        std::map<int, Indie::Scenes::LobbyScene::charact_t>::iterator it;

        this->music->update();
        for (it = _model.begin(); it != _model.end(); it++) {
            if (it->second.type == EMPTY) {
                _add[i].get()->update();
                _add[i + 1].get()->update();
                if (_add[i]->isClick()) {
                    connectController((i / 2) + 1);
                }
                if (_add[i + 1]->isClick()) {
                    update_model((i / 2) + 1, AI, "assets/objects/textures/player_grey.png");
                }
            } else {
                it->second.character->update();
                _delete[i / 2 + 1].get()->update();
                _change_ia[i].get()->update();
                _change_ia[i + 1].get()->update();
                _change_skin[i].get()->update();
                _change_skin[i + 1].get()->update();
                if (_delete[i / 2 + 1].get()->isClick()) {
                    update_model(i / 2 + 1, EMPTY, "assets/objects/textures/player.png");
                }
                if (it->second.type == AI) {
                    if (_change_ia[i].get()->isClick()) {
                        this->update_ia((i / 2) + 1, -1);
                    }
                    if (_change_ia[i + 1].get()->isClick()) {
                        this->update_ia((i / 2) + 1, 1);
                    }
                }
                if (it->second.type == PLAYER) {
                    if (_change_skin[i].get()->isClick()) {
                        this->update_skin((i / 2) + 1, -1);
                    }
                    if (_change_skin[i + 1].get()->isClick()) {
                        this->update_skin((i / 2) + 1, 1);
                    }
                }
            }
            i += 2;
        }
        _back.get()->update();
        _battle.get()->update();
        if (_back->isClick()) {
            this->reset();
            this->changingScene = this->_back->getScene();
        }
        if (_battle->isClick() && this->getNbrPlayer() > 1)
            this->changingScene = Indie::Scenes::LEVEL;

        updateControllerNbr();
    }

    void LobbyScene::draw3D()
    {
        std::map<int, Indie::Scenes::LobbyScene::charact_t>::iterator it;

        for (it = _model.begin(); it != _model.end(); it++) {
            if (it->second.type != EMPTY) {
                it->second.character->draw();
            }
        }
    }

    void LobbyScene::reset()
    {
        update_model(1, PLAYER, "assets/objects/textures/player.png");
        update_model(2, EMPTY, "assets/objects/textures/player.png");
        update_model(3, EMPTY, "assets/objects/textures/player.png");
        update_model(4, EMPTY, "assets/objects/textures/player.png");
        _players_info[2].controller_id = -1;
        _players_info[3].controller_id = -1;
        _players_info[4].controller_id = -1;
    }

    void LobbyScene::create_player(int id, TYPE type, std::string model)
    {
        _players_info[id].type = type;
        _players_info[id].model = model;
        _players_info[id].controller_id = -1;
    }

    int LobbyScene::getNbrController()
    {
        int nbr = 0;

        for (int i = 0; i < 4; i++) {
            if (event.isGamepadAvailable(i))
                nbr++;
            else
                break;
        }
        return nbr;
    }

    void LobbyScene::updateControllerNbr()
    {
        std::map<int, Indie::player_t>::iterator it;

        for (it = _players_info.begin(); it != _players_info.end(); it++) {
            if (it->second.controller_id != -1) {
                if (!event.isGamepadAvailable(it->second.controller_id)) {
                    it->second.controller_id = -1;
                    update_model(it->first, EMPTY, "assets/objects/player.iqm");
                }
            }
        }
    }

    int LobbyScene::connectController(int id)
    {
        int nbr = getNbrController();
        std::map<int, Indie::player_t>::iterator it;
        std::vector<int> id_controllers = {0, 1, 2, 3};
        std::vector<int>::iterator it_id;

        for (it = _players_info.begin(); it != _players_info.end(); it++) {
            if (it->second.controller_id != -1) {
                id_controllers[it->second.controller_id] = -1;
            }
        }

        for (it_id = id_controllers.begin(); it_id != id_controllers.end(); it_id++) {
            if (*it_id != -1 && event.isGamepadAvailable(*it_id)) {
                _players_info[id].controller_id = *it_id;
                update_model(id, PLAYER, "assets/objects/textures/player.png");
                return *it_id;
            }
        }
        if (id == 1) {
            update_model(id, PLAYER, "assets/objects/textures/player.png");
        }
        return -1;
    }

    int LobbyScene::getNbrPlayer()
    {
        int nbr = 0;
        std::map<int, Indie::player_t>::iterator it;

        for (it = _players_info.begin(); it != _players_info.end(); it++) {
            if (it->second.type != EMPTY)
                nbr++;
        }
        return nbr;
    }

    void LobbyScene::update_ia(int id, int chosen_ia)
    {
        int choice = _players_info[id].ia_type + chosen_ia;

        if (choice < IA_TYPE::EASY)
            choice = IA_TYPE::HARD;
        if (choice > IA_TYPE::HARD)
            choice = IA_TYPE::EASY;
        _players_info[id].ia_type = IA_TYPE(choice);
        _change_ia[id * 2 - 1].get()->setText(_ia_type[IA_TYPE(choice)]);
    }

    void LobbyScene::update_skin(int id, int chosen_skin)
    {
        int choice = 0;
        std::map<Indie::Scenes::LobbyScene::SKINS, std::string>::iterator it;
        for (it = _skins.begin(); it != _skins.end(); it++) {
            if (it->second.compare(_players_info[id].model) == 0) {
                break;
            }
            choice++;
        }
        choice += chosen_skin;

        if (choice < SKINS::P_BLUE)
            choice = SKINS::P_PURPLE;
        if (choice > SKINS::P_PURPLE)
            choice = SKINS::P_BLUE;
        update_model(id, PLAYER, _skins[SKINS(choice)]);
    }
}
