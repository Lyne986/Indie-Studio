/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Timer.hpp
*/

#ifndef __ECS_TIMER_HPP__
    #define __ECS_TIMER_HPP__

    #include "../ECS_namespace.hpp"
    #include "../Systems/Object2D.hpp"
    #include "../Systems/Drawable.hpp"
    #include <chrono>

class Indie::ECS::Components::Timer :
public Systems::Drawable,
public Systems::Object2D {
    protected:
        std::unique_ptr<Lib::MyText> text;
        std::chrono::steady_clock::time_point timer;
        int secondsLeft;
        bool finished;
        bool started;

    public:
    // Constructor / Destructor
        Timer(Vector2 pos);

    // Useful functions
        void init();
        void start(int minutes);
        void pause();
        void relaunch();
        void update();
        void draw() const;

    // Getter / Setter
        bool hasFinished() const;
};

#endif
