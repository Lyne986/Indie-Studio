/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

namespace Indie::ECS::Components {

    Timer::Timer(Vector2 pos) :
    Object2D(pos, {1, 1})
    {
        this->finished = false;
        this->started = false;
        this->text = std::make_unique<Lib::MyText>("3:00", 42, WHITE);
    }

    void Timer::init() {}

    void Timer::start(int minutes)
    {
        this->timer = std::chrono::steady_clock::now() + std::chrono::minutes(minutes);
        this->started = true;
    }

    void Timer::pause()
    {
        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
        this->secondsLeft = std::chrono::duration_cast<std::chrono::seconds>(this->timer - currentTime).count();
        this->started = false;
    }

    void Timer::relaunch()
    {
        this->timer = std::chrono::steady_clock::now() + std::chrono::seconds(this->secondsLeft);
        this->started = true;
    }

    void Timer::update()
    {
        if (!started) {
            return;
        }

        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

        if (currentTime >= this->timer) {
            this->finished = true;
        } else {
            int secondsLeft = std::chrono::duration_cast<std::chrono::seconds>(this->timer - currentTime).count();
            int minutes = secondsLeft / 60;
            std::string seconds = std::to_string(secondsLeft % 60);
            size_t size = 2;

            this->text->setContent(std::to_string(minutes) + ":" + std::string(size - std::min(size, seconds.length()), '0') + seconds);
        }
    }

    void Timer::draw() const
    {
        this->text->draw(*this->pos);
    }

    bool Timer::hasFinished() const
    {
        return this->finished;
    }
}
