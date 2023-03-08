/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyImage.cpp
*/

#include "MyImage.hpp"

namespace Indie::Lib {
    MyImage::MyImage(std::string path)
    {
        this->image = LoadImage(path.c_str());
    }

    MyImage::~MyImage()
    {
        UnloadImage(this->image);
    }

    Image MyImage::getImage() const
    {
        return (this->image);
    }
}