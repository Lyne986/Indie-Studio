/*
** EPITECH PROJECT, 2021
** project
** File description:
** MyText.cpp
*/

#include "MyText.hpp"

namespace Indie::Lib {
    MyText::MyText(std::string content, int fontSize, Color color)
    {
        this->content = content;
        this->fontSize = fontSize;
        this->color = color;
    }

    void MyText::draw(Vector2 position) const
    {
        DrawText(this->content.c_str(), position.x, position.y, this->fontSize, this->color);
    }

    void MyText::setContent(std::string content)
    {
        this->content = content;
    }

    void MyText::setColor(Color color)
    {
        this->color = color;
    }
}