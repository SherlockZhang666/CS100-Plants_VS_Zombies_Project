#include "pvz/GameObject/Plants/Sunflower.hpp"
#include "pvz/GameObject/Sun.hpp"

Sunflower::Sunflower(ImageID ID, int x, int y, int hp, pGameWorld world) : Plant(ID, x, y, hp, world), plant_duration(0), rand_first(randInt(30, 600)) {}

void Sunflower::Update()
{
    Plant::Update();
    if (plant_duration == rand_first || (plant_duration - rand_first) % 600 == 0)
    {
        auto sun = std::make_shared<Sun>(GetX(), GetY(), 12, SunSource::Sunflower, get_world());
        get_world()->get_gameObjects().push_back(sun);
    }
    plant_duration++;
}
