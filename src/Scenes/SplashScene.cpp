/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** SplashScene.cpp
*/

#include "SplashScene.hpp"

namespace Indie::Scenes {
    SplashScene::SplashScene()
    {
        this->splash = std::make_unique<Lib::MyTexture>("assets/splashEpitech.png");
        this->pos = {200, 300};
    }

    void SplashScene::init()
    {
        this->alphaValue = 0;
        this->framesCounter = 0;
        this->currentState = IN_SPLASH;
    }

    void SplashScene::update()
    {
        this->framesCounter++;
        if (this->currentState == IN_SPLASH) {
            this->alphaValue = this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 75);
            this->splash->setColor(this->myEasing.colorFromAlpha(WHITE, this->alphaValue));
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = OUT_SPLASH;
            }
        } else if (this->currentState == OUT_SPLASH) {
            this->alphaValue = this->myEasing.easeCubic(Lib::MyEasing::INOUT, this->framesCounter, 0, 1, 75);
            this->splash->setColor(this->myEasing.colorFromAlpha(WHITE, 1 - this->alphaValue));
            if (this->framesCounter >= 50) {
                this->framesCounter = 0;
                this->currentState = END;
            }
        } else if (this->currentState == END) {
            this->changingScene = MENU;
        }
    }

    void SplashScene::drawOver2D()
    {
        this->splash->draw(this->pos);
    }
}