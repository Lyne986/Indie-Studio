/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "../GlobalArchitecture.hpp"
#include "../ECS/ECS_namespace.hpp"
#include "../ECS/Components/Model3D.hpp"

class Indie::Character : public Indie::ECS::Components::Model3D
{
    private:

    public:
    // Constructor / Destructor

        Character(std::string texture, Vector3 pos, float scale, Vector3 rotation);

    // Usefull functions
        void init();
        void update();
        void draw();

};

#endif /* !CHARACTER_HPP_ */
