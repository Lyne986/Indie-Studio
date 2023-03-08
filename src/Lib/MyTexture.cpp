/*
** EPITECH PROJECT, 2021
** project
** File description:
** MyTexture.cpp
*/

#include "MyTexture.hpp"

namespace Indie::Lib {
    MyTexture::MyTexture(std::string path)
    {
        this->LoadNewTextureFromPath(path);
        this->color = WHITE;
    }

    MyTexture::MyTexture(Image image)
    {
        this->LoadNewTextureFromImage(image);
        this->color = WHITE;
    }

    MyTexture::MyTexture()
    {
    }

    MyTexture::~MyTexture()
    {
        UnloadTexture(this->texture);
    }

    void MyTexture::LoadNewTextureFromPath(std::string texturePath)
    {
        this->texture = LoadTexture(texturePath.c_str());
    }

    void MyTexture::LoadNewTextureFromImage(Image image)
    {
        this->texture = LoadTextureFromImage(image);
    }

    void MyTexture::draw(Vector2 position) const
    {
        DrawTexture(this->texture, position.x, position.y, this->color);
    }

    void MyTexture::drawEx(Vector2 position, float rotation, float scale) const
    {
        DrawTextureEx(this->texture, position, rotation, scale, this->color);
    }

    void MyTexture::drawRect(Vector2 position, Rectangle rec) const
    {
        DrawTextureRec(this->texture, rec, position, this->color);
    }

    Texture2D MyTexture::getTexture() const
    {
        return (this->texture);
    }

    void MyTexture::setScale(float scale)
    {
        this->texture.width = this->texture.width * scale;
        this->texture.height = this->texture.height * scale;
    }

    void MyTexture::setColor(Color color)
    {
        this->color = color;
    }
}