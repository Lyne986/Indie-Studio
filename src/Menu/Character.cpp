/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Character
*/

#include "Character.hpp"

namespace Indie {
    Character::Character(std::string texture, Vector3 pos, float scale, Vector3 rotation) :
    Model3D("assets/objects/player.iqm", pos, scale, rotation)
    {
        this->model->loadModelAnimations("assets/objects/playerAnimation.iqm", 2);
        this->setTextureFromFile(texture, MATERIAL_MAP_DIFFUSE, 0);
        this->model->updateModelAnimations(0, this->currentAnimFrame);
    }

    void Character::init()
    {

    }

    void Character::update()
    {
        int maxNbFrames = this->model->getNbFrames(0);

        if (maxNbFrames != -1) {
            this->model->updateModelAnimations(0, this->currentAnimFrame);
            this->currentAnimFrame++;
            if (this->currentAnimFrame >= maxNbFrames) {
                this->currentAnimFrame = 0;
            }
        }
    }

    void Character::draw()
    {
        this->Model3D::draw();
    }
}