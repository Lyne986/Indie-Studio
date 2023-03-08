/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyWindow.cpp
*/

#include "MyWindow.hpp"

namespace Indie::Lib {
    MyWindow::MyWindow(unsigned int width, unsigned int height, std::string title, unsigned int fps)
    {
        this->width = width;
        this->height = height;
        this->title = title;
        InitWindow(width, height, title.c_str());
        this->setFps(fps);
    }

    MyWindow::~MyWindow()
    {
        CloseWindow();
    }

    bool MyWindow::isOpen() const
    {
        return (!WindowShouldClose());
    }

    void MyWindow::clear() const
    {
        BeginDrawing();
        ClearBackground(this->bgColor);
    }

    void MyWindow::display() const
    {
        EndDrawing();
    }

    unsigned int MyWindow::getWidth() const
    {
        return (this->width);
    }

    unsigned int MyWindow::getHeight() const
    {
        return (this->height);
    }

    unsigned int MyWindow::getFps()
    {
        return (GetFPS());
    }

    void MyWindow::setFps(unsigned int fps)
    {
        SetTargetFPS(fps);
    }

    void MyWindow::setBgColor(Color color)
    {
        this->bgColor = color;
    }

    void MyWindow::setBgColor(unsigned char r, unsigned char g, unsigned char b)
    {
        this->bgColor = {r, g, b};
    }

    Color MyWindow::getBgColor() const
    {
        return (this->bgColor);
    }

    std::string MyWindow::getTitle() const
    {
        return (this->title);
    }

    float MyWindow::getFrameTime()
    {
        return GetFrameTime();
    }
    
    void MyWindow::setIcon(std::string path)
    {
        MyImage icon(path);
        SetWindowIcon(icon.getImage());
    }
}
