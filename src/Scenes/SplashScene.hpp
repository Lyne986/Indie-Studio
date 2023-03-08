/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** SplashScene.hpp
*/

#ifndef _SPLASH_SCENE_HPP_
    #define _SPLASH_SCENE_HPP_

    #include "SceneNamespace.hpp"
    #include "AScene.hpp"
    #include <memory>

class Indie::Scenes::SplashScene : public Indie::Scenes::AScene {
    public:
        SplashScene();
        void init();
        void update();
        void drawOver2D();

    private:
        Lib::MyEasing myEasing;
        std::unique_ptr<Indie::Lib::MyTexture> splash;
        float alphaValue;
        int framesCounter;

        typedef enum {
            IN_SPLASH,
            OUT_SPLASH,
            END
        } State;

        State currentState;
        Vector2 pos;
};

#endif /* !_SPLASH_SCENE_HPP_ */