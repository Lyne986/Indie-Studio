/*
** EPITECH PROJECT, 2021
** project
** File description:
** Text.hpp
*/

#ifndef _LIB_MY_TEXT_HPP__
    #define _LIB_MY_TEXT_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyText {
    private:
        std::string content;
        int fontSize;
        Color color;

    public:
    // Constructor / Destructor
        MyText(std::string content = "", int fontSize = 42, Color color = BLACK);

    // Useful functions
        void draw(Vector2 position) const;

    // Getter / Setter
        void setContent(std::string content);
        void setColor(Color color);
};

#endif