/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** ACursor
*/

#include "ACursor.hpp"

namespace Indie::ECS::Components {
    ACursor::ACursor(std::string content, Vector2 pos, Vector2 text_pos, Vector2 dim, int fontSize, Color color, std::string bg, Rectangle rect, float scale, std::string cursor, Vector2 logo_pos, Rectangle logo_rect, float logo_scale) :
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
        if (cursor != "") {
            this->cursor = std::make_unique<Lib::MyTexture>(cursor);
            this->cursor->setScale(logo_scale);
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
    }

    void ACursor::draw() const
    {
        Vector2 pos_txt = {this->text_pos.x + this->pos.get()->x, this->text_pos.y + this->pos.get()->y};
        Vector2 pos_logo = {this->logo_pos.x + this->pos.get()->x, this->logo_pos.y + this->pos.get()->y};
        if (this->bg) {
            if (this->rect.width != 0 && this->rect.height != 0) {
                this->bg->drawRect(*this->pos, this->rect);
            } else
                this->bg->draw(*this->pos);
        }
        if (this->cursor) {
            this->cursor->drawRect(pos_logo, this->logo_rect);
        }
        this->text.draw(pos_txt);
    }

    void ACursor::init() {}

    void ACursor::update() {}

    void ACursor::setRect(Rectangle rect)
    {
        this->rect = rect;
        this->dim.get()->x = rect.width;
        this->dim.get()->y = rect.height;
    }

    void ACursor::cursorMove(Rectangle rect)
    {
        Vector2 mPos = event.getMousePosition();

        if (this->logo_pos.x >= rect.x && this->logo_pos.x <= rect.width) {
            if (mPos.x - this->pos.get()->x - (this->logo_rect.width / 2) < rect.x) {
                this->logo_pos.x = rect.x;
            } else if (mPos.x - this->pos.get()->x > rect.width) {
                this->logo_pos.x = rect.width;
            } else {
                this->logo_pos.x = (mPos.x - this->pos.get()->x) - (this->logo_rect.width / 2);
            }
        }
    }

    void ACursor::cursorMoveFps(Rectangle rect)
    {
        Vector2 mPos = event.getMousePosition();

        if (this->logo_pos.x >= rect.x && this->logo_pos.x <= rect.width) {
            if (mPos.x - this->pos.get()->x - (this->logo_rect.width / 2) <= 335) {
                this->logo_pos.x = rect.x;
                Lib::MyWindow::setFps(30);
            } else if (mPos.x - this->pos.get()->x >= 525) {
                this->logo_pos.x = rect.width;
                Lib::MyWindow::setFps(120);
            } else {
                this->logo_pos.x = 430;
                Lib::MyWindow::setFps(60);
            }
        }
    }
    Vector2 ACursor::getCursorPos() const
    {
        return (this->logo_pos);
    }

    void ACursor::setPosCursor(Vector2 cursor_pos)
    {
        this->logo_pos = cursor_pos;
    }

    Rectangle ACursor::getRect() const
    {
        return this->rect;
    }
}