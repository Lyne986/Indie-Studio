/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MyEvent.cpp
*/

#include "MyEvent.hpp"

namespace Indie::Lib {
    MyEvent::MyEvent() {}

    bool MyEvent::isKey(InputType inputType, int key) const
    {
        if (inputType == DOWN) {
            return IsKeyDown(key);
        }
        if (inputType == PRESSED) {
            return IsKeyPressed(key);
        }
        return IsKeyReleased(key);
    }

    bool MyEvent::isMouseButton(InputType inputType, int button) const
    {
        if (inputType == DOWN) {
            return IsMouseButtonDown(button);
        }
        if (inputType == PRESSED) {
            return IsMouseButtonPressed(button);
        }
        return IsMouseButtonReleased(button);
    }

    bool MyEvent::isGamepadButton(InputType inputType, int controllerId, int button) const
    {
        if (inputType == DOWN) {
            return IsGamepadButtonDown(controllerId, button);
        }
        if (inputType == PRESSED) {
            return IsGamepadButtonPressed(controllerId, button);
        }
        return IsGamepadButtonReleased(controllerId, button);
    }

    Vector2 MyEvent::getGamepadAxisMovement(int controllerId, int axis)
    {
        Vector2 input = {GetGamepadAxisMovement(controllerId, axis), GetGamepadAxisMovement(controllerId, axis + 1)};
        return input;
    }

    Vector2 MyEvent::getMousePosition() const
    {
        return GetMousePosition();
    }

    bool MyEvent::isGamepadAvailable(int controllerId) const
    {
        return IsGamepadAvailable(controllerId);
    }

}