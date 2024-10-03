#include "pvz/GameObject/Zombies/BucketHead.hpp"

BucketHead::BucketHead(int x, int y, pGameWorld world)
    : Zombie(IMGID_BUCKET_HEAD_ZOMBIE, x, y, 1300, ANIMID_WALK_ANIM, world) {}

void BucketHead::Update()
{
    Zombie::Update();
    if (get_HP() <= 200)
    {
        ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
}