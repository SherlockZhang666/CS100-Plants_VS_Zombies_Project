#include "pvz/GameObject/Zombies/Zombie.hpp"

Zombie::Zombie(ImageID ID, int x, int y, int hp, AnimID anim, pGameWorld world)
    : GameObject(ID, WINDOW_WIDTH, y, LAYER_ZOMBIES, 20, 80, anim, world, GameObject::Type::Zombie), HP(hp), zb_status(ZB_status::Walk) {}

void Zombie::Update()
{
    if (HP <= 0)
    {
        set_status(GameObject::Status::DEAD);
    }
    if (zb_status == ZB_status::Walk)
    {
        MoveTo(GetX() - 1, GetY());
    }
}

void Zombie::OnClick() {}

void Zombie::Collide_Plant(Plant *other)
{
    if (abs(GetX() - other->GetX()) <= other->GetWidth() / 2 && abs(GetY() - other->GetY()) <= other->GetHeight() / 3)
    {
        if (zb_status == ZB_status::Walk)
        {
            zb_status = ZB_status::Eat;
            PlayAnimation(ANIMID_EAT_ANIM);
            other->set_HP(other->get_HP() - 3);
        }
        else
        {
            if (other->get_HP() <= 0)
            {
                zb_status = ZB_status::Walk;
                PlayAnimation(ANIMID_WALK_ANIM);
            }
            else
            {
                other->set_HP(other->get_HP() - 3);
            }
        }
    }
}

int Zombie::get_HP() const { return HP; }
void Zombie::set_HP(int hp) { HP = hp; }

Zombie::ZB_status Zombie::get_zbstatus() const { return zb_status; }
void Zombie::set_zbstatus(ZB_status zbstatus) { zb_status = zbstatus; }
