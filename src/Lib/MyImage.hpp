/*
** EPITECH PROJECT, 2021
** INDIE
** File description:
** Sprite.hpp
*/

#ifndef __LIB_MY_IMAGE_HPP__
    #define __LIB_MY_IMAGE_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyImage {
    private:
        Image image;

    public:
    // Constructor / Destructor
        MyImage(std::string path);
        ~MyImage();

    // Getter / Setter
        Image getImage() const;
};

#endif