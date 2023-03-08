/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyEasing.hpp
*/

#ifndef __LIB_MY_EASING_HPP__
    #define __LIB_MY_EASING_HPP__

    #include "Lib_namespace.hpp"
    #include "raymath.h"

class Indie::Lib::MyEasing {
    public:

        typedef enum {
            IN,
            OUT,
            INOUT
        } EaseType;

    // Constructor / Destructor
        MyEasing();
        ~MyEasing();

    // Useful functions
        float easeElastic(EaseType easeType, float t, float a, float b, float maxT);
        float easeCubic(EaseType easeType, float t, float a, float b, float maxT);
        Color colorFromAlpha(Color color, float alpha);
        float lerp(float start, float end, float amount);
};

#endif