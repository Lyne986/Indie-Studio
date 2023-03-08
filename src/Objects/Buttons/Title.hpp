/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Title
*/

#ifndef TITLE_HPP_
#define TITLE_HPP_

    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Title : public ECS::Components::AButton {
    public:
        Title(std::string content);
        ~Title();
        void update();
    private:
        bool is_move;
        float scale;
};

#endif /* !TITLE_HPP_ */
