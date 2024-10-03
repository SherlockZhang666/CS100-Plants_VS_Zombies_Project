#include "pvz/GameObject/Plants/Plant.hpp"

class Repeater : public Plant
{
public:
    Repeater(ImageID ID, int x, int y, int hp, pGameWorld world);
    void Update() override;

private:
    int pea_cooldown;
};