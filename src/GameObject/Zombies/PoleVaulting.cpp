#include "pvz/GameObject/Zombies/PoleVaulting.hpp"

PoleVaulting::PoleVaulting(int x, int y, pGameWorld world)
    : Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, 340, ANIMID_RUN_ANIM, world), jumptime(0) { set_zbstatus(ZB_status::Run); }

void PoleVaulting::Update()
{
    if (get_HP() <= 0)
    {
        set_status(GameObject::Status::DEAD);
    }
    if (get_zbstatus() == ZB_status::Run)
    {
        MoveTo(GetX() - 40, GetY());
        if (jumptime == 0)
        {
            for (auto &other : get_world()->get_gameObjects())
            {
                if (other->get_type() == GameObject::Type::Plant && (GetX() - other->GetX()) <= GetWidth() / 2 && abs(GetY() - other->GetY()) <= (GetHeight() / 8))
                {
                    jumptime++;
                    PlayAnimation(ANIMID_JUMP_ANIM);
                    break;
                }
            }
        }
        if (jumptime)
        {
            jumptime++;
        }
        else
        {
            MoveTo(GetX() - 2, GetY());
        }
        if (jumptime == 42)
        {
            set_zbstatus(ZB_status::Walk);
            MoveTo(GetX() - 150, GetY());
            PlayAnimation(ANIMID_WALK_ANIM);
        }

        MoveTo(GetX() + 40, GetY());
    }
    else if (get_zbstatus() == ZB_status::Walk)
    {
        MoveTo(GetX() - 1, GetY());
    }
}