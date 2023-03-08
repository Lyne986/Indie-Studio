/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** GameIntro.cpp
*/

#ifndef __GAME_INTRO_HPP__
    #define __GAME_INTRO_HPP__

    #include "../Objects_namespace.hpp"

class Indie::Objects::Animations::GameIntro {
    private:
        std::unique_ptr<Lib::Audio::MySound> readySfx;
        std::unique_ptr<Lib::Audio::MySound> goSfx;
        std::unique_ptr<Lib::Audio::MySound> gameStartSfx;
        Lib::MyEasing myEasing;
        std::unique_ptr<Lib::MyTexture> strip;
        std::unique_ptr<Lib::MyText> text;
        Vector2 stripPos;
        Vector2 textPos;
        float framesCounter;
        float stripValue;
        float textValue;

        typedef enum {
            IN_STRIPE,
            IN_READY,
            OUT_READY,
            IN_GO,
            OUT_GO,
            OUT_STRIPE
        } State;

        State currentState;

    public:
    // Constructor / Destructor
        GameIntro();
        ~GameIntro();

    // Useful functions
        void init();
        bool update();
        void draw();
};

#endif