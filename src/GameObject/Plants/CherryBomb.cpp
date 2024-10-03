#include "pvz/GameObject/Plants/CherryBomb.hpp"
#include "pvz/GameObject/Bullets/Explosion.hpp"

void CherryBomb::Update()
{
    plant_duration++;
    if (plant_duration == 15)
    {
        auto explosion = std::make_shared<Explosion>(GetX(), GetY(), get_world());
        get_world()->get_gameObjects().push_back(explosion);
        set_status(GameObject::Status::DEAD);
    }
}