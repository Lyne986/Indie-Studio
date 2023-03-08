/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** GameOutro.cpp
*/

#ifndef __GAME_OUTRO_HPP__
    #define __GAME_OUTRO_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Animations::GameOutro {
    private:
        std::shared_ptr<Lib::MyCamera> camera;
        std::unique_ptr<Lib::Audio::MySound> gameEndSfx;
        bool playedSfx;
        Lib::MyEasing myEasing;
        std::unique_ptr<Lib::MyTexture> bg;
        std::unique_ptr<Lib::MyTexture> strip;
        std::unique_ptr<Lib::MyText> text;
        Vector2 stripPos;
        Vector2 textPos;
        Vector2 bgPos;
        float framesCounter;
        float stripValue;
        float alphaValue;
        float textValue;

        typedef enum {
            IN_STRIPE,
            IN_WINNER,
            OUT_WINNER,
            OUT_STRIPE,
            FADE_OUT,
            PAUSE,
            END
        } State;

        State currentState;

        typedef enum {
            TARGET,
            FOV,
            CAM_END
        } CamState;

        CamState camState;
        Vector3 startTarget;
        Vector3 targetPos;
        float startFov;
        float camsCounter;
        int winnerId;
        void updateCamera();

    public:
    // Constructor / Destructor
        GameOutro();
        ~GameOutro();

    // Useful functions
        void init();
        bool update();
        void draw();
        void setWinner(int winnerId, Vector3 pos);
};

#endif