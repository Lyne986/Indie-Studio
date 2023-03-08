/*
** EPITECH PROJECT, 2021
** project
** File description:
** AButton.hpp
*/

#ifndef __A_BUTTON_HPP__
    #define __A_BUTTON_HPP__

    #include "../ECS_namespace.hpp"
    #include "../Systems/Movable2D.hpp"
    #include "../Systems/Object2D.hpp"
    #include "../Systems/Clickable.hpp"
    #include "../Systems/Drawable.hpp"

class Indie::ECS::Components::AButton :
public Systems::Object2D,
public Systems::Clickable,
public Systems::Movable2D,
public Systems::Drawable {
    private:
        std::unique_ptr<Lib::Audio::MySound> sfx;
        Indie::Lib::MyText text;
        std::unique_ptr<Indie::Lib::MyTexture> bg = nullptr;
        std::unique_ptr<Indie::Lib::MyTexture> logo = nullptr;
        Rectangle rect;
        Rectangle logo_rect;
        float scale;
        float logo_scale;
        Vector2 text_pos;
        Vector2 logo_pos;


    public:
    // Constructor / Destructor
        AButton(std::string content="", Vector2 pos={0,0}, Vector2 text_pos={0,0}, Vector2 dim={0,0}, int fontSize=42, Color color=BLACK, std::string bg="", Rectangle rect={0,0,0,0}, float scale=1, std::string logo="", Vector2 logo_pos={0, 0}, Rectangle logo_rect={0, 0, 0, 0}, float logo_scale=1);
        virtual ~AButton() = default;

    // Useful functions
        void init();
        void draw() const;
        void update();

    // Getter / Setter
        void setSfx(std::string path);
        void setRect(Rectangle rect);
        Rectangle getRect() const;
        void setTextColor(Color Color);
        void setLogoRect(Rectangle rect);
        void setText(std::string text);
};

#endif