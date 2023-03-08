/*
** EPITECH PROJECT, 2021
** INDIE
** File description:
** MyTransform.hpp
*/

#ifndef __LIB_MY_TRANSFORM_HPP__
    #define __LIB_MY_TRANSFORM_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyTransform {
    public:
    // Constructor / Destructor
        MyTransform();
        ~MyTransform();

    // Useful functions
        void rotate(float angle, float x, float y, float z) const;
        void translate(Vector3 currentPos, Vector3 targetPos) const;
        void pushMatrix() const;
        void popMatrix() const;
};

#endif