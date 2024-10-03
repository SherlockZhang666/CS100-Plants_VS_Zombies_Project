#include "pvz/GameObject/GameObject.hpp"

class PlantingSpot : public GameObject
{
public:
    PlantingSpot(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;
};