/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyRectangle.hpp
*/

#ifndef __LIB_MY_RECTANGLE_HPP__
    #define __LIB_MY_RECTANGLE_HPP__

    #include "../Lib_namespace.hpp"

class Indie::Lib::Shapes::MyRectangle {
    private:
        Rectangle rectangle;

    public:
    // Constructor / Destructor
        MyRectangle(float x, float y, float width, float height);

    // Useful functions
        void updateRec(float x, float y, float width, float height);
        bool checkCollisionRecs(Rectangle rec) const;

    // Getter / Setter
        Rectangle getRectangle() const;
};

#endif