#include "pvz/GameObject/Bullets/Bullet.hpp"

Bullet::Bullet(ImageID ID, int x, int y, int width, int height, pGameWorld world, BulletType bullettype)
    : GameObject(ID, x, y, LAYER_PROJECTILES, width, height, ANIMID_NO_ANIMATION, world, GameObject::Type::Bullet), bullet_type(bullettype) {}

void Bullet::Update() {}

void Bullet::OnClick() {}

Bullet::BulletType Bullet::get_bullet_type() const
{
    return bullet_type;
}

void Bullet::Collide_Zombie(Zombie *other)
{
    if (get_status() == GameObject::Status::DEAD)
        return;
    if (bullet_type == BulletType::Pea)
    {
        if ((abs(GetX() - other->GetX()) <= GetWidth()) && abs(GetY() - other->GetY()) <= (other->GetHeight() / 3))
        {
            other->set_HP(other->get_HP() - 20);
            set_status(GameObject::Status::DEAD);
        }
    }
    else
    {
        if (abs(GetX() - other->GetX()) <= GetWidth() / 2 && abs(GetY() - other->GetY()) <= GetHeight() / 2)
        {
            other->set_status(GameObject::Status::DEAD);
        }
    }
}