#include "pvz/GameObject/PlantingSpot.hpp"
#include "pvz/GameObject/Plants/Sunflower.hpp"
#include "pvz/GameObject/Plants/Peashooter.hpp"
#include "pvz/GameObject/Plants/Wallnut.hpp"
#include "pvz/GameObject/Plants/CherryBomb.hpp"
#include "pvz/GameObject/Plants/Repeater.hpp"

PlantingSpot::PlantingSpot(int x, int y, pGameWorld world)
    : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, world, GameObject::Type::Others) {}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick()
{
    pGameWorld world = get_world();
    if (world->get_world_plantType() == GameObject::PlantType::Sunflower)
    {
        auto sunflower = std::make_shared<Sunflower>(IMGID_SUNFLOWER, GetX(), GetY(), 300, world);
        world->get_gameObjects().push_back(sunflower);
        sunflower->set_object_plantType(GameObject::PlantType::Sunflower);
        world->set_world_plantType(GameObject::PlantType::NONE);
    }
    else if (world->get_world_plantType() == GameObject::PlantType::Peashooter)
    {
        auto peashooter = std::make_shared<Peashooter>(IMGID_PEASHOOTER, GetX(), GetY(), 300, 30, world);
        world->get_gameObjects().push_back(peashooter);
        peashooter->set_object_plantType(GameObject::PlantType::Peashooter);
        world->set_world_plantType(GameObject::PlantType::NONE);
    }
    else if (world->get_world_plantType() == GameObject::PlantType::Wallnut)
    {
        auto wallnut = std::make_shared<Wallnut>(IMGID_WALLNUT, GetX(), GetY(), 4000, world);
        world->get_gameObjects().push_back(wallnut);
        wallnut->set_object_plantType(GameObject::PlantType::Wallnut);
        world->set_world_plantType(GameObject::PlantType::NONE);
    }
    else if (world->get_world_plantType() == GameObject::PlantType::CherryBomb)
    {
        auto cherrybomb = std::make_shared<CherryBomb>(IMGID_CHERRY_BOMB, GetX(), GetY(), 4000, world);
        world->get_gameObjects().push_back(cherrybomb);
        cherrybomb->set_object_plantType(GameObject::PlantType::CherryBomb);
        world->set_world_plantType(GameObject::PlantType::NONE);
    }
    else if (world->get_world_plantType() == GameObject::PlantType::Repeater)
    {
        auto repeater = std::make_shared<Repeater>(IMGID_REPEATER, GetX(), GetY(), 300, world);
        world->get_gameObjects().push_back(repeater);
        repeater->set_object_plantType(GameObject::PlantType::Repeater);
        world->set_world_plantType(GameObject::PlantType::NONE);
    }
}
