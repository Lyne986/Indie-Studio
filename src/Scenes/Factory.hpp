/*
** EPITECH PROJECT, 2021
** project
** File description:
** Factory.hpp
*/

#ifndef __SCENE_FACTORY_HPP__
    #define  __SCENE_FACTORY_HPP__

    #include "SceneManager.hpp"
    #include <memory>

class Indie::Scenes::Factory {
    public:
        template <typename T>
        static std::unique_ptr<T> createScene()
        {
            return (std::make_unique<T>());
        }

};

#endif