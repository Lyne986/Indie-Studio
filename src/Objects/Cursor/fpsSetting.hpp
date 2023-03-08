/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** FPS
*/

#ifndef FPS_HPP_
    #define FPS_HPP_

    #include "../Objects_namespace.hpp"

class Indie::Objects::Cursor::fpsBarre : public ECS::Components::ACursor {
    public:
        fpsBarre();
        ~fpsBarre();
        void update();

    private:
        float scale;
};

#endif /* !FPS_HPP_ */
