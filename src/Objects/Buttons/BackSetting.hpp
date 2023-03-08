/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** BackSetting
*/

#ifndef BACKSETTING_HPP_
    #define BACKSETTING_HPP_

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::BackSetting : public ECS::Components::AButton {
    public:
        BackSetting();
        ~BackSetting();
        void update();
    private:
        bool is_move;
        float scale;
};


#endif /* !BACKSETTING_HPP_ */
