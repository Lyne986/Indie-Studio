/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyMusic.hpp
*/

#ifndef __LIB_MY_MUSIC_HPP__
    #define __LIB_MY_MUSIC_HPP__

    #include "../Lib_namespace.hpp"

class Indie::Lib::Audio::MyMusic {
    private:
        Music music;

    public:
    // Constructor / Destructor
        MyMusic(std::string path);
        ~MyMusic();

    // Useful functions
        void update();
        void play();
        void pause();
        void stop();
        void restart();

    // Getter / Setter
        void setVolume(float volume);
        Music getMusic() const;
};

#endif