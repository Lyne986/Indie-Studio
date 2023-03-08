/*
** EPITECH PROJECT, 2021
** project
** File description:
** Objects_namespace.hpp
*/

#ifndef __OBJECT_NAMESPACES_HPP__
    #define __OBJECT_NAMESPACES_HPP__

    #include "../Lib/Lib_namespace.hpp"
    #include "../Lib/MyCamera.hpp"
    #include "../Lib/MyEasing.hpp"
    #include "../Lib/Shapes/MyRectangle.hpp"
    #include "../ECS/Components/AButton.hpp"
    #include "../ECS/Components/ACursor.hpp"
    #include "../ECS/Components/ADestroyable.hpp"
    #include "../ECS/Components/Model3D.hpp"
    #include "../ECS/Components/Map3D.hpp"
    #include "../ECS/Components/Timer.hpp"
    #include "../ECS/Components/Effect.hpp"
    #include "../ECS/Systems/Movable3D.hpp"
    #include "../GlobalArchitecture.hpp"
    #include "../Utils/FileManager.hpp"
    #include <map>
    #include <ctime>

namespace Indie::Objects {
    namespace Button {
        class Quit;
        class BackSetting;
        class QuitSetting;
        class Title;
        class Fps;
        class GameButton;
        class Back;
        class Setting;
        class Local;
        class Online;
        class Add;
        class Delete;
        class Battle;
        class Change;
        class NewGame;
        class LoadGame;
    };

    namespace Cursor {
        class SoundBarre;
        class fpsBarre;
    };

    namespace Interactables {
        class APlayer;
        class AI;
        class Player;
        class Bomb;
        class DestroyableWall;
        class PowerUp;
    };

    namespace Animations {
        class GameIntro;
        class GameOutro;
    }

    class PlayerInfo;
    class MainCamera;
    class MapManager;
};

#endif
