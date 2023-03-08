/*
** EPITECH PROJECT, 2021
** project
** File description:
** MY_WINDOW.hpp
*/

#ifndef __LIB_MY_WINDOW_HPP__
    #define __LIB_MY_WINDOW_HPP__

    #include "Lib_namespace.hpp"
    #include "MyImage.hpp"
    #include "raylib.h"
    #include <string>

class Indie::Lib::MyWindow {
    private:
    unsigned int width, height;
    std::string title;
    Color bgColor = BLACK;

    public:
    // Constructor / Destructor

        MyWindow(unsigned int width=1200, unsigned int height=900, std::string title="IndieStudio", unsigned int fps=60);
        ~MyWindow();

    // Useful methods
        bool isOpen() const;
        void clear() const;
        void display() const;

    //Getter / Setter

        std::string getTitle() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        static unsigned int getFps();
        static void setFps(unsigned int fps);
        Color getBgColor() const;
        void setBgColor(Color color);
        void setBgColor(unsigned char r, unsigned char g, unsigned char b);
        void setIcon(std::string path);
        static float getFrameTime();
};

#endif
