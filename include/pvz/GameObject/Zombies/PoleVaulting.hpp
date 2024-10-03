#include "pvz/GameObject/Zombies/Zombie.hpp"

class PoleVaulting : public Zombie
{
public:
    PoleVaulting(int x, int y, pGameWorld world);
    void Update() override;

private:
    int jumptime;
};