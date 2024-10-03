#include "pvz/GameObject/Plants/Plant.hpp"

class Sunflower : public Plant
{
public:
    Sunflower(ImageID ID, int x, int y, int hp, pGameWorld world);
    void Update() override;

private:
    int plant_duration;
    int rand_first;
};