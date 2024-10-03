#include "pvz/GameObject/Bullets/Bullet.hpp"

class Pea : public Bullet
{
public:
    Pea(int x, int y, pGameWorld world);
    void Update() override;
};