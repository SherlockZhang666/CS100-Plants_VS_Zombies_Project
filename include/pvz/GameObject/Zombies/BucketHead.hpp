#include "pvz/GameObject/Zombies/Zombie.hpp"

class BucketHead : public Zombie
{
public:
    BucketHead(int x, int y, pGameWorld world);
    void Update() override;
};