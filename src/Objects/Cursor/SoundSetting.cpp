/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Sound
*/

#include "SoundSetting.hpp"

namespace  Indie::Objects::Cursor {
    SoundBarre::SoundBarre()
    : ACursor("Sound", {250, 200}, {30, 30}, {10, 10}, 30, BLACK, "assets/setting/soundSetting.png", {0,0, 731, 84} , 1, "assets/setting/cursor.png", {400, 28}, {0, 0, 33, 34}, 1)
    {
        this->scale = 1;
        this->posSave = this->getCursorPos();
        this->audio = std::make_unique<Lib::Audio::MyAudio>(false);
        this->audio->setVolumeAudio(0.5f);
    }

    SoundBarre::~SoundBarre()
    {}

    void SoundBarre::update()
    {
        Vector2 pos = this->getCursorPos();

        this->ACursor::update();
        if (this->isOver()) {
            this->setRect({731 * scale, 0, 731 * scale, 84 * scale});
            this->setPosCursor({pos.x, 27});
            this->cursorMove({240, 30, 620, 30});
            if (this->isClick()) {
                this->posSave = this->getCursorPos();
                this->audio->setVolumeAudio((this->getCursorPos().x - 240) / 380);
            }
        } else {
            this->setRect({0, 0, 731 * scale, 84 * scale});
            this->setPosCursor({this->posSave.x, 28});
        }
    }
}
