#include "pvz/GameObject/Zombies/Regular.hpp"

Regular::Regular(int x, int y, pGameWorld world)
    : Zombie(IMGID_REGULAR_ZOMBIE, x, y, 200, ANIMID_WALK_ANIM, world) {}
