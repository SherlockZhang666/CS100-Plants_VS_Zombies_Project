#include "pvz/GameObject/Plants/Peashooter.hpp"
#include "pvz/GameObject/Bullets/Pea.hpp"

Peashooter::Peashooter(ImageID ID, int x, int y, int hp, int pea_tick, pGameWorld world)
    : Plant(ID, x, y, hp, world), pea_tick(pea_tick), pea_cooldown(pea_tick) {}

void Peashooter::Update()
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
                pea_cooldown = pea_tick;
                break;
            }
        }
    }
    else
    {
        pea_cooldown--;
    }
}
