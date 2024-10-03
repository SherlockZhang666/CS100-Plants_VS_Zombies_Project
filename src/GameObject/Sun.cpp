#include "pvz/GameObject/Sun.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Sun::Sun(int x, int y, int droptime, SunSource source, pGameWorld world)
    : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, world, GameObject::Type::Others), droptime(droptime), source(source) { ground_ticks = 0; }

void Sun::Update()
{
    if (droptime > 0)
    {
        if (get_source() == SunSource::Sky)
        {
            MoveTo(GetX(), GetY() - 2);
        }
        else
        {
            MoveTo(GetX() - 1, GetY() + droptime - 8);
        }
        droptime--;
    }
    else
    {
        if (ground_ticks < 300)
        {
            ground_ticks++;
        }
        else if (ground_ticks == 300)
        {
            set_status(GameObject::Status::DEAD);
        }
    }
}

void Sun::OnClick()
{
    get_world()->set_sun(25);
    get_world()->set_sunText(get_world()->get_sun());
    set_status(GameObject::Status::DEAD);
}

SunSource Sun::get_source()
{
    return source;
}