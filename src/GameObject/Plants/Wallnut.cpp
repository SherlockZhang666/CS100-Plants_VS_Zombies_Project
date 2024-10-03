#include "pvz/GameObject/Plants/Wallnut.hpp"

void Wallnut::Update()
{
    Plant::Update();
    if (get_HP() <= 1333)
    {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}
