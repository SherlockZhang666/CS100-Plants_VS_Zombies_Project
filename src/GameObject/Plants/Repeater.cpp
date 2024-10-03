#include "pvz/GameObject/Plants/Repeater.hpp"
#include "pvz/GameObject/Bullets/Pea.hpp"

Repeater::Repeater(ImageID ID, int x, int y, int hp, pGameWorld world) : Plant(ID, x, y, hp, world), pea_cooldown(0) {}

void Repeater::Update()
{
    Plant::Update();
    if (pea_cooldown == 0)
    {
        for (auto &obj : get_world()->get_gameObjects())
        {
            if (obj->get_type() == GameObject::Type::Zombie && abs(GetY() - obj->GetY()) <= GetWidth() && (GetX() < obj->GetX()))
            {
                auto pea = std::make_shared<Pea>(GetX() + 30, GetY() + 20, get_world());
                get_world()->get_gameObjects().push_back(pea);
                pea_cooldown = 30;
                break;
            }
        }
    }
    else if (pea_cooldown == 25)
    {
        auto pea = std::make_shared<Pea>(GetX() + 30, GetY() + 20, get_world());
        get_world()->get_gameObjects().push_back(pea);
        pea_cooldown--;
    }
    else
    {
        pea_cooldown--;
    }
}