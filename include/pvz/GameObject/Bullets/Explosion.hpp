#include "pvz/GameObject/Bullets/Bullet.hpp"

class Explosion : public Bullet
{
public:
    Explosion(int x, int y, pGameWorld world);
    void Update() override;

private:
    int explosionTime = 0;
};