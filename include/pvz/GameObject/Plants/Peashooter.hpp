#include "pvz/GameObject/Plants/Plant.hpp"

class Peashooter : public Plant
{
public:
    Peashooter(ImageID ID, int x, int y, int hp, int pea_tick, pGameWorld world);
    void Update() override;

private:
    int pea_tick;
    int pea_cooldown;
};