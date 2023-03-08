/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** AnimatedIntro.cpp
*/

#include "GameIntro.hpp"

namespace Indie::Objects::Animations {

    GameIntro::GameIntro() {}

    GameIntro::~GameIntro() {}

    void GameIntro::init()
    {
        this->currentState = IN_STRIPE;
        this->framesCounter = 0;
        this->strip = std::make_unique<Lib::MyTexture>("assets/startStrip.png");
        this->textPos = {1200, 400};
        this->text = std::make_unique<Lib::MyText>("READY?", 100, WHITE);
        this->readySfx = std::make_unique<Lib::Audio::MySound>("assets/audio/ready.wav");
        this->readySfx->setVolume(1);
        this->goSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/go.wav");
        this->goSfx->setVolume(1);
        this->gameStartSfx = std::make_unique<Lib::Audio::MySound>("assets/audio/gameStart.wav");
        this->gameStartSfx->setVolume(1);
    }

    bool GameIntro::update()
    {
        this->framesCounter++;
        if (this->currentState == IN_STRIPE) {
            this->stripValue = this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 50);
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->readySfx->play();
                this->currentState = IN_READY;
            }
        } else if (this->currentState == IN_READY || this->currentState == IN_GO) {
            this->textValue = this->myEasing.easeCubic(Lib::MyEasing::OUT, this->framesCounter, 0, 750, 50);
            this->textPos.x = 1200 - this->textValue;
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                if (this->currentState == IN_READY) {
                    this->currentState = OUT_READY;
                } else {
                    this->currentState = OUT_GO;
                }
            }
        } else if (this->currentState == OUT_READY || this->currentState == OUT_GO) {
            this->textValue = this->myEasing.easeCubic(Lib::MyEasing::IN, this->framesCounter, 0, 1000, 50);
            this->textPos.x = 450 - this->textValue;
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                if (this->currentState == OUT_READY) {
                    this->goSfx->play();
                    this->currentState = IN_GO;
                    this->text->setContent("GO!");
                } else {
                    this->currentState = OUT_STRIPE;
                }
            }
        } else if (this->currentState == OUT_STRIPE) {
            this->stripValue = 1 - this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 50);
            if (this->framesCounter == 20) {
                this->gameStartSfx->play();
            }
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                return true;
            }
        }
        return false;
    }

    void GameIntro::draw()
    {
        if (this->currentState == IN_STRIPE || this->currentState == OUT_STRIPE) {
            this->stripPos.x = 600 - ((this->strip->getTexture().width * this->stripValue) / 2);
            this->stripPos.y = 450 - ((this->strip->getTexture().height * this->stripValue) / 2);
        }
        this->strip->drawEx(this->stripPos, 0, this->stripValue);
        this->text->draw(this->textPos);
    }
};
