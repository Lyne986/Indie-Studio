/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Effect.cpp
*/

#include "Effect.hpp"

namespace Indie::ECS::Components {
    Effect::Effect(std::string texturePath, Vector2 pos, int nbLines, int nbCols) :
    MyTexture(texturePath),
    Object2D(pos, {1, 1})
    {
        this->nbLines = nbLines;
        this->nbCols = nbCols;
        this->frameWidth = this->texture.width / this->nbCols;
        this->frameHeight = this->texture.height / this->nbLines;
        this->currentLine = 0;
        this->currentCol = 0;
        this->frameRec = {0, 0, this->frameWidth, this->frameHeight};
        this->pos->x -= this->frameWidth / 2;
        this->pos->y -= this->frameHeight / 2;
        this->done = false;
    }

    Effect::~Effect() {}

    void Effect::init()
    {

    }

    void Effect::update()
    {
        if (!this->done) {
            this->currentCol++;
            if (this->currentCol >= this->nbCols) {
                this->currentCol = 0;
                this->currentLine++;
                if (this->currentLine >= this->nbLines) {
                    this->currentLine = 0;
                    this->done = true;
                }
            }
            this->frameRec.x = this->frameWidth * this->currentCol;
            this->frameRec.y = this->frameHeight * this->currentLine;
        }
    }

    void Effect::draw() const
    {
        if (!this->done) {
            this->drawRect(*this->pos, this->frameRec);
        }
    }
}