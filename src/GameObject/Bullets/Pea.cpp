#include "pvz/GameObject/Bullets/Pea.hpp"

Pea::Pea(int x, int y, pGameWorld world) : Bullet(IMGID_PEA, x, y, 28, 28, world, BulletType::Pea) {}

void Pea::Update()
{
    if (get_status() == GameObject::Status::DEAD)
    {
        return;
    }
    MoveTo(GetX() + 8, GetY());
    if (GetX() >= WINDOW_WIDTH)
    {
        set_status(GameObject::Status::DEAD);
    }
}