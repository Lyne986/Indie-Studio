/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyEvent.hpp
*/

#ifndef __LIB_MY_EVENT_HPP__
    #define __LIB_MY_EVENT_HPP__

    #include "Lib_namespace.hpp"

class Indie::Lib::MyEvent {
    public:
        typedef enum {
            PRESSED,
            DOWN,
            RELEASED
        } InputType;

    // Constructor / Destructor
        MyEvent();

    // Useful functions
        bool isKey(InputType inputType, int key) const;
        bool isMouseButton(InputType inputType, int button) const;
        bool isGamepadButton(InputType inputType, int controllerId, int button) const;
        Vector2 getGamepadAxisMovement(int controllerId, int joystick);
        bool isGamepadAvailable(int controllerId) const;
        Vector2 getMousePosition() const;
};

#endif