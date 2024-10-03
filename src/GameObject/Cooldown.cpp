#include "pvz/GameObject/Cooldown.hpp"

Cooldown::Cooldown(int x, int y, int duration, pGameWorld world)
    : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION, world, GameObject::Type::Others) { m_duration = duration; }

void Cooldown::Update()
{
    if (m_duration <= 0)
    {
        set_status(GameObject::Status::DEAD);
        return;
    }
    m_duration--;
}

void Cooldown::OnClick() {}