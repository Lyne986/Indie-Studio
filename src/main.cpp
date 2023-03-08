/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.cpp
*/

#include "main.hpp"
#include <memory>

int main(int ac, char **av)
{
    Indie::Lib::MyWindow window;
    Indie::Objects::MainCamera camera;
    Indie::Lib::Audio::MyAudio audio(true);
    Indie::SceneManager sceneManager;
    Vector3 pos = {0.0f, 0.0f, 0.0f};

    window.setIcon("assets/icon.png");
    sceneManager.init();
    while (window.isOpen() && sceneManager.getisRunning()) {
        sceneManager.update();
        window.clear();
        sceneManager.drawUnder2D();
        camera.begin3DMode();
        sceneManager.draw3D();
        camera.end3DMode();
        sceneManager.drawOver2D();
        window.display();
    }
    return (0);
}
