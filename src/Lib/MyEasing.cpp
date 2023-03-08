/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyAnimation.cpp
*/

#include "MyEasing.hpp"

namespace Indie::Lib {
    MyEasing::MyEasing()
    {

    }

    MyEasing::~MyEasing()
    {

    }

    float MyEasing::easeElastic(EaseType easeType, float t, float a, float b, float maxT)
    {
        if (easeType == IN) {
            return EaseElasticIn(t, a, b, maxT);
        } else if (easeType == OUT) {
            return EaseElasticOut(t, a, b, maxT);
        } else {
            return EaseElasticInOut(t, a, b, maxT);
        }
    }
    float MyEasing::easeCubic(EaseType easeType, float t, float a, float b, float maxT)
    {
        if (easeType == IN) {
            return EaseCubicIn(t, a, b, maxT);
        } else if (easeType == OUT) {
            return EaseCubicOut(t, a, b, maxT);
        } else {
            return EaseCubicInOut(t, a, b, maxT);
        }
    }

    Color MyEasing::colorFromAlpha(Color color, float alpha)
    {
        return ColorAlpha(color, alpha);
    }

    float MyEasing::lerp(float start, float end, float amount)
    {
        return Lerp(start, end, amount);
    }
};