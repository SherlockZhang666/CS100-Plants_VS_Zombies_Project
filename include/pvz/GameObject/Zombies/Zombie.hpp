#pragma once
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/Plants/Plant.hpp"

class Zombie : public GameObject
{
public:
    enum class ZB_status
    {
        Walk,
        Eat,
        Run,
    };

    Zombie(ImageID ID, int x, int y, int hp, AnimID anim, pGameWorld world);
    void Update() override;
    void OnClick() override;
    void Collide_Plant(Plant *other);

    int get_HP() const;
    void set_HP(int hp);

    ZB_status get_zbstatus() const;
    void set_zbstatus(ZB_status status);

private:
    int HP;
    ZB_status zb_status;
};