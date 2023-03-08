/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyMusic.cpp
*/

#include "MyMusic.hpp"

namespace Indie::Lib::Audio {
    MyMusic::MyMusic(std::string path)
    {
        this->music = LoadMusicStream(path.c_str());
    }

    MyMusic::~MyMusic()
    {
        UnloadMusicStream(this->music);
    }

    void MyMusic::update()
    {
        UpdateMusicStream(this->music);
    }

    void MyMusic::play()
    {
        PlayMusicStream(this->music);
    }

    void MyMusic::pause()
    {
        PauseMusicStream(this->music);
    }

    void MyMusic::stop()
    {
        StopMusicStream(this->music);
    }

    void MyMusic::restart()
    {
        SeekMusicStream(this->music, 0);
    }

    void MyMusic::setVolume(float volume)
    {
        SetMusicVolume(this->music, volume);
    }

    Music MyMusic::getMusic() const
    {
        return this->music;
    }
}