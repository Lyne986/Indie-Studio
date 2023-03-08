/*
** EPITECH PROJECT, 2021
** project
** File description:
** Lib_namespace.hpp
*/

#ifndef __LIB_NAMESPACE_HPP__
    #define __LIB_NAMESPACE_HPP__

    #include "raylib.h"
    #include "rlgl.h"
    #include "extras/easings.h"
    #include <string>
    #include <memory>
    #include <iostream>
    #include <sstream>
    #include <fstream>

namespace Indie::Lib {
    class MyWindow;
    class MyEvent;
    class MyTransform;
    class MyCamera;
    class MyImage;
    class MyTexture;
    class MyModel;
    class MyText;
    class MyMesh;
    class MyEasing;

    namespace Shapes {
        class MyRectangle;
    }

    namespace Audio {
        class MyAudio;
        class MyMusic;
        class MySound;
    }
}

#endif