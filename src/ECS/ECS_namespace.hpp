/*
** EPITECH PROJECT, 2021
** project
** File description:
** ECS_namespace.hpp
*/

#ifndef __ECS_NAMESPACE_HPP__
    #define __ECS_NAMESPACE_HPP__

    #include "../Lib/Lib_namespace.hpp"
    #include "../Lib/MyWindow.hpp"
    #include "../Lib/MyModel.hpp"
    #include "../Lib/MyTexture.hpp"
    #include "../Lib/MyText.hpp"
    #include "../Lib/MyImage.hpp"
    #include "../Lib/MyMesh.hpp"
    #include "../Lib/MyEvent.hpp"
    #include "../Lib/MyTransform.hpp"
    #include "../Lib/Audio/MyMusic.hpp"
    #include "../Lib/Audio/MyAudio.hpp"
    #include "../Lib/Audio/MySound.hpp"
    #include "../Lib/Shapes/MyRectangle.hpp"

namespace Indie::ECS {
    namespace Systems {
        class Movable3D;
        class Movable2D;
        class Clickable;
        class Object2D;
        class Object3D;
        class Drawable;
        class Model3D;
        class Collider;
    }

    namespace Components {
        class AButton;
        class ACursor;
        class ADestroyable;
        class Model3D;
        class Map3D;
        class Timer;
        class Effect;
    }
};

#endif