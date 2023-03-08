/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** GameOutro.cpp
*/

#include "GameOutro.hpp"

namespace Indie::Objects::Animations {

    GameOutro::GameOutro()
    {
        this->camera = Lib::MyCamera::getInstance();
    }

    GameOutro::~GameOutro() {}

    void GameOutro::init()
    {
        this->strip = std::make_unique<Lib::MyTexture>("assets/startStrip.png");
        this->bg = std::make_unique<Lib::MyTexture>("assets/black_background.png");
        this->bgPos = {0, 0};
        this->text = std::make_unique<Lib::MyText>("", 100, WHITE);
        this->gameEndSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/gameEnd.wav");
        this->currentState = IN_STRIPE;
        this->framesCounter = 0;
        this->bg->setColor(this->myEasing.colorFromAlpha(WHITE, 0));
        this->textPos = {1200, 400};
        this->gameEndSfx->setVolume(1);
        this->playedSfx = false;
        this->camsCounter = 0;
        this->camState = TARGET;
    }

    bool GameOutro::update()
    {
        if (!this->playedSfx) {
            this->playedSfx = true;
            this->gameEndSfx->play();
        }

        if (this->winnerId > 0) {
            this->updateCamera();
        }
        this->framesCounter++;
        if (this->currentState == IN_STRIPE) {
            this->stripValue = this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 50);
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = IN_WINNER;
            }
        } else if (this->currentState == IN_WINNER) {
            this->textValue = this->myEasing.easeCubic(Lib::MyEasing::OUT, this->framesCounter, 0, 900, 50);
            this->textPos.x = 1200 - this->textValue;
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = OUT_WINNER;
            }
        } else if (this->currentState == OUT_WINNER) {
            this->textValue = this->myEasing.easeCubic(Lib::MyEasing::IN, this->framesCounter, 0, 1500, 50);
            this->textPos.x = 300 - this->textValue;
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = OUT_STRIPE;
            }
        } else if (this->currentState == OUT_STRIPE) {
            this->stripValue = 1 - this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 50);
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = PAUSE;
            }
        } else if (this->currentState == PAUSE) {
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = FADE_OUT;
            }
        } else if (this->currentState == FADE_OUT) {
            this->alphaValue = this->myEasing.easeCubic(Lib::MyEasing::OUT, this->framesCounter, 0, 1, 50);
            this->bg->setColor(this->myEasing.colorFromAlpha(WHITE, this->alphaValue));
            if (this->framesCounter >= 50) {
                this->camera->setTarget(this->startTarget);
                this->camera->setFov(this->startFov);
                this->currentState = END;
                return true;
            }
        }
        return false;
    }

    void GameOutro::updateCamera()
    {
        Vector3 newTarget = {0, 0, 0};

        this->camsCounter++;
        if (this->camState == TARGET) {
            newTarget.x = this->myEasing.lerp(this->startTarget.x, this->targetPos.x, this->camsCounter / 40);
            newTarget.y = this->myEasing.lerp(this->startTarget.y, this->targetPos.y, this->camsCounter / 40);
            newTarget.z = this->myEasing.lerp(this->startTarget.z, this->targetPos.z, this->camsCounter / 40);
            this->camera->setTarget(newTarget);
            if (this->camsCounter >= 40) {
                this->camsCounter = 0;
                this->camState = FOV;
            }
        } else if (this->camState == FOV) {
            float fov = this->myEasing.lerp(this->startFov, 10, this->camsCounter / 60);
            this->camera->setFov(fov);
            if (this->camsCounter >= 40) {
                this->camsCounter = 0;
                this->camState = CAM_END;
            }
        }
    }

    void GameOutro::draw()
    {
        if (this->currentState == IN_STRIPE || this->currentState == OUT_STRIPE) {
            this->stripPos.x = 600 - ((this->strip->getTexture().width * this->stripValue) / 2);
            this->stripPos.y = 450 - ((this->strip->getTexture().height * this->stripValue) / 2);
        }
        this->strip->drawEx(this->stripPos, 0, this->stripValue);
        this->text->draw(this->textPos);
        if (this->currentState == FADE_OUT || this->currentState == END) {
            this->bg->draw(this->bgPos);
        }
    }

    void GameOutro::setWinner(int playerId, Vector3 pos)
    {
        this->startTarget = this->camera->getTarget();
        this->startFov = this->camera->getFov();
        this->targetPos = pos;
        this->winnerId = playerId;
        if (this->winnerId == -1 || this->winnerId == 0) {
            this->text->setContent("IT'S A TIE!");
        } else {
            this->text->setContent("PLAYER " + std::to_string(this->winnerId) + " WINS!");
        }
    }
};
