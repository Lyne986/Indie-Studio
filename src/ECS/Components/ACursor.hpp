/*
** EPITECH PROJECT, 2021
** project
** File description:
** ACURSOR.hpp
*/

#ifndef __A_CURSOR_HPP__
    #define __A_CURSOR_HPP__

    #include "../ECS_namespace.hpp"
    #include "../Systems/Movable2D.hpp"
    #include "../Systems/Object2D.hpp"
    #include "../Systems/Clickable.hpp"
    #include "../Systems/Drawable.hpp"

class Indie::ECS::Components::ACursor :
public Systems::Object2D,
public Systems::Clickable,
public Systems::Movable2D,
public Systems::Drawable {
    private:
        Indie::Lib::MyText text;
        std::unique_ptr<Indie::Lib::MyTexture> bg = nullptr;
        std::unique_ptr<Indie::Lib::MyTexture> cursor = nullptr;
        Rectangle rect;
        Rectangle logo_rect;
        float scale;
        float logo_scale;
        Vector2 text_pos;
        Vector2 logo_pos;

    public:
    // Constructor / Destructor
        ACursor(std::string content="", Vector2 pos={0,0}, Vector2 text_pos={0,0}, Vector2 dim={0,0}, int fontSize=42, Color color=BLACK, std::string bg="", Rectangle rect={0,0,0,0}, float scale=1, std::string logo="", Vector2 logo_pos={0, 0}, Rectangle logo_rect={0, 0, 0, 0}, float logo_scale=1);
        virtual ~ACursor() = default;

    // Useful functions
        void draw() const;
        void update();
        void init();

    // Getter / Setter
        void setRect(Rectangle rect);
        Rectangle getRect() const;

        void setPosCursor(Vector2 cursor_pos);
        Vector2 getCursorPos() const;
        void cursorMove(Rectangle rect);
        void cursorMoveFps(Rectangle rect);

};

#endif