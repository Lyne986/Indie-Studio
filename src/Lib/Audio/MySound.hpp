/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MySound.hpp
*/

#ifndef __LIB_MY_SOUND_HPP__
    #define __LIB_MY_SOUND_HPP__

    #include "../Lib_namespace.hpp"

class Indie::Lib::Audio::MySound {
    private:
        Sound sound;

    public:
    // Constructor / Destructor
        MySound(std::string path);
        ~MySound();

    // Useful functions
        void play() const;

    // Getter / Setter
        Sound getSound() const;
        void setVolume(float volume);
};

#endif