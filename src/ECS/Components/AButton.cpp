/*
** EPITECH PROJECT, 2021
** project
** File description:
** Text.cpp
*/

#include "AButton.hpp"

namespace Indie::ECS::Components {
    AButton::AButton(std::string content, Vector2 pos, Vector2 text_pos, Vector2 dim, int fontSize, Color color, std::string bg, Rectangle rect, float scale, std::string logo, Vector2 logo_pos, Rectangle logo_rect, float logo_scale) :
    text(content, fontSize, color),
    Object2D(pos, dim),
    Clickable(this->pos, this->dim),
    Movable2D(this->pos)
    {
        this->text_pos = text_pos;
        this->scale = scale;
        this->logo_pos = logo_pos;
        this->logo_scale = logo_scale;
        this->logo_rect = logo_rect;
        if (bg != "") {
            this->bg = std::make_unique<Lib::MyTexture>(bg);
            this->bg->setScale(this->scale);
        }
        if (logo != "") {
            this->logo = std::make_unique<Lib::MyTexture>(logo);
            this->logo->setScale(logo_scale);
            this->logo_rect.width *= this->logo_scale;
            this->logo_rect.height *= this->logo_scale;
            this->logo_rect.x *= this->logo_scale;
            this->logo_rect.y *= this->logo_scale;
        }
        rect.width *= this->scale;
        rect.height *= this->scale;
        rect.x *= this->scale;
        rect.y *= this->scale;
        this->rect = rect;
        this->dim.get()->x *= this->scale;
        this->dim.get()->y *= this->scale;
        this->sfx = nullptr;
    }

    void AButton::draw() const
    {
        Vector2 pos_txt = {this->text_pos.x + this->pos.get()->x, this->text_pos.y + this->pos.get()->y};
        Vector2 pos_logo = {this->logo_pos.x + this->pos.get()->x, this->logo_pos.y + this->pos.get()->y};
        if (this->bg) {
            if (this->rect.width != 0 && this->rect.height != 0) {
                this->bg->drawRect(*this->pos, this->rect);
            } else
                this->bg->draw(*this->pos);
        }
        if (this->logo) {
            this->logo->drawRect(pos_logo, this->logo_rect);
        }
        this->text.draw(pos_txt);
    }

    void AButton::init() {}

    void AButton::update()
    {
        if (this->sfx && this->isClick()) {
            this->sfx->play();
        }
    }

    void AButton::setSfx(std::string path)
    {
        this->sfx = std::make_unique<Lib::Audio::MySound>(path);
        this->sfx->setVolume(1.0f);
    }

    void AButton::setRect(Rectangle rect)
    {
        this->rect = rect;
        this->dim.get()->x = rect.width;
        this->dim.get()->y = rect.height;
    }

    Rectangle AButton::getRect() const
    {
        return this->rect;
    }

    void AButton::setLogoRect(Rectangle rect)
    {
        this->logo_rect = rect;
        this->logo_rect.width *= this->logo_scale;
        this->logo_rect.height *= this->logo_scale;
        this->logo_rect.x *= this->logo_scale;
        this->logo_rect.y *= this->logo_scale;
    }

    void AButton::setTextColor(Color Color)
    {
        this->text.setColor(Color);
    }

    void AButton::setText(std::string text)
    {
        this->text.setContent(text);
    }
}