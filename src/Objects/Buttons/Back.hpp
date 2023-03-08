/*
** EPITECH PROJECT, 2021
** project
** File description:
** Back.hpp
*/

#ifndef __BACK_BUTTON_HPP__
    #define __BACK_BUTTON_HPP__

    #include "../../Scenes/Scenes.hpp"
    #include "../Objects_namespace.hpp"

class Indie::Objects::Button::Back : public ECS::Components::AButton {
    public:
        Back(Vector2 pos, Indie::Scenes::Scenes scene);
        ~Back();
        void update();
        Indie::Scenes::Scenes getScene() const;
        void setScene(Indie::Scenes::Scenes scene);

    private:
        float scale;
        Indie::Scenes::Scenes changingScene;
};

#endif
