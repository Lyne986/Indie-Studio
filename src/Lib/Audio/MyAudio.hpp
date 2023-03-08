/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyAudio.hpp
*/

#ifndef __LIB_MY_AUDIO_HPP__
    #define __LIB_MY_AUDIO_HPP__

    #include "../Lib_namespace.hpp"

class Indie::Lib::Audio::MyAudio {
    public:
    // Constructor / Destructor
        MyAudio(bool init);
        ~MyAudio();

    // Utiles
        void setVolumeAudio(float volume);
};

#endif