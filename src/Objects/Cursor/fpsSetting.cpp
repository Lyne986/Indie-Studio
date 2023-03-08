/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** f
*/

#include "fpsSetting.hpp"

namespace  Indie::Objects::Cursor {
    fpsBarre::fpsBarre()
    : ACursor("Fps", {250, 350}, {30, 30}, {10, 10}, 30, BLACK, "assets/setting/fpsSetting.png", {0,0, 731, 84} , 1, "assets/setting/cursor.png", {430, 28}, {0, 0, 33, 34}, 1)
    {
        this->scale = 1;
    }

    fpsBarre::~fpsBarre()
    {}

    void fpsBarre::update()
    {
        Vector2 pos = this->getCursorPos();

        this->ACursor::update();
        if (this->isOver()) {
            this->setRect({731 * scale, 0, 731 * scale, 84 * scale});
            this->setPosCursor({pos.x, 27});
            this->cursorMoveFps({240, 30, 620, 30});
        } else {
            this->setRect({0, 0, 731 * scale, 84 * scale});
            this->setPosCursor({pos.x, 28});
        }
    }
}
