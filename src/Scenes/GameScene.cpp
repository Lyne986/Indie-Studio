/*
** EPITECH PROJECT, 2021
** project
** File description:
** GameScene.cpp
*/

#include "GameScene.hpp"

namespace Indie::Scenes {

    bool operator==(Vector3 a, Vector3 b)
    {
        return (a.x == b.x && a.y == b.y && a.z == b.z);
    }

    GameScene::GameScene()
    {
        this->music = std::make_unique<Lib::Audio::MyMusic>("assets/audio/mapTheme.mp3");
        this->music->setVolume(0.5f);
    }

    std::string GameScene::getPlayerRequest()
    {
        std::string request = "phase=gid" + std::to_string(this->gid) + ";event=player;id=" + std::to_string(this->packageId++) + ";message=";
        for (std::size_t i = 0; i < 4; i++) {
            std::shared_ptr<Indie::Objects::Interactables::APlayer> player = this->mapManager->getPlayer(i);
            if (player != nullptr) {
                Vector3 pPos = this->mapManager->getPlayer(i)->getPosition();
                request += std::to_string(pPos.x) + "," 
                        + std::to_string(pPos.y) + "," 
                        + std::to_string(pPos.z) + "," 
                        + std::to_string(player->getRot().x) + ","
                        + std::to_string(player->getRot().y) + ","
                        + std::to_string(player->getRot().z) + ","
                        + "1";
                request += ":";
            } else {
                request += "0,0,0,0,0,0,0:";
            }
        }
        return (request);
    }

    std::string GameScene::getWallColliderRequest()
    {
        std::string request = "phase=gid" + std::to_string(this->gid) + ";event=wall collider;id=" + std::to_string(this->packageId++) + ";message=";
        std::vector<std::shared_ptr<ECS::Systems::Collider>> colliders = this->mapManager->getColliders();
        for (std::shared_ptr<ECS::Systems::Collider> collider : colliders) {
            if (!collider->getIsActive()) {
                Rectangle pos = collider->getRect();
                request += std::to_string(pos.x) + "," 
                        + std::to_string(pos.y) + ":";
            }
        }
        return (request);
    }

    std::string GameScene::getWallDrawableRequest()
    {
        std::string request = "phase=gid" + std::to_string(this->gid) + ";event=wall drawable;id=" + std::to_string(this->packageId++) + ";message=";
        std::vector<std::shared_ptr<Indie::Objects::Interactables::DestroyableWall>> walls = this->mapManager->getDestroyableWalls();

        for (std::shared_ptr<Indie::Objects::Interactables::DestroyableWall> wall : walls) {
            if (!wall->getIsActive()) {
                Vector3 pos = wall->getPosition();
                request += std::to_string(pos.x) + "," 
                        + std::to_string(pos.y) + "," 
                        + std::to_string(pos.z) + ":";
            }
        }
        return (request);
    }

    void GameScene::parseBomb(std::smatch match, bool isSave)
    {
        std::string data = match[4];
        const std::regex ta_regex(BOMB_REGEX);
        std::smatch cmatch;
        std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>> messageBombs;
        typedef struct bombData_s {
            Vector3 pos;
            int range;
            bool active;
        } bombdata_t;
        std::vector<bombdata_t> bombDatas;

        while (regex_search(data, cmatch, ta_regex)) {
            Vector3 pos = {
                std::stof(cmatch[1]),
                std::stof(cmatch[2]),
                std::stof(cmatch[3])
            };
            int range = std::stoi(cmatch[4]);
            bool isActive = std::stoi(cmatch[5]);
            bombDatas.push_back(bombdata_t{pos, range, isActive});
            data = cmatch.suffix();
        }
        std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>> bombs = this->mapManager->getBombs();
        for (bombdata_t data : bombDatas) {
            std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>>::iterator it = std::find_if(bombs.begin(), bombs.end(), [&data](std::shared_ptr<Indie::Objects::Interactables::Bomb> wantedBomb) {
                return (wantedBomb->getPosition() == data.pos);
            });
            if (it == bombs.end()) {
                if (this->mapManager->getPlayer(this->pid) != nullptr) {
                    this->mapManager->getPlayer(this->pid)->placeBomb(this->mapManager->getCollidersRef(), this->mapManager->getBombsRef());
                }
            }
        }
    }

    std::string GameScene::getBombRequest()
    {
        std::string request = "phase=gid" + std::to_string(this->gid) + ";event=bomb;id=" + std::to_string(this->packageId++) + ";message=";
        std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>> bombs = this->mapManager->getBombs();

        for (std::shared_ptr<Indie::Objects::Interactables::Bomb> bomb : bombs) {
            Vector3 pos = bomb->getPosition();
            request += std::to_string(pos.x) + ","
                    + std::to_string(pos.y) + ","
                    + std::to_string(pos.z) + ","
                    + std::to_string(bomb->getRange()) + ",";
            if (bomb->getIsActive() && !bomb->getHasExploded()) {
                request += "1";
            } else {
                request += "1";
            }
            request += ":";
        }
        return (request);
    }

    void GameScene::parsePlayer(std::smatch match, bool isSave)
    {
        const std::regex ta_regex(PLAYER_REGEX);
        std::smatch pmatch;
        std::string data = match[4];
        
        if (regex_search(data, pmatch, ta_regex)) {
            for (std::size_t i = 0; i < 4; i++) {
                if (isSave) {
                    Vector3 pos = {
                        std::stof(pmatch[i * 7 + 1]),
                        std::stof(pmatch[i * 7 + 2]),
                        std::stof(pmatch[i * 7 + 3])
                    };
                    Vector3 rot = {
                        std::stof(pmatch[i * 7 + 4]),
                        std::stof(pmatch[i * 7 + 5]),
                        std::stof(pmatch[i * 7 + 6])
                    };
                    int isAlive = std::stoi(pmatch[i * 7 + 7]);
                    if (isAlive) {
                        if (this->mapManager->getPlayer(i) != nullptr) {
                            this->mapManager->getPlayer(i)->setPosition(pos);
                            this->mapManager->getPlayer(i)->setRot(rot);
                        }
                    } else {
                        if (this->mapManager->getPlayer(i) != nullptr) {
                            // s->mapManager->getPlayer(i)->kill();
                            this->mapManager->getPlayer(i) = nullptr;
                        }
                    }
                }
            }
        }
    }

    void GameScene::parseWallCollider(std::smatch match, bool isSave)
    {
        std::string data = match[4];
        const std::regex ta_regex(WALL_COLLIDER_REGEX);
        std::smatch cmatch;
        std::vector<Vector2> collPos;
        while (regex_search(data, cmatch, ta_regex)) {
            Vector2 pos = {
                std::stof(cmatch[1]),
                std::stof(cmatch[2])
            };
            collPos.push_back(pos);
            data = cmatch.suffix();
        }
        for (std::shared_ptr<ECS::Systems::Collider> coll : this->mapManager->getColliders()) {
            for (Vector2 pos : collPos) {
                Rectangle rect = coll->getRect();
                if (rect.x == pos.x && rect.y == pos.y) {
                    coll->setIsActive(false);
                }
            }
        }
    }

    void GameScene::parseWallDrawable(std::smatch match, bool isSave)
    {
        const std::regex ta_regex(WALL_REGEX);
        std::smatch wmatch;
        std::string data = match[4];
        std::vector<Vector3> wallsPos;

        while (regex_search(data, wmatch, ta_regex)) {
            Vector3 pos = {
                std::stof(wmatch[1]),
                std::stof(wmatch[2]),
                std::stof(wmatch[3])
            };
            wallsPos.push_back(pos);
            data = wmatch.suffix();
        }
        for (std::shared_ptr<Indie::Objects::Interactables::DestroyableWall> wall : this->mapManager->getDestroyableWalls()) {
            bool found = false;
            for (Vector3 pos : wallsPos) {
                if (wall->getPosition() == pos) {
                    wall->setIsActive(false);
                    found = true;
                    break;
                }
            }
            if (!found && isSave) {
                wall->setIsActive(true);
            }
        }
    }

    std::string GameScene::getPowerUpRequest()
    {
        std::string request = "phase=gid" + std::to_string(this->gid) + ";event=powerup;id=" + std::to_string(this->packageId++) + ";message=";
        for (std::shared_ptr<Indie::Objects::Interactables::DestroyableWall> wall : this->mapManager->getDestroyableWalls()) {
            request += std::to_string(wall->getPowerUp()) + ",";
        }
        return (request);
    }

    void GameScene::parsePowerUp(std::smatch match, bool isSave)
    {
        std::string data = match[4];
        const std::regex ta_regex(POWER_UP_REGEX);
        std::smatch pmatch;
        std::vector<int> values;
        int index = 0;

        while (regex_search(data, pmatch, ta_regex)) {
            int value = std::stoi(pmatch[1]);
            values.push_back(value);
            data = pmatch.suffix();
        }

        static bool alreadyDone = false;
        if (!alreadyDone) {
            alreadyDone = true;
            for (int i : values) {
                this->mapManager->getDestroyableWall(index)->setPowerUp(i);
                index++;
            }
        }
        int id = 0;
        if (isSave) {
            for (std::shared_ptr<Indie::Objects::Interactables::DestroyableWall> wall : this->mapManager->getDestroyableWalls()) {
                wall->setPowerUp(values[id++]);
            }
        }
    }

    void GameScene::init()
    {
        this->currentGamePhase = START_INTRO;
        this->mapManager = std::make_unique<Objects::MapManager>("assets/maps/map1/map1", this->_players_info);
        Vector2 pos = {550, 10};
        this->timer = std::make_unique<ECS::Components::Timer>(pos);
        if (this->saveIndex != 0) {
            Indie::Utils::FileManager fm;
            std::string content = fm.read("save" + std::to_string(this->saveIndex) + ".txt");
            this->loadSave(content);
        }
        this->music->restart();
        this->music->play();
        this->gameIntro.init();
        this->gameOutro.init();
    }

    void GameScene::drawUnder2D()
    {
        if (this->currentGamePhase != END) {
            this->mapManager->drawUnder();
        }
    }

    void GameScene::drawOver2D()
    {
        if (this->currentGamePhase != END) {
            if (this->currentGamePhase == START_INTRO) {
                this->gameIntro.draw();
            } else if (this->currentGamePhase == END_INTRO) {
                this->gameOutro.draw();
            } else if (this->currentGamePhase == GAME) {
                this->mapManager->drawOver();
            }
            this->timer->draw();
        }
    }

    void GameScene::draw3D()
    {
        if (this->currentGamePhase != END) {
            this->mapManager->drawAll();
        }
    }

    void GameScene::writeSaveInFile(std::string filename)
    {
        std::string players = this->getPlayerRequest();
        std::string walls = this->getWallColliderRequest();
        std::string wallsDrawable = this->getWallDrawableRequest();
        std::string bombs = this->getBombRequest();
        std::string powerups = this->getPowerUpRequest();
        Indie::Utils::FileManager fm;
        fm.write(filename, 
            players + "\n" + 
            walls + "\n" +
            wallsDrawable + "\n" +
            bombs + "\n" +
            powerups
        );
    }

    void GameScene::update()
    {
        this->music->update();
        if (this->currentGamePhase == START_INTRO) {
            if (this->gameIntro.update()) {
                this->currentGamePhase = GAME;
                this->timer->start(3);
            }
        } else if (this->currentGamePhase == GAME) {
            if (event.isKey(Lib::MyEvent::DOWN, KEY_P)) {
                this->changingScene = PAUSE;
                this->currentGamePhase = PAUSEGAME;
                this->timer->pause();
                std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>> bombs = this->mapManager->getBombs();
                for (int i = 0; i < bombs.size(); i++) {
                    bombs[i]->pauseBomb();
                }
                return;
            }
            this->mapManager->update();
            this->timer->update();
            int status = this->mapManager->checkStatus();
            if (this->timer->hasFinished() || status != -1) {
                this->gameOutro.setWinner(status, this->mapManager->getPlayerPosition(status));
                this->currentGamePhase = END_INTRO;
            }
            if (event.isKey(Lib::MyEvent::DOWN, KEY_F1)) {
                this->writeSaveInFile("save1.txt");
            }
            if (event.isKey(Lib::MyEvent::DOWN, KEY_F2)) {
                this->writeSaveInFile("save2.txt");
            }
            if (event.isKey(Lib::MyEvent::DOWN, KEY_F3)) {
                this->writeSaveInFile("save3.txt");
            }
        } else if (this->currentGamePhase == END_INTRO) {
            if (this->gameOutro.update()) {
                this->currentGamePhase = END;
                this->changingScene = MENU;
            }
        } else if (this->currentGamePhase == PAUSEGAME) {
            this->timer->relaunch();
            this->currentGamePhase = GAME;
            std::vector<std::shared_ptr<Indie::Objects::Interactables::Bomb>> bombs = this->mapManager->getBombs();
            for (int i = 0; i < bombs.size(); i++) {
                bombs[i]->resumeBomb();
            }
        }
        this->mapManager->updatePlayerAnimations();
    }

    void GameScene::loadSave(std::string content)
    {
        if (content.empty())
            return;
        const std::regex ta_regex(SAVE_REGEX);
        std::smatch pmatch;

        if (regex_search(content, pmatch, ta_regex)) {
            for (int i = 1; i < 6; i++) {
                std::string data = pmatch[i];
                const std::regex req_regex(REQUEST_REGEX);
                std::smatch match;
                if (regex_search(data, match, req_regex)) {
                    const std::string phase = match[1];
                    const std::string event = match[2];
                    const std::string id = match[3];
                    if (this->eventMap.find(event) != this->eventMap.end()) {
                        (this->*eventMap[event])(match, true);
                    }
                }
            }
        }
        this->mapManager->updatePlayerAnimations();
    }
}
