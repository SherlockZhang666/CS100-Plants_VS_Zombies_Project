#include "pvz/GameObject/GameObject.hpp"

class Background : public GameObject
{
public:
    Background(pGameWorld world);
    void Update() override {}
    void OnClick() override {}
    bool operator==(const GameObject &other);
};