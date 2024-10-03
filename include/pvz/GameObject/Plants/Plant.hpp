#pragma once
#include "pvz/GameWorld/GameWorld.hpp"

class Plant : public GameObject
{
public:
    Plant(ImageID ID, int x, int y, int hp, pGameWorld world);
    void Update() override;
    void OnClick() override;
    int get_HP() const;
    void set_HP(int hp);

private:
    int HP;
};