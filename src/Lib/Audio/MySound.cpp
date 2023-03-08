/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MySound.cpp
*/

#include "MySound.hpp"

namespace Indie::Lib::Audio {
    MySound::MySound(std::string path)
    {
        this->sound = LoadSound(path.c_str());
    }

    MySound::~MySound()
    {
        UnloadSound(this->sound);
    }

    void MySound::play() const
    {
        PlaySoundMulti(this->sound);
    }

    void MySound::setVolume(float volume)
    {
        SetSoundVolume(this->sound, volume);
    }

    Sound MySound::getSound() const
    {
        return this->sound;
    }
}