#include "pvz/GameObject/Seed.hpp"
#include "pvz/GameObject/Cooldown.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

Seed::Seed(ImageID ID, int x, int y, int price, int cool_duration, pGameWorld world)
    : GameObject(ID, x, y, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, world, GameObject::Type::Others), price(price), cool_duration(cool_duration) { cool_tick = 0; }

void Seed::Update()
{
    if (cool_tick == 0)
    {
        return;
    }
    else
    {
        cool_tick--;
    }
}

void Seed::OnClick()
{
    if (get_world()->get_world_plantType() != GameObject::PlantType::NONE || get_world()->get_isShovel())
    {
        return;
    }
    if (get_cooltick() != 0)
    {
        return;
    }
    pGameWorld world = get_world();
    if (world->get_sun() >= price)
    {
        world->set_sun(-price);
        if (GetX() == 130)
            world->set_world_plantType(GameObject::PlantType::Sunflower);
        else if (GetX() == 190)
            world->set_world_plantType(GameObject::PlantType::Peashooter);
        else if (GetX() == 250)
            world->set_world_plantType(GameObject::PlantType::Wallnut);
        else if (GetX() == 310)
            world->set_world_plantType(GameObject::PlantType::CherryBomb);
        else if (GetX() == 370)
            world->set_world_plantType(GameObject::PlantType::Repeater);
        auto cooldown_mask = std::make_shared<Cooldown>(GetX(), GetY(), cool_duration, world);
        world->get_gameObjects().push_back(cooldown_mask);
        set_cooltick(cool_duration);
    }
}

int Seed::get_cooltick() const { return cool_tick; }
void Seed::set_cooltick(int tick) { cool_tick = tick; }