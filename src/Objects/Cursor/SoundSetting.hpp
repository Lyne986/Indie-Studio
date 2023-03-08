/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Sound
*/

#ifndef SOUND_HPP_
    #define SOUND_HPP_

    #include "../Objects_namespace.hpp"

class Indie::Objects::Cursor::SoundBarre : public ECS::Components::ACursor {
    public:
        SoundBarre();
        ~SoundBarre();
        void update();

    private:
        float scale;
        Vector2 posSave;
        std::unique_ptr<Indie::Lib::Audio::MyAudio> audio;
};


#endif /* !SOUND_HPP_ */
