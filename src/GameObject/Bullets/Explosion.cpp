#include "pvz/GameObject/Bullets/Explosion.hpp"

Explosion::Explosion(int x, int y, pGameWorld world)
    : Bullet(IMGID_EXPLOSION, x, y, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, world, BulletType::Explosion) {}

void Explosion::Update()
{
    explosionTime++;
    if (explosionTime >= 3)
    {
        set_status(GameObject::Status::DEAD);
    }
}