#include "pvz/GameObject/Plants/Plant.hpp"

Plant::Plant(ImageID ID, int x, int y, int hp, pGameWorld world) : GameObject(ID, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, world, GameObject::Type::Plant), HP(hp) {}

void Plant::Update()
{
    if (get_HP() <= 0)
    {
        set_status(GameObject::Status::DEAD);
    }
}

void Plant::OnClick()
{
    if (get_world()->get_isShovel())
    {
        set_status(GameObject::Status::DEAD);
        get_world()->set_isShovel(false);
        set_object_plantType(GameObject::PlantType::NONE);
    }
}

int Plant::get_HP() const { return HP; }

void Plant::set_HP(int hp) { HP = hp; }