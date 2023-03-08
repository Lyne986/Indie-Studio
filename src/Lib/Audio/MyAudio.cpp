/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyAudio.cpp
*/

#include "MyAudio.hpp"

namespace Indie::Lib::Audio {
    MyAudio::MyAudio(bool init)
    {
        if (init) {
            InitAudioDevice();
        }
    }

    void MyAudio::setVolumeAudio(float volume)
    {
        SetMasterVolume(volume);
    }

    MyAudio::~MyAudio()
    {
        CloseAudioDevice();
    }
};
