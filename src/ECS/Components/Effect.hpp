/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Effect.hpp
*/

#ifndef __EFFECT_HPP__
    #define __EFFECT_HPP__

    #include "../ECS_namespace.hpp"
    #include "../Systems/Drawable.hpp"
    #include "../Systems/Object2D.hpp"

class Indie::ECS::Components::Effect :
public Lib::MyTexture,
public Systems::Object2D,
public Systems::Drawable {
    private:
        int nbLines;
        int nbCols;
        float frameWidth;
        float frameHeight;
        int currentCol;
        int currentLine;
        Rectangle frameRec;
        bool done;

    public:
    // Constructor / Destructor
        Effect(std::string texturePath, Vector2 pos, int nbLines, int nbCols);
        ~Effect();
        void init();
        void update();
        void draw() const;
};

#endif