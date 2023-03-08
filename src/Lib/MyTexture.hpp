/*
** EPITECH PROJECT, 2021
** project
** File description:
** MyTexture.hpp
*/

#ifndef __LIB_MY_TEXTURE_HPP__
    #define __LIB_MY_TEXTURE_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyTexture {
    protected:
        Texture2D texture;
        Color color;

    public:
        // Constructor / Destructor
        MyTexture(std::string path);
        MyTexture(Image image);
        MyTexture();
        ~MyTexture();

        // Useful functions
        void draw(Vector2 position) const;
        void drawEx(Vector2 position, float rotation, float scale) const;
        void drawRect(Vector2 position, Rectangle rec) const;
        void LoadNewTextureFromPath(std::string texturePath);
        void LoadNewTextureFromImage(Image image);

        // Getter / Setter
        Texture2D getTexture() const;
        void setScale(float scale);
        void setColor(Color color);
};

#endif