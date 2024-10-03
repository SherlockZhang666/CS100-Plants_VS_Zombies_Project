#include "pvz/GameObject/Shovel.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Shovel::Shovel(pGameWorld world) : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, world, GameObject::Type::Others) {}

void Shovel::Update() {}

void Shovel::OnClick()
{
    pGameWorld world = get_world();
    if (world->get_world_plantType() != GameObject::PlantType::NONE)
    {
        return;
    }
    if (world->get_isShovel())
    {
        world->set_isShovel(false);
    }
    else
    {
        world->set_isShovel(true);
    }
}