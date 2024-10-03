#include "pvz/GameObject/GameObject.hpp"

class Shovel : public GameObject
{
public:
    Shovel(pGameWorld world);
    void Update() override;
    void OnClick() override;
};